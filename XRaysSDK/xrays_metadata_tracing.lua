--- Object detection
script = "XRays® metadata tracker"
author = "XRays®"
description = "show all object"

function DrawSpell(spell, ui)
    if ui:TreeNode(tonumber(spell.solt_)) then
        ui:LabelText("Name", spell.name_)
        ui:LabelText("MissileName", spell.missile_name_)
        ui:LabelText("SummmonerSpellType", tostring(spell.summoner_spell_type_))
        ui:DragInt2("Level", spell.level_)
        ui:DragFloat2("ReadyAt", spell.ready_at_)
        ui:DragFloat2("Value", spell.value_)
        ui:DragFloat2("TimeCharge", spell.time_charge_)

        ui:Separator()
        ui:DragFloat2("Speed", spell.speed_)
        ui:DragFloat2("CastRange", spell.cast_range_)
        ui:DragFloat2("Width", spell.width_)
        ui:DragFloat2("CastRadius", spell.cast_radius_)
        ui:DragFloat2("Height", spell.height_)
        ui:DragFloat2("Delay", spell.delay_)
        ui:TreePop()
    end
end

function DrawItems(items, ui)
    for item in items do
        if ui:TreeNode(tostring(item.id_)) then
            ui:DragInt2("Slot", item.slot_)
            if item:MovementSpeed() > 0 then
                ui:DragFloat2("MovementSpeed", item:MovementSpeed())
            end
            if item.health_ > 0 then
                ui:DragFloat2("Health", item.health_)
            end
            if item.crit > 0 then ui:DragFloat2("Crit", item.crit_) end
            if item.ability_power > 0 then
                ui:DragFloat2("AbilityPower", item.ability_power_)
            end
            if item.mana > 0 then ui:DragFloat2("Mana", item.mana_) end
            if item.armour > 0 then
                ui:DragFloat2("Armour", item.armour_)
            end
            if item.magic_resist > 0 then
                ui:DragFloat2("MagicResist", item.magic_resist_)
            end
            if item.physical_damage > 0 then
                ui:DragFloat2("PhysicalDamage", item.physical_damage_)
            end
            if item.attack_speed > 0 then
                ui:DragFloat2("attack_speed", item.attack_speed_)
            end
            if item.life_steal > 0 then
                ui:DragFloat2("life_steal", item.life_steal_)
            end
            if item.hp_regen > 0 then
                ui:DragFloat2("hp_regen", item.hp_regen_)
            end
            if item.movement_speed_percent > 0 then
                ui:DragFloat2("movement_speed_percent",
                              item.movement_speed_percent_)
            end
            ui:TreePop()
        end
    end
end

function DrawBuffs(buffs, ui)
    for idx, buff in pairs(buffs) do
        if ui:TreeNode(tostring(buff.name_)) then
            ui:Checkbox("isAlive", buff.is_alive_)
            if buff.count_ > 0 then
                ui:LabelText("count", tostring(buff.count_))
            end
            if buff.count_alt_ > 0 then
                ui:LabelText("countAlt", tostring(buff.count_alt_))
            end
            if buff.type_ > 0 then ui:DragInt2("type", buff.type_) end
            if buff.start_time_ > 0 then
                ui:DragFloat2("start_time", buff.start_time_)
            end
            if buff.end_time_ > 0 then
                ui:DragFloat2("end_time", buff.end_time_)
            end
            ui:TreePop()
        end
    end
end

function DrawMissile(obj, ui)
    if ui:TreeNode(string.format("%s,%d,%d,%X", obj.name, obj.src_id,
                                 obj.dest_id, obj.address)) then
        ui:DragInt2("id", obj.id)
        ui:LabelText("net_id", string.format("%02X", obj.net_id_))
        ui:DragInt2("team", obj.team_)

        ui:LabelText("start_pos",
                     string.format("%2f, %2f, %2f", obj.start_pos_.x_,
                                   obj.start_pos_.y_, obj.start_pos_.z_))
        ui:LabelText("end_pos", string.format("%2f, %2f, %2f", obj.end_pos_.x_,
                                              obj.end_pos_.y_, obj.end_pos_.z_))
        ui:LabelText("pos", string.format("%2f, %2f, %2f", obj.pos_.x_, obj.pos_.y_,
                                          obj.pos_.z_))

        ui:DragInt2("src_index", obj.src_index_)
        ui:DragInt2("src_index", obj.src_index_)

        ui:Separator()
        ui:DragFloat2("speed", obj.speed_)
        ui:DragFloat2("cast_range", obj.cast_range_)
        ui:DragFloat2("width", obj.width_)
        ui:DragFloat2("cast_radius", obj.cast_radius_)
        ui:DragFloat2("height", obj.height_)
        ui:DragFloat2("delay", obj.delay_)
        ui:TreePop()
    end
end

