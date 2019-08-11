//
//  novice_pyromancer.cpp
//  Sorcery
//
//  Created by An Zhang on 2019-07-25.
//  Copyright © 2019 An Zhang. All rights reserved.
//
#include "novice_pyromancer.h"

Novice_Pyromancer::Novice_Pyromancer(int player) : Minion(player, true) {
    name = "Novice Pyromancer";
    description = "Deal 1 damage to target minion";
    type = "Minion";
    cost = 1;
    attack = 0;
    defence = 1;
    action_number = 0;
    action_performed = 0;
    has_active = true;
    activated_cost = 1;
    effect = Effect(EffectType::DMG, player, 0, CollectionType::BOARD, 1);
}


