#pragma once
#include <Windows.h>
#include <iostream>
#include <stdio.h>

#ifdef _WIN64
#define XIP Rip
#else
#define XIP Eip
#endif

class VEHHook {
public:
  static bool Hook(uintptr_t og_fun, uintptr_t hk_fun);
  static bool Unhook();

private:
  static uintptr_t og_fun;
  static uintptr_t hk_fun;
  static PVOID VEH_Handle;
  static DWORD oldProtection;

  static bool AreInSamePage(const uint8_t *Addr1, const uint8_t *Addr2);
  static LONG WINAPI ExceptionHandler(EXCEPTION_POINTERS *pExceptionInfo);
};

uintptr_t VEHHook::og_fun = 0;
uintptr_t VEHHook::hk_fun = 0;
PVOID VEHHook::VEH_Handle = nullptr;
DWORD VEHHook::oldProtection = 0;

bool VEHHook::Hook(uintptr_t original_fun, uintptr_t hooked_fun) {
  VEHHook::og_fun = original_fun;
  VEHHook::hk_fun = hooked_fun;

  // We cannot hook two functions in the same page, because we will cause an
  // infinite callback
  if (AreInSamePage((const uint8_t *)og_fun, (const uint8_t *)hk_fun))
    return false;

  // Register the Custom Exception Handler
  VEH_Handle = AddVectoredExceptionHandler(
      true, (PVECTORED_EXCEPTION_HANDLER)ExceptionHandler);

  // Toggle PAGE_GUARD flag on the page
  if (VEH_Handle &&
      VirtualProtect((LPVOID)og_fun, 1, PAGE_EXECUTE_READ | PAGE_GUARD,
                     &oldProtection))
    return true;

  return false;
}

bool VEHHook::Unhook() {
  DWORD old;
  if (VEH_Handle && // Make sure we have a valid Handle to the registered VEH
      VirtualProtect((LPVOID)og_fun, 1, oldProtection,
                     &old) &&                     // Restore old Flags
      RemoveVectoredExceptionHandler(VEH_Handle)) // Remove the VEH
    return true;

  return false;
}

LONG WINAPI VEHHook::ExceptionHandler(EXCEPTION_POINTERS *pExceptionInfo) {
  if (pExceptionInfo->ExceptionRecord->ExceptionCode ==
      STATUS_GUARD_PAGE_VIOLATION) // We will catch PAGE_GUARD Violation
  {
    if (pExceptionInfo->ContextRecord->XIP ==
        (uintptr_t)
            og_fun) // Make sure we are at the address we want within the page
    {
      pExceptionInfo->ContextRecord->XIP =
          (uintptr_t)hk_fun; // Modify EIP/RIP to where we want to jump to
                             // instead of the original function
    }

    pExceptionInfo->ContextRecord->EFlags |=
        0x100; // Will trigger an STATUS_SINGLE_STEP exception right after the
               // next instruction get executed. In short, we come right back
               // into this exception handler 1 instruction later
    return EXCEPTION_CONTINUE_EXECUTION; // Continue to next instruction
  }

  if (pExceptionInfo->ExceptionRecord->ExceptionCode ==
      STATUS_SINGLE_STEP) // We will also catch STATUS_SINGLE_STEP, meaning we
                          // just had a PAGE_GUARD violation
  {
    DWORD dwOld;
    VirtualProtect((LPVOID)og_fun, 1, PAGE_EXECUTE_READ | PAGE_GUARD,
                   &dwOld); // Reapply the PAGE_GUARD flag because everytime it
                            // is triggered, it get removes

    return EXCEPTION_CONTINUE_EXECUTION; // Continue the next instruction
  }

  return EXCEPTION_CONTINUE_SEARCH; // Keep going down the exception handling
                                    // list to find the right handler IF it is
                                    // not PAGE_GUARD nor SINGLE_STEP
}

bool VEHHook::AreInSamePage(const uint8_t *Addr1, const uint8_t *Addr2) {
  MEMORY_BASIC_INFORMATION mbi1;
  if (!VirtualQuery(Addr1, &mbi1,
                    sizeof(mbi1))) // Get Page information for Addr1
    return true;

  MEMORY_BASIC_INFORMATION mbi2;
  if (!VirtualQuery(Addr2, &mbi2,
                    sizeof(mbi2))) // Get Page information for Addr1
    return true;

  if (mbi1.BaseAddress ==
      mbi2.BaseAddress) // See if the two pages start at the same Base Address
    return true;        // Both addresses are in the same page, abort hooking!

  return false;
}