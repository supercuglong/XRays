#include "GameData.h"

#include "RenderEngine.h"

UnitInfo *GameData::UnknownUnit = new UnitInfo();
SpellInfo *GameData::UnknownSpell = new SpellInfo();
ItemInfo *GameData::UnknownItem = new ItemInfo();
std::map<std::string, UnitInfo *> GameData::Units = {};
std::map<std::string, SpellInfo *> GameData::Spells = {};
std::map<std::string, Texture2D *> GameData::Images = {};
std::map<int, ItemInfo *> GameData::Items = {};

void GameData::Load(std::string &dataFolder) {
  std::string unitData = dataFolder + "/UnitData.json";
  std::string spellData = dataFolder + "/SpellData.json";
  std::string spellDataCustom = dataFolder + "/SpellDataCustom.json";
  std::string itemData = dataFolder + "/ItemData.json";
  std::string spellIcons = dataFolder + "/icons_spells";
  std::string champIcons = dataFolder + "/icons_champs";
  std::string extraIcons = dataFolder + "/icons_extra";

  LoadItemData(itemData);

  LoadUnitData(unitData);

  LoadSpellData(spellData);
  LoadSpellData(spellDataCustom);

  LoadIcons(spellIcons);
  LoadIcons(champIcons);
  LoadIcons(extraIcons);

  printf("\r	Load Metadata complete ...... \n");
}

UnitInfo *GameData::GetUnitInfoByName(std::string &name) {
  auto it = Units.find(name);
  if (it != Units.end())
    return it->second;
  return UnknownUnit;
}

SpellInfo *GameData::GetSpellInfoByName(std::string &name) {
  auto it = Spells.find(name);
  if (it != Spells.end())
    return it->second;
  return UnknownSpell;
}

ItemInfo *GameData::GetItemInfoById(int id) {
  auto it = Items.find(id);
  if (it != Items.end())
    return it->second;
  return UnknownItem;
}

nlohmann::json parse_json_file(std::string &path) {
  std::ifstream inputData;
  inputData.open(path);

  if (!inputData.is_open())
    throw std::runtime_error("Can't open unit data file");

  nlohmann::json j;

  try {
    j = nlohmann::json::parse(inputData);

  } catch (const std::exception &) {
    throw std::runtime_error("Failed to parse JSON file");
  }

  return j;
}

void GameData::LoadUnitData(std::string &path) {
  auto jv = parse_json_file(path);

  for (auto &unitEle : jv) {
    UnitInfo *unit = new UnitInfo();
    unit->acquisitionRange = unitEle["acquisitionRange"];
    unit->attackSpeedRatio = unitEle["attackSpeedRatio"];
    unit->baseAttackRange = unitEle["attackRange"];
    unit->baseAttackSpeed = unitEle["attackSpeed"];
    unit->baseMovementSpeed = unitEle["baseMoveSpeed"];
    unit->basicAttackMissileSpeed = unitEle["basicAtkMissileSpeed"];
    unit->basicAttackWindup = unitEle["basicAtkWindup"];
    unit->gameplayRadius = unitEle["gameplayRadius"];
    unit->healthBarHeight = unitEle["healthBarHeight"];
    unit->name = unitEle["name"];
    unit->pathRadius = unitEle["pathingRadius"];
    unit->selectionRadius = unitEle["selectionRadius"];

    auto &tags = unitEle["tags"];
    for (auto &tag : tags)
      unit->SetTag(tag.get<std::string>().c_str());

    Units[unit->name] = unit;
  }
}

void GameData::LoadSpellData(std::string &path) {
  auto jv = parse_json_file(path);

  for (auto &spellObj : jv) {
    SpellInfo *info = new SpellInfo();
    info->flags = (SpellFlags)spellObj["flags"];
    info->delay = spellObj["delay"];
    info->height = spellObj["height"];
    info->icon = spellObj["icon"];
    info->name = spellObj["name"];
    info->width = spellObj["width"];
    info->castRange = spellObj["castRange"];
    info->castRadius = spellObj["castRadius"];
    info->speed = spellObj["speed"];
    info->travelTime = spellObj["travelTime"];
    info->flags =
        (SpellFlags)(info->flags | (spellObj["projectDestination"].get<bool>()
                                        ? ProjectedDestination
                                        : 0));

    Spells[info->name] = info;
  }
}

void GameData::LoadIcons(std::string &path) {
  std::string folder(path);
  WIN32_FIND_DATAA findData;
  HANDLE hFind;

  int nrFiles = std::distance(std::filesystem::directory_iterator(path),
                              std::filesystem::directory_iterator());
  int nrFile = 0;
  hFind = FindFirstFileA((folder + "\\*.png").c_str(), &findData);
  do {
    if (hFind != INVALID_HANDLE_VALUE) {
      if (nrFile % 100 == 0)
        printf("\r	Library loading %d/%d      ", nrFile, nrFiles);

      std::string filePath = folder + "/" + findData.cFileName;
      Texture2D *image =
          Texture2D::LoadFromFile(RenderEngine::GetDxDevice(), filePath);
      if (image == nullptr)
        printf("	Failed to load: %s\n", filePath.c_str());
      else {
        std::string fileName(findData.cFileName);
        fileName.erase(fileName.find(".png"), 4);
        Images[Character::ToLower(fileName)] = image;
      }
    }
    nrFile++;
  } while (FindNextFileA(hFind, &findData));
}

void GameData::LoadItemData(std::string &path) {
  auto jv = parse_json_file(path);
  for (auto &item : jv) {
    ItemInfo *info = new ItemInfo();

    info->movementSpeed = item["movementSpeed"];
    info->health = item["health"];
    info->crit = item["crit"];
    info->abilityPower = item["abilityPower"];
    info->mana = item["mana"];
    info->armour = item["armour"];
    info->magicResist = item["magicResist"];
    info->physicalDamage = item["physicalDamage"];
    info->attackSpeed = item["attackSpeed"];
    info->lifeSteal = item["lifeSteal"];
    info->hpRegen = item["hpRegen"];
    info->movementSpeedPercent = item["movementSpeedPercent"];
    info->cost = item["cost"];
    info->id = item["id"];

    Items[info->id] = info;
  }
}
