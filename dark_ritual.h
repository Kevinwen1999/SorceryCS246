//
// Created by An Zhang on 2019-07-25.
//

#ifndef SORCERY_DARK_RITUAL_H
#define SORCERY_DARK_RITUAL_H
#include "Ritual.h"

class Dark_Ritual : public Ritual {

public:
    Dark_Ritual(int player);
    void start_turn(Subject<std::shared_ptr<Card>, Effect> &whoFrom) override;
};

#endif //SORCERY_DARK_RITUAL_H


