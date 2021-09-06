script = "XRays® object detection"
author = "XRays®"
description = "AI"

function XRaysLoadCfg() end
function XRaysSaveCfg() end
function XRaysDrawSettings() end

function XRaysUpdate(snapshot, ui)
    for idx, item in pairs(snapshot.minions_) do
        if (item.is_visible_ or item.is_alive_) then
            world_pos = item.pos_
            screen_pos = snapshot:WorldToScreen(world_pos)
            if (snapshot:IsScreenPointOnScreen(screen_pos)) then

                if (item:IsEnemyTo(snapshot:GetPlayer())) then

                    snapshot:DrawText(Vec2(screen_pos.x_ + 40,
                                           screen_pos.y_ + 40),
                                      "Enemy Minion Unit,  Health=" ..
                                          item.health_ .. ",AttachRange=" ..
                                          item.atk_range_, Color:RED())

                    snapshot:DrawCircle(Vec2(screen_pos.x_, screen_pos.y_),
                                        item.atk_range_, 0, 3, Color:RED())

                    snapshot:DrawCircle(Vec2(screen_pos.x_, screen_pos.y_),
                                        item:GetAcquisitionRadius(), 0, 3,
                                        Color:RED())
                    snapshot:DrawCircle(Vec2(screen_pos.x_, screen_pos.y_),
                                        item:GetSelectionRadius(), 0, 3,
                                        Color:RED())
                    snapshot:DrawCircle(Vec2(screen_pos.x_, screen_pos.y_),
                                        item:GetPathingRadius(), 0, 3,
                                        Color:RED())

                    snapshot:DrawRect(Vec4(screen_pos.x_ + 40,
                                           screen_pos.y_ + 40,
                                           screen_pos.x_ - 40,
                                           screen_pos.y_ - 40), Color:RED(), 0,
                                      3)
                else
                    snapshot:DrawText(Vec2(screen_pos.x_ + 40,
                                           screen_pos.y_ + 40),
                                      "Ally Minion Unit,  Health=" ..
                                          item.health_ .. ",AttachRange=" ..
                                          item.atk_range_, Color:GREEN())

                    snapshot:DrawCircle(Vec2(screen_pos.x_, screen_pos.y_),
                                        item.atk_range_, 0, 3, Color:GREEN())

                    snapshot:DrawCircle(Vec2(screen_pos.x_, screen_pos.y_),
                                        item:GetAcquisitionRadius(), 0, 3,
                                        Color:GREEN())
                    snapshot:DrawCircle(Vec2(screen_pos.x_, screen_pos.y_),
                                        item:GetSelectionRadius(), 0, 3,
                                        Color:GREEN())
                    snapshot:DrawCircle(Vec2(screen_pos.x_, screen_pos.y_),
                                        item:GetPathingRadius(), 0, 3,
                                        Color:GREEN())

                    snapshot:DrawRect(Vec4(screen_pos.x_ + 40,
                                           screen_pos.y_ + 40,
                                           screen_pos.x_ - 40,
                                           screen_pos.y_ - 40), Color:GREEN(),
                                      0, 3)
                end
            end
        end

        for idx, item in pairs(snapshot.champs_) do
            if (item.is_visible_ or item.is_alive_) then
                world_pos = item.pos_
                screen_pos = snapshot:WorldToScreen(world_pos)
                if (snapshot:IsScreenPointOnScreen(screen_pos)) then

                    if (item:IsEnemyTo(snapshot:GetPlayer())) then

                        snapshot:DrawText(
                            Vec2(screen_pos.x_ + 80, screen_pos.y_ + 80),
                            "Enemy Hero  Health=" .. item.health_ ..
                                ",AttachRange=" .. item.atk_range_,
                            Color:BROWN())

                        snapshot:DrawCircle(Vec2(screen_pos.x_, screen_pos.y_),
                                            item.atk_range_, 0, 3, Color:BROWN())

                        snapshot:DrawCircle(Vec2(screen_pos.x_, screen_pos.y_),
                                            item:GetAcquisitionRadius(), 0, 3,
                                            Color:BROWN())
                        snapshot:DrawCircle(Vec2(screen_pos.x_, screen_pos.y_),
                                            item:GetSelectionRadius(), 0, 3,
                                            Color:BROWN())
                        snapshot:DrawCircle(Vec2(screen_pos.x_, screen_pos.y_),
                                            item:GetPathingRadius(), 0, 3,
                                            Color:BROWN())

                        snapshot:DrawRect(
                            Vec4(screen_pos.x_ + 80, screen_pos.y_ + 80,
                                 screen_pos.x_ - 80, screen_pos.y_ - 80),
                            Color:BROWN(), 0, 3)
                    else
                        snapshot:DrawText(
                            Vec2(screen_pos.x_ + 80, screen_pos.y_ + 80),
                            "Hero  Health=" .. item.health_ .. ",AttachRange=" ..
                                item.atk_range_, Color:BLUE())

                        snapshot:DrawCircle(Vec2(screen_pos.x_, screen_pos.y_),
                                            item.atk_range_, 0, 3, Color:BLUE())

                        snapshot:DrawCircle(Vec2(screen_pos.x_, screen_pos.y_),
                                            item:GetAcquisitionRadius(), 0, 3,
                                            Color:BLUE())
                        snapshot:DrawCircle(Vec2(screen_pos.x_, screen_pos.y_),
                                            item:GetSelectionRadius(), 0, 3,
                                            Color:BLUE())
                        snapshot:DrawCircle(Vec2(screen_pos.x_, screen_pos.y_),
                                            item:GetPathingRadius(), 0, 3,
                                            Color:BLUE())

                        snapshot:DrawRect(
                            Vec4(screen_pos.x_ + 80, screen_pos.y_ + 80,
                                 screen_pos.x_ - 80, screen_pos.y_ - 80),
                            Color:BLUE(), 0, 3)
                    end
                end
            end
        end

        for idx, item in pairs(snapshot.missiles_) do
            if (item.is_visible_ or item.is_alive_) then
                world_pos = item.pos_
                screen_pos = snapshot:WorldToScreen(world_pos)
                if (snapshot:IsScreenPointOnScreen(screen_pos)) then

                    if (item:IsEnemyTo(snapshot:GetPlayer())) then

                        snapshot:DrawText(
                            Vec2(screen_pos.x_ + 110, screen_pos.y_ + 110),
                            "Enemy Missile  Health=" .. item.health_ ..
                                ",AttachRange=" .. item.atk_range_,
                            Color:WHITE())

                        snapshot:DrawCircle(Vec2(screen_pos.x_, screen_pos.y_),
                                            item.atk_range_, 0, 3, Color:WHITE())

                        snapshot:DrawCircle(Vec2(screen_pos.x_, screen_pos.y_),
                                            item:GetAcquisitionRadius(), 0, 3,
                                            Color:WHITE())
                        snapshot:DrawCircle(Vec2(screen_pos.x_, screen_pos.y_),
                                            item:GetSelectionRadius(), 0, 3,
                                            Color:WHITE())
                        snapshot:DrawCircle(Vec2(screen_pos.x_, screen_pos.y_),
                                            item:GetPathingRadius(), 0, 3,
                                            Color:WHITE())

                        snapshot:DrawRect(
                            Vec4(screen_pos.x_ + 110, screen_pos.y_ + 110,
                                 screen_pos.x_ - 110, screen_pos.y_ - 110),
                            Color:DARK_RED(), 0, 3)
                    else

                        snapshot:DrawText(
                            Vec2(screen_pos.x_ + 110, screen_pos.y_ + 110),
                            "Ally Missile  Health=" .. item.health_ ..
                                ",AttachRange=" .. item.atk_range_,
                            Color:DARK_GREEN())

                        snapshot:DrawCircle(Vec2(screen_pos.x_, screen_pos.y_),
                                            item.atk_range_, 0, 3,
                                            Color:DARK_GREEN())

                        snapshot:DrawCircle(Vec2(screen_pos.x_, screen_pos.y_),
                                            item:GetAcquisitionRadius(), 0, 3,
                                            Color:DARK_GREEN())
                        snapshot:DrawCircle(Vec2(screen_pos.x_, screen_pos.y_),
                                            item:GetSelectionRadius(), 0, 3,
                                            Color:DARK_GREEN())
                        snapshot:DrawCircle(Vec2(screen_pos.x_, screen_pos.y_),
                                            item:GetPathingRadius(), 0, 3,
                                            Color:DARK_GREEN())

                        snapshot:DrawRect(
                            Vec4(screen_pos.x_ + 110, screen_pos.y_ + 110,
                                 screen_pos.x_ - 110, screen_pos.y_ - 110),
                            Color:DARK_GREEN(), 0, 3)
                    end
                end
            end
        end

        for idx, item in pairs(snapshot.jungle_) do
            if (item.is_visible_ or item.is_alive_) then
                world_pos = item.pos_
                screen_pos = snapshot:WorldToScreen(world_pos)
                if (snapshot:IsScreenPointOnScreen(screen_pos)) then

                    snapshot:DrawText(Vec2(screen_pos.x_ + 100,
                                           screen_pos.y_ + 110),
                                      "Jungle  Health=" .. item.health_ ..
                                          ",AttachRange=" .. item.atk_range_,
                                      Color:ORANGE())

                    snapshot:DrawCircle(Vec2(screen_pos.x_, screen_pos.y_),
                                        item.atk_range_, 0, 3, Color:ORANGE())

                    snapshot:DrawCircle(Vec2(screen_pos.x_, screen_pos.y_),
                                        item:GetAcquisitionRadius(), 0, 3,
                                        Color:ORANGE())
                    snapshot:DrawCircle(Vec2(screen_pos.x_, screen_pos.y_),
                                        item:GetSelectionRadius(), 0, 3,
                                        Color:ORANGE())
                    snapshot:DrawCircle(Vec2(screen_pos.x_, screen_pos.y_),
                                        item:GetPathingRadius(), 0, 3,
                                        Color:ORANGE())

                    snapshot:DrawRect(Vec4(screen_pos.x_ + 100,
                                           screen_pos.y_ + 100,
                                           screen_pos.x_ - 100,
                                           screen_pos.y_ - 100), Color:ORANGE(),
                                      0, 3)
                end
            end
        end
    end

    for idx, item in pairs(snapshot.turrets_) do
        if (item.is_visible_ or item.is_alive_) then
            world_pos = item.pos_
            screen_pos = snapshot:WorldToScreen(world_pos)
            if (snapshot:IsScreenPointOnScreen(screen_pos)) then

                if (item:IsEnemyTo(snapshot:GetPlayer())) then

                    snapshot:DrawText(Vec2(screen_pos.x_ + 100,
                                           screen_pos.y_ + 110),
                                      "Enemy Turret  Health=" .. item.health_ ..
                                          ",AttachRange=" .. item.atk_range_,
                                      Color:YELLOW())

                    snapshot:DrawCircle(Vec2(screen_pos.x_, screen_pos.y_),
                                        item.atk_range_, 0, 3, Color:YELLOW())

                    snapshot:DrawCircle(Vec2(screen_pos.x_, screen_pos.y_),
                                        item:GetAcquisitionRadius(), 0, 3,
                                        Color:YELLOW())
                    snapshot:DrawCircle(Vec2(screen_pos.x_, screen_pos.y_),
                                        item:GetSelectionRadius(), 0, 3,
                                        Color:YELLOW())
                    snapshot:DrawCircle(Vec2(screen_pos.x_, screen_pos.y_),
                                        item:GetPathingRadius(), 0, 3,
                                        Color:YELLOW())

                    snapshot:DrawRect(Vec4(screen_pos.x_ + 100,
                                           screen_pos.y_ + 100,
                                           screen_pos.x_ - 100,
                                           screen_pos.y_ - 100), Color:YELLOW(),
                                      0, 3)
                else
                    snapshot:DrawText(Vec2(screen_pos.x_ + 100,
                                           screen_pos.y_ + 110),
                                      "Ally Turret  Health=" .. item.health_ ..
                                          ",AttachRange=" .. item.atk_range_,
                                      Color:DARK_YELLOW())

                    snapshot:DrawCircle(Vec2(screen_pos.x_, screen_pos.y_),
                                        item.atk_range_, 0, 3,
                                        Color:DARK_YELLOW())

                    snapshot:DrawCircle(Vec2(screen_pos.x_, screen_pos.y_),
                                        item:GetAcquisitionRadius(), 0, 3,
                                        Color:DARK_YELLOW())
                    snapshot:DrawCircle(Vec2(screen_pos.x_, screen_pos.y_),
                                        item:GetSelectionRadius(), 0, 3,
                                        Color:DARK_YELLOW())
                    snapshot:DrawCircle(Vec2(screen_pos.x_, screen_pos.y_),
                                        item:GetPathingRadius(), 0, 3,
                                        Color:DARK_YELLOW())

                    snapshot:DrawRect(Vec4(screen_pos.x_ + 100,
                                           screen_pos.y_ + 100,
                                           screen_pos.x_ - 100,
                                           screen_pos.y_ - 100),
                                      Color:DARK_YELLOW(), 0, 3)
                end
            end
        end
    end

    for idx, item in pairs(snapshot.others_) do
        if (item.is_visible_ or item.is_alive_) then
            world_pos = item.pos_
            screen_pos = snapshot:WorldToScreen(world_pos)
            if (snapshot:IsScreenPointOnScreen(screen_pos)) then

                if (item:IsEnemyTo(snapshot:GetPlayer())) then

                    snapshot:DrawText(Vec2(screen_pos.x_ + 60,
                                           screen_pos.y_ + 60),
                                      "Enemy Turret  Health=" .. item.health_ ..
                                          ",AttachRange=" .. item.atk_range_,
                                      Color:PURPLE())

                    snapshot:DrawCircle(Vec2(screen_pos.x_, screen_pos.y_),
                                        item:GetAcquisitionRadius(), 0, 3,
                                        Color:PURPLE())
                    snapshot:DrawCircle(Vec2(screen_pos.x_, screen_pos.y_),
                                        item:GetSelectionRadius(), 0, 3,
                                        Color:PURPLE())
                    snapshot:DrawCircle(Vec2(screen_pos.x_, screen_pos.y_),
                                        item:GetPathingRadius(), 0, 3,
                                        Color:PURPLE())

                    snapshot:DrawRect(Vec4(screen_pos.x_ + 60,
                                           screen_pos.y_ + 60,
                                           screen_pos.x_ - 60,
                                           screen_pos.y_ - 60), Color:PURPLE(),
                                      0, 3)
                else

                    snapshot:DrawText(Vec2(screen_pos.x_ + 60,
                                           screen_pos.y_ + 60),
                                      "Ally Buff  Health=" .. item.health_ ..
                                          ",AttachRange=" .. item.atk_range_,
                                      Color:CYAN())

                    snapshot:DrawCircle(Vec2(screen_pos.x_, screen_pos.y_),
                                        item:GetAcquisitionRadius(), 0, 3,
                                        Color:CYAN())
                    snapshot:DrawCircle(Vec2(screen_pos.x_, screen_pos.y_),
                                        item:GetSelectionRadius(), 0, 3,
                                        Color:CYAN())
                    snapshot:DrawCircle(Vec2(screen_pos.x_, screen_pos.y_),
                                        item:GetPathingRadius(), 0, 3,
                                        Color:CYAN())

                    snapshot:DrawRect(Vec4(screen_pos.x_ + 60,
                                           screen_pos.y_ + 60,
                                           screen_pos.x_ - 60,
                                           screen_pos.y_ - 60), Color:CYAN(), 0,
                                      3)
                end
            end
        end
    end
end
