#pragma once

#define COLOR_API(COLOR)                                                       \
  static ImVec4 _##COLOR() { return COLOR; }

#define GENLUAFUNC(NAME, TYPE)                                                 \
  static int NAME##_##TYPE() { return static_cast<int>(TYPE::NAME); }


namespace Colors {
COLOR_API(BLACK);
COLOR_API(WHITE);
COLOR_API(RED);
COLOR_API(DARK_RED);
COLOR_API(GREEN);
COLOR_API(DARK_GREEN);
COLOR_API(YELLOW);
COLOR_API(DARK_YELLOW);
COLOR_API(CYAN);
COLOR_API(PURPLE);
COLOR_API(GRAY);
COLOR_API(ORANGE);
COLOR_API(BLUE);
COLOR_API(BROWN);
}

GENLUAFUNC(SUMMONERS_RIFT, MapType)
GENLUAFUNC(HOWLING_ABYSS, MapType)

GENLUAFUNC(AffectAllyChampion, SpellFlags)
GENLUAFUNC(AffectEnemyChampion, SpellFlags)
GENLUAFUNC(AffectAllyLaneMinion, SpellFlags)
GENLUAFUNC(AffectEnemyLaneMinion, SpellFlags)
GENLUAFUNC(AffectAllyWard, SpellFlags)
GENLUAFUNC(AffectEnemyWard, SpellFlags)
GENLUAFUNC(AffectAllyTurret, SpellFlags)
GENLUAFUNC(AffectEnemyTurret, SpellFlags)
GENLUAFUNC(AffectAllyInhibs, SpellFlags)
GENLUAFUNC(AffectEnemyInhibs, SpellFlags)
GENLUAFUNC(AffectAllyNonLaneMinion, SpellFlags)
GENLUAFUNC(AffectJungleMonster, SpellFlags)
GENLUAFUNC(AffectEnemyNonLaneMinion, SpellFlags)
GENLUAFUNC(AffectAlwaysSelf, SpellFlags)
GENLUAFUNC(AffectNeverSelf, SpellFlags)
GENLUAFUNC(ProjectedDestination, SpellFlags)
GENLUAFUNC(AffectAllyMob, SpellFlags)
GENLUAFUNC(AffectEnemyMob, SpellFlags)
GENLUAFUNC(AffectAllyGeneric, SpellFlags)
GENLUAFUNC(AffectEnemyGeneric, SpellFlags)

GENLUAFUNC(Unit_, UnitTag)
GENLUAFUNC(Unit_Champion, UnitTag)
GENLUAFUNC(Unit_Champion_Clone, UnitTag)
GENLUAFUNC(Unit_IsolationNonImpacting, UnitTag)
GENLUAFUNC(Unit_KingPoro, UnitTag)
GENLUAFUNC(Unit_Minion, UnitTag)
GENLUAFUNC(Unit_Minion_Lane, UnitTag)
GENLUAFUNC(Unit_Minion_Lane_Melee, UnitTag)
GENLUAFUNC(Unit_Minion_Lane_Ranged, UnitTag)
GENLUAFUNC(Unit_Minion_Lane_Siege, UnitTag)
GENLUAFUNC(Unit_Minion_Lane_Super, UnitTag)
GENLUAFUNC(Unit_Minion_Summon, UnitTag)
GENLUAFUNC(Unit_Minion_SummonName_game_character_displayname_ZyraSeed, UnitTag)
GENLUAFUNC(Unit_Minion_Summon_Large, UnitTag)
GENLUAFUNC(Unit_Monster, UnitTag)
GENLUAFUNC(Unit_Monster_Blue, UnitTag)
GENLUAFUNC(Unit_Monster_Buff, UnitTag)
GENLUAFUNC(Unit_Monster_Camp, UnitTag)
GENLUAFUNC(Unit_Monster_Crab, UnitTag)
GENLUAFUNC(Unit_Monster_Dragon, UnitTag)
GENLUAFUNC(Unit_Monster_Epic, UnitTag)
GENLUAFUNC(Unit_Monster_Gromp, UnitTag)
GENLUAFUNC(Unit_Monster_Krug, UnitTag)
GENLUAFUNC(Unit_Monster_Large, UnitTag)
GENLUAFUNC(Unit_Monster_Medium, UnitTag)
GENLUAFUNC(Unit_Monster_Raptor, UnitTag)
GENLUAFUNC(Unit_Monster_Red, UnitTag)
GENLUAFUNC(Unit_Monster_Wolf, UnitTag)
GENLUAFUNC(Unit_Plant, UnitTag)
GENLUAFUNC(Unit_Special, UnitTag)
GENLUAFUNC(Unit_Special_AzirR, UnitTag)
GENLUAFUNC(Unit_Special_AzirW, UnitTag)
GENLUAFUNC(Unit_Special_CorkiBomb, UnitTag)
GENLUAFUNC(Unit_Special_EpicMonsterIgnores, UnitTag)
GENLUAFUNC(Unit_Special_KPMinion, UnitTag)
GENLUAFUNC(Unit_Special_MonsterIgnores, UnitTag)
GENLUAFUNC(Unit_Special_Peaceful, UnitTag)
GENLUAFUNC(Unit_Special_SyndraSphere, UnitTag)
GENLUAFUNC(Unit_Special_TeleportTarget, UnitTag)
GENLUAFUNC(Unit_Special_Trap, UnitTag)
GENLUAFUNC(Unit_Special_Tunnel, UnitTag)
GENLUAFUNC(Unit_Special_TurretIgnores, UnitTag)
GENLUAFUNC(Unit_Special_UntargetableBySpells, UnitTag)
GENLUAFUNC(Unit_Special_Void, UnitTag)
GENLUAFUNC(Unit_Special_YorickW, UnitTag)
GENLUAFUNC(Unit_Structure, UnitTag)
GENLUAFUNC(Unit_Structure_Inhibitor, UnitTag)
GENLUAFUNC(Unit_Structure_Nexus, UnitTag)
GENLUAFUNC(Unit_Structure_Turret, UnitTag)
GENLUAFUNC(Unit_Structure_Turret_Inhib, UnitTag)
GENLUAFUNC(Unit_Structure_Turret_Inner, UnitTag)
GENLUAFUNC(Unit_Structure_Turret_Nexus, UnitTag)
GENLUAFUNC(Unit_Structure_Turret_Outer, UnitTag)
GENLUAFUNC(Unit_Structure_Turret_Shrine, UnitTag)
GENLUAFUNC(Unit_Ward, UnitTag)

