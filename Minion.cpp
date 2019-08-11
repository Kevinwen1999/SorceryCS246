//
// Created by Tim Liu on 2019-07-22.
//
#include "Minion.h"

Minion::Minion(int player, bool has) : Card(player, has) {
    type = "Minion";
}
/*
bool Minion::check_death() {
    if (get_defence() == 0) {
        setState(Effect{EffectType::MLC, 0, 0, CollectionType::GRAVE, 0});
        notifyObservers();
        return true;
    }
    else
        return false;
}
*/
void Minion::start_turn(Subject<std::shared_ptr<Card>, Effect> &whoFrom) {
    action_number = 1;
    action_performed = 0;
}


