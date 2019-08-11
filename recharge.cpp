//
//  recharge.cpp
//  Sorcery
//
//  Created by An Zhang on 2019-07-25.
//  Copyright © 2019 An Zhang. All rights reserved.
//
#include "recharge.h"

Recharge::Recharge(int player) : Spell(player, false) {
    name = "Recharge";
    description = "Your ritual gains 3 charges.";
    type = "Spell";
    cost = 1;
    effect = Effect(EffectType::BUF, player, 4, CollectionType::BOARD, 0, 3, 2);
}


