//
//  enrage.cpp
//  Sorcery
//
//  Created by An Zhang on 2019-07-25.
//  Copyright © 2019 An Zhang. All rights reserved.
//
#include "enrage.h"

Enrage::Enrage (int player) : Enchantment(player) { // *2 *2 enchantment
    name  = "Enrage";
    description = "";
    cost = 2;
    attack = -2;
    defence = -2;
}



