//
// Created by An Zhang on 2019-07-24.
//

#ifndef SORCERY_FIRE_ELEMENTAL_H
#define SORCERY_FIRE_ELEMENTAL_H
#include "Minion.h"

class Fire_Elemental : public Minion {

public:
    Fire_Elemental(int player);
    void meb(Subject<std::shared_ptr<Card>, Effect> &whoFrom) override;
};

#endif //SORCERY_FIRE_ELEMENTAL_H