GENLUAFUNC(NONE, SummonerSpellType)
GENLUAFUNC(GHOST, SummonerSpellType)
GENLUAFUNC(HEAL, SummonerSpellType)
GENLUAFUNC(BARRIER, SummonerSpellType)
GENLUAFUNC(EXHAUST, SummonerSpellType)
GENLUAFUNC(CLARITY, SummonerSpellType)
GENLUAFUNC(SNOWBALL, SummonerSpellType)
GENLUAFUNC(FLASH, SummonerSpellType)
GENLUAFUNC(TELEPORT, SummonerSpellType)
GENLUAFUNC(CLEANSE, SummonerSpellType)
GENLUAFUNC(IGNITE, SummonerSpellType)
GENLUAFUNC(SMITE, SummonerSpellType)
GENLUAFUNC(RECALL, SummonerSpellType)
GENLUAFUNC(WARD, SummonerSpellType)

GENLUAFUNC(Q, SpellSlot)
GENLUAFUNC(W, SpellSlot)
GENLUAFUNC(E, SpellSlot)
GENLUAFUNC(R, SpellSlot)
GENLUAFUNC(D, SpellSlot)
GENLUAFUNC(F, SpellSlot)
GENLUAFUNC(NONE, SpellSlot)

static void ExportLuaStructure(lua_State *L) {
  luabridge::getGlobalNamespace(L)
      .beginClass<SpellInfo>("SpellInfo")
      .addProperty("width_", &SpellInfo::width, false)
      .addProperty("cast_radius_", &SpellInfo::castRadius, false)
      .addProperty("speed_", &SpellInfo::speed, false)
      .addProperty("cast_range_", &SpellInfo::castRange, false)
      .addProperty("delay_", &SpellInfo::delay, false)
      .addProperty("height_", &SpellInfo::height, false)
      .addProperty("icon_", &SpellInfo::icon, false)
      .addProperty("travel_time_", &SpellInfo::travelTime, false)
      .endClass();

  luabridge::getGlobalNamespace(L)
      .beginClass<ItemSlot>("Item")
      .addProperty("slot_", &ItemSlot::slot, false)

      .addFunction("GetId", &ItemSlot::GetId)
      .addFunction("GetCost", &ItemSlot::GetCost)
      .addFunction("GetMovementSpeed", &ItemSlot::GetMovementSpeed)
      .addFunction("GetHealth", &ItemSlot::GetHealth)
      .addFunction("GetCrit", &ItemSlot::GetCrit)
      .addFunction("GetAbilityPower", &ItemSlot::GetAbilityPower)
      .addFunction("GetMana", &ItemSlot::GetMana)
      .addFunction("GetArmour", &ItemSlot::GetArmour)
      .addFunction("GetMagicResist", &ItemSlot::GetMagicResist)
      .addFunction("GetPhysicalDamage", &ItemSlot::GetPhysicalDamage)
      .addFunction("GetAttackSpeed", &ItemSlot::GetAttackSpeed)
      .addFunction("GetLifeSteal", &ItemSlot::GetLifeSteal)
      .addFunction("GetHpRegen", &ItemSlot::GetHpRegen)
      .addFunction("GetMovementSpeedPercent",
                   &ItemSlot::GetMovementSpeedPercent)
      .endClass();

  luabridge::getGlobalNamespace(L)
      .beginClass<BuffInstance>("Buff")
      .addProperty("name_", &BuffInstance::name, false)
      .addProperty("is_alive_", &BuffInstance::isAlive, false)
      .addProperty("count_", &BuffInstance::count, false)
      .addProperty("count_alt_", &BuffInstance::countAlt, false)
      .addProperty("type_", &BuffInstance::type, false)
      .addProperty("start_time_", &BuffInstance::startTime, false)
      .addProperty("end_time_", &BuffInstance::endTime, false)
      .endClass();

  luabridge::getGlobalNamespace(L)
      .beginClass<Spell>("Spell")
      .addProperty("name_", &Spell::name, false)
      .addProperty("missileName_", &Spell::missileName, false)
      .addProperty("slot_", &Spell::slot, false)
      .addProperty("summoner_spell_type_", &Spell::summonerSpellType, false)
      .addProperty("level_", &Spell::level, false)
      .addProperty("ready_at_", &Spell::readyAt, false)
      .addProperty("value_", &Spell::value, false)
      .addProperty("time_charge_", &Spell::timeCharge, false)

      .addFunction("GetCurrentCooldown", &Spell::GetRemainingCooldown)

      .addFunction("GetTrigger", &Spell::Trigger)
      .addFunction("MoveAndTrigger", &Spell::MoveAndTrigger)

      .addFunction("GetWidth", &Spell::GetWidth)
      .addFunction("GetCastRadius", &Spell::GetCastRadius)
      .addFunction("GetSpeed", &Spell::GetSpeed)
      .addFunction("GetCastRange", &Spell::GetCastRange)
      .addFunction("GetDelay", &Spell::GetDelay)
      .addFunction("GetHeight", &Spell::GetHeight)
      .addFunction("GetIcon", &Spell::GetIcon)
      .addFunction("GetTravelTime", &Spell::GetTravelTime)
      .addFunction("HasSpellFlags", &Spell::HasSpellFlags)
      .addFunction("EqualSpellFlags", &Spell::EqualSpellFlags)
      .endClass();

  luabridge::getGlobalNamespace(L)
      .beginClass<GameObject>("Obj")
      .addProperty("address_", &GameObject::address, false)
      .addProperty("health_", &GameObject::health, false)
      .addProperty("mana_", &GameObject::mana, false)
      .addProperty("max_mana_", &GameObject::maxMana, false)
      .addProperty("max_health_", &GameObject::maxHealth, false)
      .addProperty("mana_regen_", &GameObject::manaRegen, false)
      .addProperty("health_regen_", &GameObject::healthRegen, false)
      .addProperty("base_atk_", &GameObject::baseAttack, false)
      .addProperty("bonus_atk_", &GameObject::bonusAttack, false)
      .addProperty("armour_", &GameObject::armour, false)
      .addProperty("magic_resist_", &GameObject::magicResist, false)
      .addProperty("movement_speed_", &GameObject::movementSpeed, false)
      .addProperty("is_alive_", &GameObject::isAlive, false)
      .addProperty("name_", &GameObject::name, false)
      .addProperty("pos_", &GameObject::position, false)
      .addProperty("prev_pos_", &GameObject::previousPosition, false)
      .addProperty("duration_", &GameObject::duration, false)
      .addProperty("is_visible_", &GameObject::isVisible, false)
      .addProperty("last_visible_at_", &GameObject::lastVisibleAt, false)
      .addProperty("id_", &GameObject::objectIndex, false)
      .addProperty("net_id_", &GameObject::networkId, false)
      .addProperty("crit_", &GameObject::crit, false)
      .addProperty("crit_multi_", &GameObject::critMulti, false)
      .addProperty("ap_", &GameObject::abilityPower, false)
      .addProperty("atk_speed_multi_", &GameObject::atkSpeedMulti, false)
      .addProperty("team_", &GameObject::team, false)
      .addProperty("is_targetable_", &GameObject::isTargetable, false)
      .addProperty("is_direction_", &GameObject::isDirection, false)
      .addProperty("is_moving_", &GameObject::isMoving, false)
      .addProperty("is_invulnerable_", &GameObject::isInvulnerable, false)
      .addProperty("is_recalling_", &GameObject::isRecalling, false)
      .addProperty("atk_range_", &GameObject::atkRange, false)

      .addProperty("current_dash_speed_", &GameObject::currentDashSpeed, false)
      .addProperty("is_dashing_", &GameObject::isDashing, false)
      .addProperty("d_is_moving_", &GameObject::dIsMoving, false)
      .addProperty("dash_pos_", &GameObject::dashPos, false)
      .addProperty("nav_begin_", &GameObject::navBegin, false)
      .addProperty("nav_end_", &GameObject::navEnd, false)

      .addFunction("GetAcquisitionRadius", &GameObject::GetAcquisitionRadius)
      .addFunction("GetSelectionRadius", &GameObject::GetSelectionRadius)
      .addFunction("GetPathingRadius", &GameObject::GetPathingRadius)
      .addFunction("GetGameplayRadius", &GameObject::GetGameplayRadius)

      .addFunction("GetBasicAttackMissileSpeed",
                   &GameObject::GetBasicAttackMissileSpeed)
      .addFunction("GetBasicAttackWindup", &GameObject::GetBasicAttackWindup)
      .addFunction("GetBaseMovementSpeed", &GameObject::GetBaseMovementSpeed)
      .addFunction("GetBaseAttackSpeed", &GameObject::GetBaseAttackSpeed)
      .addFunction("GetBaseAttackRange", &GameObject::GetBaseAttackRange)
      
      
      .addFunction("GetAttackRange", &GameObject::GetAttackRange)
      .addFunction("GetAttackSpeedRatio", &GameObject::GetAttackSpeedRatio)
      
      .addFunction("IsRanged", &GameObject::IsRanged)

      .addFunction("IsEqualTo", &GameObject::IsEqualTo)
      .addFunction("IsNotEqualTo", &GameObject::IsNotEqualTo)
      .addFunction("IsAllyTo", &GameObject::IsAllyTo)
      .addFunction("IsEnemyTo", &GameObject::IsEnemyTo)
      .addFunction("HasUnitTags", &GameObject::HasUnitTags)

      // Champion
      .addProperty("Q", &GameObject::Q, false)
      .addProperty("W", &GameObject::W, false)
      .addProperty("E", &GameObject::E, false)
      .addProperty("R", &GameObject::R, false)
      .addProperty("D", &GameObject::D, false)
      .addProperty("F", &GameObject::F, false)

      .addFunction("GetItems", &GameObject::ItemsToList)
      .addFunction("GetBuffs", &GameObject::BuffsToList)

      .addProperty("level_", &GameObject::level, false)

      .addFunction("GetSummonerSpell", &GameObject::GetSummonerSpell)

      // Missile
      .addProperty("src_index_", &GameObject::srcIndex, false)
      .addProperty("dest_index_", &GameObject::destIndex, false)
      .addProperty("start_pos_", &GameObject::startPos, false)
      .addProperty("end_pos_", &GameObject::endPos, false)

      // Spell
      .addFunction("GetWidth", &GameObject::GetWidth)
      .addFunction("GetCastRadius", &GameObject::GetCastRadius)
      .addFunction("GetSpeed", &GameObject::GetSpeed)
      .addFunction("GetCastRange", &GameObject::GetCastRange)
      .addFunction("GetDelay", &GameObject::GetDelay)
      .addFunction("GetHeight", &GameObject::GetHeight)
      .addFunction("GetIcon", &GameObject::GetIcon)
      .addFunction("GetTravelTime", &GameObject::GetTravelTime)
      .addFunction("HasSpellFlags", &GameObject::HasSpellFlags)
      .addFunction("EqualSpellFlags", &GameObject::EqualSpellFlags)
      .endClass();

  luabridge::getGlobalNamespace(L)
      .beginClass<GameRenderer>("GameRenderer")
      .addProperty("width_", &GameRenderer::width, false)
      .addProperty("height_", &GameRenderer::height, false)
      .endClass();
  ;

  luabridge::getGlobalNamespace(L)
      .beginClass<LuaGameInterface>("Game")
      .addProperty("champs_", &LuaGameInterface::champs)
      .addProperty("minions_", &LuaGameInterface::minions)
      .addProperty("jungle_", &LuaGameInterface::jungle)
      .addProperty("turrets_", &LuaGameInterface::turrets)
      .addProperty("missiles_", &LuaGameInterface::missiles)
      .addProperty("others_", &LuaGameInterface::others)

      .addFunction("GetHoveredObject", &LuaGameInterface::GetHoveredObject)
      .addFunction("GetPlayer", &LuaGameInterface::GetLocalChampion)

      .addProperty("time_", &LuaGameInterface::gameTime)
      .addProperty("is_chat_open_", &LuaGameInterface::isChatOpen)
      .addProperty("ping_", &LuaGameInterface::ping)

      .addFunction("GetMap", &LuaGameInterface::GetMap)

      .addFunction("GetObjectByIndex", &LuaGameInterface::GetObjectByIndex)
      .addFunction("GetObjectByNetId", &LuaGameInterface::GetObjectByNetId)
      .addFunction("GetBestTarget", &LuaGameInterface::GetBestTarget)

      .addFunction("IsScreenPointOnScreen", (bool (LuaGameInterface::*)(const Vector2 &, float,float) )&LuaGameInterface::IsScreenPointOnScreen)
      .addFunction("IsWorldPointOnScreen", (bool (LuaGameInterface::*)(const Vector3 &, float,float) )&LuaGameInterface::IsWorldPointOnScreen)

      .addFunction("IsScreenPointOnScreen",(bool (LuaGameInterface::*)(const Vector2 &) ) &LuaGameInterface::IsScreenPointOnScreen)
      .addFunction("IsWorldPointOnScreen", (bool (LuaGameInterface::*)(const Vector3 &) )&LuaGameInterface::IsWorldPointOnScreen)

      .addFunction("WorldToScreen", &LuaGameInterface::WorldToScreen)
      .addFunction("WorldToMinimap", &LuaGameInterface::WorldToMinimap)
      .addFunction("DistanceToMinimap", &LuaGameInterface::DistanceToMinimap)
      .addFunction("Distance", &LuaGameInterface::Distance)

      .addFunction("DrawLine", &LuaGameInterface::DrawLine)
      .addFunction("DrawCircle", &LuaGameInterface::DrawCircle)
      .addFunction("DrawCircleFilled", &LuaGameInterface::DrawCircleFilled)
      .addFunction("DrawCircleWorld", &LuaGameInterface::DrawCircleWorld)
      .addFunction("DrawCircleWorldFilled", &LuaGameInterface::DrawCircleWorldFilled)
      .addFunction("DrawText", &LuaGameInterface::DrawText)
      .addFunction("DrawRect", &LuaGameInterface::DrawRect)
      .addFunction("DrawRectFilled", &LuaGameInterface::DrawRectFilled)
      .addFunction("DrawRectWorld", &LuaGameInterface::DrawRectWorld)
      .addFunction("DrawTriangleWorld", &LuaGameInterface::DrawTriangleWorld)
      .addFunction("DrawTriangleWorldFilled", &LuaGameInterface::DrawTriangleWorldFilled)
      .addFunction("DrawButton", &LuaGameInterface::DrawButton)
      .addFunction("DrawImage", &LuaGameInterface::DrawImage)
      .addFunction("DrawImageRounded", &LuaGameInterface::DrawImageRounded)

      .addFunction("GetSpellInfo", &LuaGameInterface::GetSpellInfo)
      .addFunction("GetHpBarPos", &LuaGameInterface::HpBarPos)

      .addFunction("Clamp2D", &LuaGameInterface::clamp_norm_2d)
      .addFunction("IsLeft", &LuaGameInterface::IsLeft)
      .addFunction("PointOnLineSegment", &LuaGameInterface::PointOnLineSegment)
      .addFunction("isPointOnLineSegment", &LuaGameInterface::IsPointOnLineSegment)

      .addFunction("WasKeyPressed", &LuaGameInterface::WasKeyPressed)
      .addFunction("IsKeyDown", &LuaGameInterface::IsKeyDown)
      .addFunction("PressKey", &LuaGameInterface::PressKey)
      .addFunction("PressLeftClick", &LuaGameInterface::PressLeftClick)
      .addFunction("PressRightClick", &LuaGameInterface::PressRightClick)
      .addFunction("MouseLeftDown", &LuaGameInterface::MouseLeftDown)
      .addFunction("MouseLeftUp", &LuaGameInterface::MouseLeftUp)
      .addFunction("MouseRightDown", &LuaGameInterface::MouseRightDown)
      .addFunction("MouseRightUp", &LuaGameInterface::MouseRightUp)
      .addFunction("ClickAt", &LuaGameInterface::ClickAt)
      .addFunction("GetCursor", &LuaGameInterface::GetCursor)
      .endClass();

  luabridge::getGlobalNamespace(L)
      .beginClass<MapObject>("Map")
      .addFunction("GetHeightAt", &MapObject::GetHeightAt)
      .addProperty("type_", &MapObject::type, false)
      .endClass();

  luabridge::getGlobalNamespace(L)
      .beginClass<LuaGUIInterface>("UI")
      .addFunction("Begin", &LuaGUIInterface::Begin)
      .addFunction("End", &LuaGUIInterface::End)

      .addFunction("Button", &LuaGUIInterface::Button)
      .addFunction("ColorButton", &LuaGUIInterface::ColorButton)
      .addFunction("ColorPicker", &LuaGUIInterface::ColorPicker)
      .addFunction("Checkbox", &LuaGUIInterface::Checkbox)
      .addFunction("Text", &LuaGUIInterface::Text)
      .addFunction("TextColored", &LuaGUIInterface::TextColored)
      .addFunction("LabelText", &LuaGUIInterface::LabelText)
      .addFunction("LabelTextColored", &LuaGUIInterface::LabelTextColored)
      .addFunction("Separator", &LuaGUIInterface::Separator)
      .addFunction("DragInt2", &LuaGUIInterface::DragInt2)
      .addFunction("DragInt5", &LuaGUIInterface::DragInt5)
      .addFunction("DragFloat2", &LuaGUIInterface::DragFloat2)
      .addFunction("DragFloat5", &LuaGUIInterface::DragFloat5)
      .addFunction("KeySelect", &LuaGUIInterface::KeySelect)
      .addFunction("SliderFloat", &LuaGUIInterface::SliderFloat)
      .addFunction("SliderInt", &LuaGUIInterface::SliderInt)

      .addFunction("CollapsingHeader", &LuaGUIInterface::CollapsingHeader)
      .addFunction("TreeNode", &LuaGUIInterface::TreeNode)
      .addFunction("TreePop", &LuaGUIInterface::TreePop)
      .addFunction("SetNextItemOpen", &LuaGUIInterface::SetNextItemOpen)

      .addFunction("SameLine", &LuaGUIInterface::SameLine)
      .addFunction("BeginGroup", &LuaGUIInterface::BeginGroup)
      .addFunction("EndGroup", &LuaGUIInterface::EndGroup)

      .addFunction("ListBox", &LuaGUIInterface::ListBox)
      .endClass();

  luabridge::getGlobalNamespace(L)
      .beginClass<ImVec4>("Color")
      .addConstructor<void (*)()>()
      .addConstructor<void (*)(float, float, float, float)>()

      .addProperty("r_", &ImVec4::x)
      .addProperty("g_", &ImVec4::y)
      .addProperty("b_", &ImVec4::z)
      .addProperty("a_", &ImVec4::w)
      .endClass();

  luabridge::getGlobalNamespace(L)
      .beginClass<Vector4>("Vec4")
      .addConstructor<void (*)()>()
      .addConstructor<void (*)(float, float, float, float)>()
      .addProperty("x_", &Vector4::x)
      .addProperty("y_", &Vector4::y)
      .addProperty("z_", &Vector4::z)
      .addProperty("w_", &Vector4::w)
      .addFunction("Length", &Vector4::length)
      .addFunction("Normalize", &Vector4::normalize)
      .addFunction("Distance", &Vector4::distance)
      .addFunction("Scale", &Vector4::scale)
      .addFunction("VScale", &Vector4::vscale)
      .addFunction("Add", &Vector4::add)
      .addFunction("Sub", &Vector4::sub)
      .addFunction("Clone", &Vector4::clone)
      .endClass();

  luabridge::getGlobalNamespace(L)
      .beginClass<Vector3>("Vec3")
      .addConstructor<void (*)()>()
      .addConstructor<void (*)(float, float, float)>()
      .addProperty("x_", &Vector3::x)
      .addProperty("y_", &Vector3::y)
      .addProperty("z_", &Vector3::z)
      .addFunction("Length", &Vector3::length)
      .addFunction("Normalize", &Vector3::normalize)
      .addFunction("Distance", &Vector3::distance)
      .addFunction("Scale", &Vector3::scale)
      .addFunction("VScale", &Vector3::vscale)
      .addFunction("RotateX", &Vector3::rotate_x)
      .addFunction("RotateY", &Vector3::rotate_y)
      .addFunction("RotateZ", &Vector3::rotate_z)
      .addFunction("Add", &Vector3::add)
      .addFunction("Sub", &Vector3::sub)
      .addFunction("Clone", &Vector3::clone)
      .addFunction("Extend", &Vector3::extend)
      .endClass();

  luabridge::getGlobalNamespace(L)
      .beginClass<Vector2>("Vec2")
      .addConstructor<void (*)()>()
      .addConstructor<void (*)(float, float)>()
      .addProperty("x_", &Vector2::x)
      .addProperty("y_", &Vector2::y)
      .addFunction("Length", &Vector2::length)
      .addFunction("Normalize", &Vector2::normalize)
      .addFunction("Distance", &Vector2::distance)
      .addFunction("Scale", &Vector2::scale)
      .addFunction("VScale", &Vector2::vscale)
      .addFunction("Add", &Vector2::add)
      .addFunction("Sub", &Vector2::sub)
      .addFunction("Clone", &Vector2::clone)
      .endClass();

  luabridge::getGlobalNamespace(L)
      .beginClass<ConfigSet>("ConfigSet")
      .addFunction("SetInt", &ConfigSet::SetInt)
      .addFunction("SetBool", &ConfigSet::SetBool)
      .addFunction("SetFloat", &ConfigSet::SetFloat)
      .addFunction("SetStr", &ConfigSet::SetStr)
      .addFunction("GetInt", &ConfigSet::GetInt)
      .addFunction("GetBool", &ConfigSet::GetBool)
      .addFunction("GetFloat", &ConfigSet::GetFloat)
      .addFunction("GetStr", &ConfigSet::GetStr)
      .endClass();

  luabridge::getGlobalNamespace(L)
      .beginNamespace("Color")
      .addFunction("BLACK", &Colors::_BLACK)
      .addFunction("WHITE", &Colors::_WHITE)
      .addFunction("RED", &Colors::_RED)
      .addFunction("DARK_RED", &Colors::_DARK_RED)
      .addFunction("GREEN", &Colors::_GREEN)
      .addFunction("DARK_GREEN", &Colors::_DARK_GREEN)
      .addFunction("YELLOW", &Colors::_YELLOW)
      .addFunction("DARK_YELLOW", &Colors::_DARK_YELLOW)
      .addFunction("CYAN", &Colors::_CYAN)
      .addFunction("PURPLE", &Colors::_PURPLE)
      .addFunction("GRAY", &Colors::_GRAY)
      .addFunction("ORANGE", &Colors::_ORANGE)
      .addFunction("BLUE", &Colors::_BLUE)
      .addFunction("BROWN", &Colors::_BROWN)
      .endNamespace();

  /*************************	enum	*******************************/

  luabridge::getGlobalNamespace(L)
      .beginNamespace("MapType")
      .addFunction("SummonersRift", &SUMMONERS_RIFT_MapType)
      .addFunction("HowlingAbyss", &HOWLING_ABYSS_MapType)
      .endNamespace();

  luabridge::getGlobalNamespace(L)
      .beginNamespace("SpellSlot")
      .addFunction("Q", &Q_SpellSlot)
      .addFunction("W", &W_SpellSlot)
      .addFunction("E", &E_SpellSlot)
      .addFunction("R", &R_SpellSlot)
      .addFunction("D", &D_SpellSlot)
      .addFunction("F", &F_SpellSlot)
      .addFunction("NONE", &NONE_SpellSlot)
      .endNamespace();

  luabridge::getGlobalNamespace(L)
      .beginNamespace("SpellFlags")
      .addFunction("AffectAllyChampion", &AffectAllyChampion_SpellFlags)
      .addFunction("AffectEnemyChampion", &AffectEnemyChampion_SpellFlags)
      .addFunction("AffectAllyLaneMinion", &AffectAllyLaneMinion_SpellFlags)
      .addFunction("AffectEnemyLaneMinion", &AffectEnemyLaneMinion_SpellFlags)
      .addFunction("AffectAllyWard", &AffectAllyWard_SpellFlags)
      .addFunction("AffectEnemyWard", &AffectEnemyWard_SpellFlags)
      .addFunction("AffectAllyTurret", &AffectAllyTurret_SpellFlags)
      .addFunction("AffectEnemyTurret", &AffectEnemyTurret_SpellFlags)

      .addFunction("AffectAllyInhibs", &AffectAllyInhibs_SpellFlags)
      .addFunction("AffectEnemyInhibs", &AffectEnemyInhibs_SpellFlags)

      .addFunction("AffectAllyNonLaneMinion",
                   &AffectAllyNonLaneMinion_SpellFlags)
      .addFunction("AffectJungleMonster", &AffectJungleMonster_SpellFlags)
      .addFunction("AffectEnemyNonLaneMinion",
                   &AffectEnemyNonLaneMinion_SpellFlags)
      .addFunction("AffectAlwaysSelf", &AffectAlwaysSelf_SpellFlags)
      .addFunction("AffectNeverSelf", &AffectNeverSelf_SpellFlags)

      .addFunction("ProjectDestination", &ProjectedDestination_SpellFlags)
      .addFunction("AffectAllyMob", &AffectAllyMob_SpellFlags)
      .addFunction("AffectEnemyMob", &AffectEnemyMob_SpellFlags)
      .addFunction("AffectAllyGeneric", &AffectAllyGeneric_SpellFlags)
      .addFunction("AffectEnemyGeneric", &AffectEnemyGeneric_SpellFlags)
      .endNamespace();

  luabridge::getGlobalNamespace(L)
      .beginNamespace("SummonerSpellType")
      .addFunction("Ghost", &GHOST_SummonerSpellType)
      .addFunction("Heal", &HEAL_SummonerSpellType)
      .addFunction("Barrier", &BARRIER_SummonerSpellType)
      .addFunction("Exhaust", &EXHAUST_SummonerSpellType)
      .addFunction("Clarity", &CLARITY_SummonerSpellType)
      .addFunction("Snowball", &SNOWBALL_SummonerSpellType)
      .addFunction("Flash", &FLASH_SummonerSpellType)
      .addFunction("Teleport", &TELEPORT_SummonerSpellType)
      .addFunction("Cleanse", &CLEANSE_SummonerSpellType)
      .addFunction("Ignite", &IGNITE_SummonerSpellType)
      .addFunction("Smite", &SMITE_SummonerSpellType)
      .addFunction("None", &NONE_SummonerSpellType)
      .endNamespace();

  luabridge::getGlobalNamespace(L)
      .beginNamespace("UnitTag")
      .addFunction("Unit_Champion", &Unit_Champion_UnitTag)
      .addFunction("Unit_Champion_Clone", &Unit_Champion_Clone_UnitTag)
      .addFunction("Unit_IsolationNonImpacting",
                   &Unit_IsolationNonImpacting_UnitTag)
      .addFunction("Unit_KingPoro", &Unit_KingPoro_UnitTag)
      .addFunction("Unit_Minion", &Unit_Minion_UnitTag)
      .addFunction("Unit_Minion_Lane", &Unit_Minion_Lane_UnitTag)
      .addFunction("Unit_Minion_Lane_Melee", &Unit_Minion_Lane_Melee_UnitTag)
      .addFunction("Unit_Minion_Lane_Ranged", &Unit_Minion_Lane_Ranged_UnitTag)
      .addFunction("Unit_Minion_Lane_Siege", &Unit_Minion_Lane_Siege_UnitTag)
      .addFunction("Unit_Minion_Lane_Super", &Unit_Minion_Lane_Super_UnitTag)
      .addFunction("Unit_Minion_Summon", &Unit_Minion_Summon_UnitTag)
      .addFunction("Unit_Minion_Summon_Large",
                   &Unit_Minion_Summon_Large_UnitTag)
      .addFunction("Unit_Monster", &Unit_Monster_UnitTag)
      .addFunction("Unit_Monster_Blue", &Unit_Monster_Blue_UnitTag)
      .addFunction("Unit_Monster_Buff", &Unit_Monster_Buff_UnitTag)
      .addFunction("Unit_Monster_Camp", &Unit_Monster_Camp_UnitTag)
      .addFunction("Unit_Monster_Crab", &Unit_Monster_Crab_UnitTag)
      .addFunction("Unit_Monster_Dragon", &Unit_Monster_Dragon_UnitTag)
      .addFunction("Unit_Monster_Epic", &Unit_Monster_Epic_UnitTag)
      .addFunction("Unit_Monster_Gromp", &Unit_Monster_Gromp_UnitTag)
      .addFunction("Unit_Monster_Krug", &Unit_Monster_Krug_UnitTag)
      .addFunction("Unit_Monster_Large", &Unit_Monster_Large_UnitTag)
      .addFunction("Unit_Monster_Medium", &Unit_Monster_Medium_UnitTag)
      .addFunction("Unit_Monster_Raptor", &Unit_Monster_Raptor_UnitTag)
      .addFunction("Unit_Monster_Red", &Unit_Monster_Red_UnitTag)
      .addFunction("Unit_Monster_Wolf", &Unit_Monster_Wolf_UnitTag)
      .addFunction("Unit_Plant", &Unit_Plant_UnitTag)
      .addFunction("Unit_Special", &Unit_Special_UnitTag)
      .addFunction("Unit_Special_AzirR", &Unit_Special_AzirR_UnitTag)
      .addFunction("Unit_Special_AzirW", &Unit_Special_AzirW_UnitTag)
      .addFunction("Unit_Special_CorkiBomb", &Unit_Special_CorkiBomb_UnitTag)
      .addFunction("Unit_Special_EpicMonsterIgnores",
                   &Unit_Special_EpicMonsterIgnores_UnitTag)
      .addFunction("Unit_Special_KPMinion", &Unit_Special_KPMinion_UnitTag)
      .addFunction("Unit_Special_MonsterIgnores",
                   &Unit_Special_MonsterIgnores_UnitTag)
      .addFunction("Unit_Special_Peaceful", &Unit_Special_Peaceful_UnitTag)
      .addFunction("Unit_Special_SyndraSphere",
                   &Unit_Special_SyndraSphere_UnitTag)
      .addFunction("Unit_Special_TeleportTarget",
                   &Unit_Special_TeleportTarget_UnitTag)
      .addFunction("Unit_Special_Trap", &Unit_Special_Trap_UnitTag)
      .addFunction("Unit_Special_Tunnel", &Unit_Special_Tunnel_UnitTag)
      .addFunction("Unit_Special_TurretIgnores",
                   &Unit_Special_TurretIgnores_UnitTag)
      .addFunction("Unit_Special_UntargetableBySpells",
                   &Unit_Special_UntargetableBySpells_UnitTag)
      .addFunction("Unit_Special_Void", &Unit_Special_Void_UnitTag)
      .addFunction("Unit_Special_YorickW", &Unit_Special_YorickW_UnitTag)
      .addFunction("Unit_Structure", &Unit_Structure_UnitTag)
      .addFunction("Unit_Structure_Inhibitor",
                   &Unit_Structure_Inhibitor_UnitTag)
      .addFunction("Unit_Structure_Nexus", &Unit_Structure_Nexus_UnitTag)
      .addFunction("Unit_Structure_Turret", &Unit_Structure_Turret_UnitTag)
      .addFunction("Unit_Structure_Turret_Inhib",
                   &Unit_Structure_Turret_Inhib_UnitTag)
      .addFunction("Unit_Structure_Turret_Inner",
                   &Unit_Structure_Turret_Inner_UnitTag)
      .addFunction("Unit_Structure_Turret_Nexus",
                   &Unit_Structure_Turret_Nexus_UnitTag)
      .addFunction("Unit_Structure_Turret_Outer",
                   &Unit_Structure_Turret_Outer_UnitTag)
      .addFunction("Unit_Structure_Turret_Shrine",
                   &Unit_Structure_Turret_Shrine_UnitTag)
      .addFunction("Unit_Ward", &Unit_Ward_UnitTag)
      .endNamespace();
}