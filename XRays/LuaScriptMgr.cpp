#include "LuaScriptMgr.h"

void ScriptManager::LoadAll(std::string scriptsLocation,
                            std::string &champion) {

  try {
    activeScripts.clear();
    inactiveScripts.clear();

    WIN32_FIND_DATAA findData;
    HANDLE hFind;

    hFind = FindFirstFileA((scriptsLocation + "\\*.lua").c_str(), &findData);
    do {
      if (hFind != INVALID_HANDLE_VALUE) {
        std::string fileName = findData.cFileName;

        std::shared_ptr<Script> script;
        auto it = allScripts.find(fileName);
        if (it != allScripts.end())
          script = it->second;
        else {
          script = std::shared_ptr<Script>(new Script());
          allScripts[fileName] = script;
        }

        std::string full_path;
        full_path += scriptsLocation;
        full_path.push_back('\\');
        full_path += fileName;

        script->full_path = full_path;

        script->Load();

        if (script->loadError.empty())
          ReloadScriptConfigs(script);
        if (script->targetChampion.size() > 0 &&
            script->targetChampion.compare(champion) != 0)
          inactiveScripts.push_back(script);
        else
          activeScripts.push_back(script);
      }
    } while (FindNextFileA(hFind, &findData));
  } catch (...) {
    std::cerr << "Loading LUA Exception \n" << std::endl;
  }
}

void ScriptManager::ReloadScript(std::shared_ptr<Script> &script) {
  script->Load();
  if (script->loadError.empty())
    ReloadScriptConfigs(script);
}

void ScriptManager::SaveAllScriptsConfigs() {
  for (auto it = activeScripts.begin(); it != activeScripts.end(); ++it) {
    SaveScriptConfigs(*it);
  }
}

void ScriptManager::SaveScriptConfigs(std::shared_ptr<Script> &script) {
  ConfigSet &configs = *(ConfigSet::Get());

  configs.SetPrefixKey(script->name);
  configs.SetBool("enabled", script->enabled);
  script->ExecSaveCfg();
  configs.SetPrefixKey("");
}

void ScriptManager::ReloadScriptConfigs(std::shared_ptr<Script> &script) {
  ConfigSet &configs = *(ConfigSet::Get());

  configs.SetPrefixKey(script->name);
  script->enabled = configs.GetBool("enabled", true);
  script->ExecLoadCfg();
  configs.SetPrefixKey("");
}
