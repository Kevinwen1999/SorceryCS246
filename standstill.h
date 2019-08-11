//
// Created by An Zhang on 2019-07-25.
//

#ifndef SORCERY_STANDSTILL_H
#define SORCERY_STANDSTILL_H
#include "Ritual.h"

class Standstill : public Ritual {

public:
    Standstill(int player);
    void meb(Subject<std::shared_ptr<Card>, Effect> &whoFrom) override;
};

#endif //SORCERY_STANDSTILL_H


