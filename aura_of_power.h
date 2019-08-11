//
// Created by An Zhang on 2019-07-25.
//

#ifndef SORCERY_AURA_OF_POWER_H
#define SORCERY_AURA_OF_POWER_H
#include "Ritual.h"

class Aura_of_Power : public Ritual {

public:
    Aura_of_Power(int player);
    void meb(Subject<std::shared_ptr<Card>, Effect> &whoFrom) override;
};

#endif //SORCERY_AURA_OF_POWER_H


