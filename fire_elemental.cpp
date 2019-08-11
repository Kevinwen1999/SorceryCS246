//
//  fire_elemental.cpp
//  Sorcery
//
//  Created by An Zhang on 2019-07-25.
//  Copyright © 2019 An Zhang. All rights reserved.
//
#include "fire_elemental.h"

Fire_Elemental::Fire_Elemental(int player) : Minion(player, false) {
    name = "Fire Elemental";
    description = "Whenever an opponent's minion enters play, deal 1 damage to it.";
    type = "Minion";
    cost = 2;
    attack = 2;
    defence = 2;
    has_active = false;
    activated_cost = 0;
    effect = Effect{EffectType::DMG, player, 0, CollectionType::BOARD, 1, 0, 2};
}

void Fire_Elemental::meb(Subject<std::shared_ptr<Card>, Effect> &whoFrom) {
    if (!has_ability()) return;
    if (whoFrom.getInfo()->get_player() == 1 - player) {
        setInfo(whoFrom.getInfo());
        setState(effect);
        notifyObservers();
    }
}


