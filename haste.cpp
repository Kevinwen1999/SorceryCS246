//
//  Haste.cpp
//  Sorcery
//
//  Created by An Zhang on 2019-07-25.
//  Copyright © 2019 An Zhang. All rights reserved.
//
#include "haste.h"

Haste::Haste (int m) : Enchantment(m) {
    name  = "Haste";
    description = "Enchanted minion gains +1 action each turn";
    cost = 1;
    action_number = 1;
}