function DrawGameObject(player, ui, additional_draw, set_open)

    if player == nil then
        ui:text_colored("null", Color.BLUE)
        return
    end

    if set_open then ui:opennext() end

    if ui:TreeNode(string.format("%s, %s, %02X", player.name_, player.id_,
                                 player.address_)) then
        ui:LabelText("address", string.format("%02X", (player.address_)))
        ui:LabelText("net_id", string.format("%02X", (player.net_id_)))

        ui:LabelText("name", player.name_, Color._DARK_GREEN)
        ui:LabelText("pos", string.format("%2f, %2f, %2f", player.pos_.x_,
                                          player.pos_.y_, player.pos_.z_))
        ui:DragInt2("id", player.id_)

        ui:Separator()
        ui:DragFloat2("health", player.health_)
        ui:DragFloat2("mana", player.mana_)
        ui:DragFloat2("max_mana", player.max_mana_)
        ui:DragFloat2("health_regen", player.health_regen_)
        ui:DragFloat2("mana_regen", player.mana_regen_)
        ui:Checkbox("is_alive", player.is_alive_)

        ui:Separator()
        ui:DragFloat2("currentDashSpeed", player.current_dash_speed_)
        ui:Checkbox("isDashing", player.is_dashing_)
        ui:Checkbox("dIsMoving", player._dash_pos_)
        ui:LabelText("dash_pos_",
                     string.format("%2f, %2f, %2f", player.dash_pos_.x_,
                                   player.dash_pos_.y_, player.dash_pos_.z_))

        ui:Separator()
        ui:DragFloat2("base_atk", player.base_atk_)
        ui:DragFloat2("bonus_atk", player.bonus_atk_)
        ui:DragFloat2("armour", player.armour_)
        ui:DragFloat2("magic_resist", player.magic_resist_)
        ui:DragFloat2("ap", player.ap_)
        ui:DragFloat2("crit", player.crit_)
        ui:DragFloat2("crit_multi", player.crit_multi_)

        ui:Separator()
        ui:DragFloat2("basic_atk_missile_speed", player:GetBasicAttackMissileSpeed())
        ui:DragFloat2("base_atk_range", player:GetBaseAttackRange())
        ui:DragFloat2("base_atk_speed", player:GetBaseAttackSpeed())
        
        ui:DragFloat2("atk_range", player:GetBaseAttackRange())
        ui:DragFloat2("atk_speed_ratio", player:GetAttackSpeedRatio())


        ui:DragFloat2("atk_speed_multi", player.atk_speed_multi_)

        ui:DragFloat2("base_ms", player:GetBaseMovementSpeed())
        ui:DragFloat2("MovementSpeed", player.movement_speed_)

        ui:Separator()
        ui:DragFloat2("SelectionRadius", player:GetSelectionRadius())
        ui:DragFloat2("GamePlayRadius", player:GetGameplayRadius())
        ui:DragFloat2("pathing_radius", player:GetPathingRadius())
        ui:DragFloat2("acquisition_radius", player:GetAcquisitionRadius())

        ui:Separator()
        ui:DragFloat2("duration", player.duration_)
        ui:DragFloat2("last_visible_at", player.last_visible_at_)

        ui:Text("Buffs")
        DrawBuffs(player:GetBuffs(), ui)

        ui:Checkbox("is_visible", player.is_visible_)
        if additional_draw then additional_draw(player, ui) end

        ui:TreePop()
    end
end

function DrawChampion(player, ui) DrawGameObject(player, ui) end

function DrawList(label, objs, ui)
    if ui:TreeNode(label) then
        for k, v in pairs(objs) do DrawChampion(v, ui) end
        ui:TreePop()
    end
end

function XRaysLoadCfg() end

function XRaysSaveCfg() end

function XRaysDrawSettings() end

function BoolToNumber(value) return value and 1 or 0 end

function XRaysUpdate(game, ui)
    ui:Begin("XRays® metadata tracker")
    ui:DragFloat2("time", game.time_)
    ui:DragFloat2("chat", BoolToNumber(game.is_chat_open_))
    ui:DragInt2("ping", game.ping_)
    if game:GetHoveredObject() then
        ui:LabelText("GetHoveredObject", string.format("%s, %02X",
                                                 game:GetHoveredObject().name_,
                                                 game:GetHoveredObject().address_))
    else
        ui:LabelText("GetHoveredObject", "none")
    end

    ui:Text("Local Champion")
    DrawChampion(game:GetPlayer(), ui)

    ui:Text("Lists")

    DrawList("Champions", game.champs_, ui, DrawChampion)
    DrawList("Minions", game.minions_, ui, DrawGameObject)
    DrawList("Jungle", game.jungle_, ui, DrawGameObject)
    DrawList("Turrets", game.turrets_, ui, DrawGameObject)
    DrawList("Missiles", game.missiles_, ui, DrawMissile)
    DrawList("Others", game.others_, ui, DrawGameObject)

    ui:End()
end
