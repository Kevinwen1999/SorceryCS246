//
// Created by An Zhang on 2019-07-25.
//

#ifndef SORCERY_POTION_SELLER_H
#define SORCERY_POTION_SELLER_H
#include "Minion.h"

class Potion_Seller : public Minion {
    
public:
    Potion_Seller(int player);
    void end_turn(Subject<std::shared_ptr<Card>, Effect> &whoFrom) override;
};

#endif //SORCERY_POTION_SELLER_H


