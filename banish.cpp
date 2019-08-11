//
//  banish.cpp
//  Sorcery
//
//  Created by An Zhang on 2019-07-25.
//  Copyright © 2019 An Zhang. All rights reserved.
//
#include "banish.h"

Banish::Banish(int player) : Spell(player, true) {
    name = "Banish";
    description = "Destroy target minion or ritual";
    type = "Spell";
    cost = 2;
    effect = Effect(EffectType::MOV, player, 0, CollectionType::GRAVE);
}



