#pragma once

#include <chrono>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <string>

#include <Windows.h>
#include <d3d11_2.h>
#include <dcomp.h>
#include <dinput.h>
#include <dxgi1_3.h>

#include "backends/imgui_impl_dx11.h"
#include "backends/imgui_impl_win32.h"

#include "imgui.h"

#include "ConfigSet.h"

#include "LuaGUIInterface.h"
#include "LuaGameInterface.h"

#include "LuaScriptMgr.h"

/// Manages the overlay of the cheat. Also manages the executing scripts.
class RenderEngine {
public:
  RenderEngine();

  void Init();
  void GameStart(MemSnapshot &memSnapshot);

  void StartFrame();
  void Update(MemSnapshot &memSnapshot);
  void RenderFrame();

  bool IsVisible();
  void Hide();
  void Show();
  void ToggleTransparent();

  static ID3D11Device *GetDxDevice();

private:
  void DrawUI(LuaGameInterface &state, MemSnapshot &memSnapshot);
  void ExecScripts(LuaGameInterface &state, MemSnapshot &memSnapshot);

  void DrawOverlayWindows(LuaGameInterface &state);
  void DrawScriptSettings(LuaGameInterface &state, MemSnapshot &memSnapshot);

  void DrawScriptError(std::shared_ptr<Script> &script);
  void DrawScriptCommonSettings(std::shared_ptr<Script> &script, int id);

  static bool CreateDeviceD3D(HWND hWnd);
  static void CleanupDeviceD3D();
  static void CreateRenderTarget();
  static void CleanupRenderTarget();

  static LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam,
                                LPARAM lParam);

private:
  HWND hWindow;
  bool isWindowVisible = true;
  bool isOvVisible = true;

  // DirectX stuff
  static ID3D11Device *dxDevice;
  static ID3D11DeviceContext *dxDeviceContext;
  static IDXGISwapChain1 *dxSwapChain;
  static ID3D11RenderTargetView *dxRenderTarget;

  ConfigSet &configs;

  ScriptManager scriptManager;
  LuaGUIInterface imguiInterface;

  // Some simple benchmarks
  float renderTimeMs;
  float processTimeMs;

  // Some IMGUI flags
  bool drawSettings = true;
  bool drawBenchmarks = false;
};
