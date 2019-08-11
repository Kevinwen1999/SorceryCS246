
//
//  standstill.cpp
//  Sorcery
//
//  Created by An Zhang on 2019-07-25.
//  Copyright © 2019 An Zhang. All rights reserved.
//
#include "standstill.h"

Standstill::Standstill (int player) : Ritual(player) {
    name = "Standstill";
    description = "Whenever a minion enters play, destroy it";
    type = "Ritual";
    cost = 3;
    defence = 4;
    activated_cost = 2;
    effect = Effect(EffectType::MOV, player, 0, CollectionType::GRAVE, 0, 0, 2);
}

void Standstill::meb(Subject<std::shared_ptr<Card>, Effect> &whoFrom) {
    if (get_defence() >= activated_cost) {
        add_damage(activated_cost);
        setInfo(whoFrom.getInfo());
        setState(effect);
        notifyObservers();
    }
}


