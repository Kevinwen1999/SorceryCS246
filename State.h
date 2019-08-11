//
// Created by Tim Liu on 2019-07-22.
//

#ifndef SORCERY_STATE_H
#define SORCERY_STATE_H

enum class EffectType {SOT, EOT, MEC, MLC, DMG, BUF, MOV, DEC, SUM, NON, RES};
enum class CollectionType {DECK, BOARD, GRAVE, HAND};
struct Effect {
    EffectType type;
    int player;
    int target;
    CollectionType destination;
    int value1;
    int value2;
    int notified_type; // 0 - minion, 1 - ritual, 2 - collections, 3 - player
    int notified_player;
    Effect() = default;
    Effect(EffectType type, int player, int target, CollectionType destination, int value1 = 0, int value2 = 0, int notified_type = 0, int notified_player = 0) : type{type}, player{player}, target{target}, destination{destination}, value1{value1}, value2{value2}, notified_type{notified_type}, notified_player{notified_player} {};
};

#endif //SORCERY_STATE_H


