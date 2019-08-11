//
//  giant_strength.cpp
//  Sorcery
//
//  Created by An Zhang on 2019-07-25.
//  Copyright © 2019 An Zhang. All rights reserved.
//
#include "giant_strength.h"

Giant_Strength::Giant_Strength (int player) : Enchantment(player) { // +2 +2 enchantment
    name  = "Giant Strength";
    description = "";
    cost = 1;
    attack = 2;
    defence = 2;
}


