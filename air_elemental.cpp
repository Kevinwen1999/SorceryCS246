#include "air_elemental.h"

Air_Elemental::Air_Elemental(int player) : Minion(player, false) {
    name = "Air Elemental";
    description = "";
    type = "Minion";
    cost = 0;
    attack = 1;
    defence = 1;
    has_active = false;
    activated_cost = 0;
    effect = {EffectType::NON, player, 0, CollectionType::BOARD};
}


