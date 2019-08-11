//
//  Enchantment.cpp
//  Sorcery
//
//  Created by An Zhang on 2019-07-25.
//  Copyright © 2019 An Zhang. All rights reserved.
//
#include "Enchantment.h"

Enchantment::Enchantment (int player) : Card(player, true) {
    type = "Enchantment";
    attack = 0;
    defence = 0;
    action_number = 0;
    activated_cost = 0;
    can_use = true;
}


