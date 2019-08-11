//
// Created by Tim Liu on 2019-07-22.
//

#ifndef SORCERY_MINION_H
#define SORCERY_MINION_H


#include "Card.h"

class Minion : public Card {
public:
    Minion(int player, bool);
    virtual void start_turn(Subject<std::shared_ptr<Card>, Effect> &whoFrom) override;
};


#endif //SORCERY_MINION_H


