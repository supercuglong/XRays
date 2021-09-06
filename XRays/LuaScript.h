#pragma once

#include <chrono>
#include <cstdio>
#include <map>

#include "LuaBridge.h"
#include "ConfigSet.h"
#include "LuaGUIInterface.h"
#include "LuaGameInterface.h"

/// Represents a LUA game play script
class Script {
public:
  Script();
  ~Script();

public:
  void Load();
  void ExecUpdate(const LuaGameInterface &state, const LuaGUIInterface &ui);
  void ExecDrawSettings(const LuaGameInterface &state, const LuaGUIInterface &ui);
  void ExecLoadCfg();
  void ExecSaveCfg();

private:
  bool LoadFunc(const char *);
  bool LoadInfo();

public:
  std::string full_path;
  std::string description;
  std::string author;
  std::string name;
  std::string targetChampion;

  std::string loadError;
  std::string execError;

  std::chrono::duration<float, std::milli> updateTimeMs;

  bool enabled;

  lua_State *L;
};