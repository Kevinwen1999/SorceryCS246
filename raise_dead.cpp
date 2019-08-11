//
//  raise_dead.cpp
//  Sorcery
//
//  Created by An Zhang on 2019-07-25.
//  Copyright © 2019 An Zhang. All rights reserved.
//
#include "raise_dead.h"

Raise_Dead::Raise_Dead(int player) : Spell(player, false) {
    name = "Raise_Dead";
    description = "Resurrect the top minion in your graveyard and set its defence to 1";
    type = "Spell";
    cost = 1;
    effect = {EffectType::RES, player, 0, CollectionType::BOARD, 0, 0, 2};
}


