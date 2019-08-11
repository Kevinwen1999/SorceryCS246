//
//  disenchant.cpp
//  Sorcery
//
//  Created by An Zhang on 2019-07-25.
//  Copyright © 2019 An Zhang. All rights reserved.
//
#include "disenchant.h"

Disenchant::Disenchant(int player) : Spell(player, true) {
    name = "Disenchant";
    description = "Destroy the top enchantment on target minion";
    type = "Spell";
    cost = 1;
    effect = Effect(EffectType::DEC, player, 0, CollectionType::BOARD);
}


