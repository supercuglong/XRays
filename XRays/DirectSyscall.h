#pragma once
#include <windows.h>

typedef enum _MEMORY_INFORMATION_CLASS {
  MemoryBasicInformation
} MEMORY_INFORMATION_CLASS;

extern "C" NTSTATUS
NtQueryVirtualMemory(HANDLE ProcessHandle, PVOID BaseAddress,
                     MEMORY_INFORMATION_CLASS MemoryInformationClass,
                     PVOID MemoryInformation, SIZE_T MemoryInformationLength,
                     PSIZE_T ReturnLength);

extern "C" NTSTATUS NtReadVirtualMemory(IN HANDLE ProcessHandle,
                                        IN PVOID BaseAddress, OUT PVOID Buffer,
                                        IN ULONG BufferSize,
                                        OUT PULONG NumberOfBytesRead OPTIONAL);

extern "C" NTSTATUS
NtWriteVirtualMemory(IN HANDLE ProcessHandle, OUT PVOID BaseAddress,
                     IN PVOID Buffer, IN ULONG BufferSize,
                     OUT PULONG NumberOfBytesWritten OPTIONAL);
