#pragma once
#include <filesystem>
#include <fstream>
#include <map>
#include <string>

#include "ItemInfo.h"
#include "SpellInfo.h"
#include "Texture2D.h"
#include "UnitInfo.h"
#include "Utils.h"
#include "json.hpp"

/// Data that cant be read from memory or it is too inefficient to do so can be
/// accessed with this class.
class GameData {
public:
  static void Load(std::string &dataFolder);
  static UnitInfo *GetUnitInfoByName(std::string &name);
  static SpellInfo *GetSpellInfoByName(std::string &name);
  static ItemInfo *GetItemInfoById(int id);

private:
  static void LoadUnitData(std::string &path);
  static void LoadSpellData(std::string &path);
  static void LoadIcons(std::string &path);
  static void LoadItemData(std::string &path);

public:
  static UnitInfo *UnknownUnit;
  static SpellInfo *UnknownSpell;
  static ItemInfo *UnknownItem;

  static std::map<std::string, UnitInfo *> Units;
  static std::map<std::string, SpellInfo *> Spells;
  static std::map<std::string, Texture2D *> Images;
  static std::map<int, ItemInfo *> Items;
};