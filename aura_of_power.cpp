#include "aura_of_power.h"

Aura_of_Power::Aura_of_Power(int player) : Ritual(player) {
    name = "Aura of Power";
    description = "Whenever a minion enters play under your control, it gains +1/+1";
    type = "Ritual";
    cost = 1;
    defence = 4;
    activated_cost = 1;
    effect = Effect(EffectType::BUF, player, 0, CollectionType::BOARD, 1, 1, 2);
}

void Aura_of_Power::meb(Subject<std::shared_ptr<Card>, Effect> &whoFrom) {
    if (get_defence() >= activated_cost && whoFrom.getInfo()->get_player() == player) {
        add_damage(activated_cost);
        setInfo(whoFrom.getInfo());
        setState(effect);
        notifyObservers();
    }
}


