#define USE_WINDOWS_DLL_SEMANTICS
#define STB_IMAGE_IMPLEMENTATION

#include <chrono>
#include <iostream>
#include <list>
#include <map>
#include <thread>

#include <conio.h>

#include <windows.h>

#include "AntiCrack.h"

#include "GameData.h"
#include "LuaBridge.h"
#include "MapObject.h"
#include "MemoryReader.h"
#include "RenderEngine.h"
#include "Structs.h"
#include "Utils.h"
#include "imgui.h"

std::map<std::string, lua_State *> g_lua_env;

void MainLoop(RenderEngine &overlay, MemoryReader &reader);

std::wstring getComputerName() {
  wchar_t buffer[MAX_COMPUTERNAME_LENGTH + 1] = {0};
  DWORD cchBufferSize = sizeof(buffer) / sizeof(buffer[0]);
  if (!GetComputerNameW(buffer, &cchBufferSize))
    throw std::runtime_error("GetComputerName() failed.");
  return std::wstring(&buffer[0]);
}

//#define DLL

#ifdef DLL

DWORD WINAPI DllThreadEntry(LPVOID pParam);
HANDLE hThread;
DWORD threadID;

BOOL WINAPI DllMain(HINSTANCE hinstDLL, // handle to DLL module
                    DWORD fdwReason,    // reason for calling function
                    LPVOID lpReserved)  // reserved
{
  // Perform actions based on the reason for calling.
  switch (fdwReason) {
  case DLL_PROCESS_ATTACH:
    // Initialize once for each new process.
    // Return FALSE to fail DLL load.

    hThread = CreateThread(NULL, 0, DllThreadEntry, NULL, 0, &threadID);

    MessageBox(NULL, TEXT("OK"), TEXT(""), NULL);

    break;
  case DLL_THREAD_ATTACH:
    // Do thread-specific initialization.
    break;

  case DLL_THREAD_DETACH:
    // Do thread-specific cleanup.
    break;

  case DLL_PROCESS_DETACH:
    // Perform any necessary cleanup.
    break;
  }
  return TRUE; // Successful DLL_PROCESS_ATTACH.
}

DWORD WINAPI DllThreadEntry(LPVOID pParam) {
  printf("\r	Init LUA environment ......\n");

  RenderEngine overlay = RenderEngine();
  MemoryReader reader = MemoryReader();

  try {
    overlay.Init();
    MapObject::Get(MapType::SUMMONERS_RIFT)
        ->Load("data/"
               "height_map_sru.bin");
    MapObject::Get(MapType::HOWLING_ABYSS)
        ->Load("data/height_map_ha.bin");
    std::string dataPath("data");
    GameData::Load(dataPath);

    MainLoop(overlay, reader);
  } catch (std::runtime_error exception) {
    std::cout << exception.what() << std::endl;
  }
}

#else

int main(int argc, char **argv) {
  printf("\r	Init LUA environment ......\n");

  RenderEngine overlay = RenderEngine();
  MemoryReader reader = MemoryReader();

  try {
    overlay.Init();
    MapObject::Get(MapType::SUMMONERS_RIFT)->Load("data/height_map_sru.bin");
    MapObject::Get(MapType::HOWLING_ABYSS)->Load("data/height_map_ha.bin");
    std::string dataPath("data");
    GameData::Load(dataPath);

    MainLoop(overlay, reader);
  } catch (std::runtime_error exception) {
    std::cout << exception.what() << std::endl;
  }
  return 0;
}

#endif

void MainLoop(RenderEngine &overlay, MemoryReader &reader) {
  MemSnapshot memSnapshot;
  bool isNeedRehook = true;
  bool firstIter = true;

  printf("\r	Load LUA Script complete ...... \n"
         "\r	Waiting the process starting ...... \n");
  while (true) {
    bool isLeagueWindowActive = reader.IsLeagueWindowActive();
    if (overlay.IsVisible()) {
      if (Input::WasKeyPressed(HKey::F8)) {
        overlay.ToggleTransparent();
      }
      if (!isLeagueWindowActive) {
        overlay.Hide();
      }
    } else if (isLeagueWindowActive) {
      overlay.Show();
    }
    try {
      overlay.StartFrame();

      // Process Exception
      if (isNeedRehook) {
        reader.HookToProcess();
        isNeedRehook = false;
        firstIter = true;
        memSnapshot = MemSnapshot();
        printf("        Module injected ......\n");
      } else {
        // Check is Hooked Process
        if (!reader.IsHookedToProcess()) {
          isNeedRehook = true;
          printf("\r	Process is closed ...... \n"
                 "\r	Waiting the process starting ......\n");
        }
        reader.MakeSnapshot(memSnapshot);

        if (memSnapshot.gameTime > 2.f) {
          if (firstIter) {
            overlay.GameStart(memSnapshot);
            firstIter = false;
          }

          overlay.Update(memSnapshot);
        }
      }

      overlay.RenderFrame();
    } catch (WinApiException exception) {
      isNeedRehook = true;
    } catch (std::runtime_error exception) {
      printf("\r	Error? %s \n", exception.what());
      break;
    }
  }
}
