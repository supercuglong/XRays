#include "LuaScript.h"

#include "LuaExport.inc"



extern std::map<std::string, lua_State *> g_lua_env;

static std::string GetLuaErrorString(lua_State *L, int status) {

  return lua_tostring(L, -1);
}

static void dumpstack(lua_State *L) {

  int top = lua_gettop(L);
  for (int i = 1; i <= top; i++) {
    printf("%d\t%s\t", i, luaL_typename(L, i));
    switch (lua_type(L, i)) {
    case LUA_TNUMBER:
      printf("%g\n", lua_tonumber(L, i));
      break;
    case LUA_TSTRING:
      printf("%s\n", lua_tostring(L, i));
      break;
    case LUA_TBOOLEAN:
      printf("%s\n", (lua_toboolean(L, i) ? "true" : "false"));
      break;
    case LUA_TNIL:
      printf("%s\n", "nil");
      break;
    default:
      printf("%p\n", lua_topointer(L, i));
      break;
    }
  }
}

bool Script::LoadInfo() {

  auto ref = luabridge::getGlobal(L, "script");
  if (ref.isString())
    name = ref.cast<std::string>();
  ref = luabridge::getGlobal(L, "description");
  if (ref.isString())
    description = ref.cast<std::string>();
  ref = luabridge::getGlobal(L, "author");
  if (ref.isString())
    author = ref.cast<std::string>();
  ref = luabridge::getGlobal(L, "targetChampion");
  if (ref.isString())
    targetChampion = ref.cast<std::string>();

  return true;
}

bool Script::LoadFunc(const char *func_name) {

  auto ref = luabridge::getGlobal(L, func_name);
  if (ref.isNil()) {
    loadError = "Not found => ";
    loadError += func_name;
    return false;
  }

  return true;
}

void Script::Load() {
  g_lua_env[full_path] = luaL_newstate();
  L = g_lua_env[full_path];
  luaL_openlibs(L);
  ExportLuaStructure(L);

  int status = 0;
  printf("	Loading addon %s\n", full_path.c_str());
  status = luaL_loadfile(L, full_path.c_str());
  if (status) {
    loadError = lua_tostring(L, -1);
    fprintf(stderr, "luaL_loadfile: %s\n", lua_tostring(L, -1));
  }
  status = lua_pcall(L, 0, 0, 0);
  if (status) {
    loadError = lua_tostring(L, -1);
    fprintf(stderr, "lua_pcall: %s\n", lua_tostring(L, -1));
  } else {
    if (LoadInfo() && LoadFunc("XRaysUpdate") &&
        LoadFunc("XRaysDrawSettings") && LoadFunc("XRaysLoadCfg") &&
        LoadFunc("XRaysSaveCfg")) {
      loadError.clear();
    }
  }
}

void Script::ExecUpdate(const LuaGameInterface &state,
                        const LuaGUIInterface &ui) {

  auto updateFunc = luabridge::getGlobal(L, "XRaysUpdate");
  try {
    std::chrono::high_resolution_clock::time_point beforeUpdate =
        std::chrono::high_resolution_clock::now();

    updateFunc(state, ui);
    updateTimeMs = std::chrono::high_resolution_clock::now() - beforeUpdate;

    std::cout << "duration milliseconds : " << updateTimeMs.count()
              << std::endl;

  } catch (luabridge::LuaException const &e) {
    execError = e.what();
    std::cout << execError << std::endl;
  }
}

void Script::ExecDrawSettings(const LuaGameInterface &state,
                              const LuaGUIInterface &ui) {

  auto drawSettingsFunc = luabridge::getGlobal(L, "XRaysDrawSettings");
  try {
    drawSettingsFunc(state, ui);
  } catch (luabridge::LuaException const &e) {
    execError = e.what();
    std::cout << execError << std::endl;
  }
}

void Script::ExecLoadCfg() {

  auto loadCfgFunc = luabridge::getGlobal(L, "XRaysLoadCfg");
  try {
    loadCfgFunc(*ConfigSet::Get());
  } catch (luabridge::LuaException const &e) {
    execError = e.what();
    std::cout << execError << std::endl;
  }
}

void Script::ExecSaveCfg() {

  auto saveCfgFunc = luabridge::getGlobal(L, "XRaysSaveCfg");

  try {
    saveCfgFunc(*ConfigSet::Get());
  } catch (luabridge::LuaException const &e) {
    execError = e.what();
    std::cout << execError << std::endl;
  }
}

Script::Script() {}

Script::~Script() {
  lua_close(L);
  g_lua_env.erase(full_path);
}
