#include "apprentice_summoner.h"

Apprentice_Summoner::Apprentice_Summoner(int player) : Minion(player, false) {
    name = "Apprentice Summoner";
    description = "Summon a 1/1 air elemental";
    type = "Minion";
    cost = 1;
    attack = 1;
    defence = 1;
    action_number = 1;
    action_performed = 0;
    has_active = true;
    activated_cost = 1;
    effect = Effect(EffectType::SUM, get_player(), 1, CollectionType::BOARD, 1, 1);
}


