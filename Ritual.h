//
// Created by An Zhang on 2019-07-25.
//

#ifndef SORCERY_RITUAL_H
#define SORCERY_RITUAL_H
#include "Card.h"

class Ritual : public Card {
public:
    Ritual(int player);
    void take_dmg(Subject<std::shared_ptr<Card>, Effect> &whoFrom) override;
};

#endif //SORCERY_RITUAL_H


