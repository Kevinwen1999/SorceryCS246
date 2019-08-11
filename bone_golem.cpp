//
//  bone_golem.cpp
//  Sorcery
//
//  Created by An Zhang on 2019-07-25.
//  Copyright © 2019 An Zhang. All rights reserved.
//
#include "bone_golem.h"

Bone_Golem::Bone_Golem(int player) : Minion(player, false) {
    name = "Bone Golem";
    description = "Gain +1/+1 whenever a minion leaves play.";
    type = "Minion";
    cost = 2;
    attack = 1;
    defence = 3;
    has_active = false;
    activated_cost = 0;
    effect = {EffectType::NON, player, 0, CollectionType::BOARD};
            //Effect(EffectType::MLC, get_player(), 0, CollectionType::BOARD, 1, 1);
}

void Bone_Golem::mlb(Subject<std::shared_ptr<Card>, Effect> &whoFrom) {
    if (has_ability()) {
        attack += 1;
        defence += 1;
    }
}



