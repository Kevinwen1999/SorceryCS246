#include "earth_elemental.h"

Earth_Elemental::Earth_Elemental(int player) : Minion(player, false) {
    name = "Earth Elemental";
    description = "";
    type = "Minion";
    cost = 3;
    attack = 4;
    defence = 4;
    has_active = false;
    activated_cost = 0;
    effect = {EffectType::NON, player, 0, CollectionType::BOARD};
}


