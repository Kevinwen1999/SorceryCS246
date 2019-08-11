//
//  master_summoner.cpp
//  Sorcery
//
//  Created by An Zhang on 2019-07-25.
//  Copyright © 2019 An Zhang. All rights reserved.
//
#include "master_summoner.h"

Master_Summoner::Master_Summoner(int player) : Minion(player, false) {
    name = "Master Summoner";
    description = "Summon up to three 1/1 air elementals";
    type = "Minion";
    cost = 3;
    attack = 2;
    defence = 3;
    action_number = 0;
    action_performed = 0;
    has_active = true;
    activated_cost = 2;
    effect = Effect(EffectType::SUM, get_player(), 3, CollectionType::BOARD, 1, 1);
}


