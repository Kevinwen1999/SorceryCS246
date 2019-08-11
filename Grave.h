//
//  Grave.h
//  Sorcery
//
//  Created by An Zhang on 2019-07-25.
//  Copyright © 2019 An Zhang. All rights reserved.
//

#ifndef SORCERY_GRAVE_H
#define SORCERY_GRAVE_H
#include"Collection.h"

class Graveyard : public Collection {
    
public:
    Graveyard();
    ~Graveyard();
    void push_card(int player, std::shared_ptr<Card> in) override;
    void pop_card(int player, std::shared_ptr<Card> out) override;
    void pop_top(int player);
    void notify(Subject<std::shared_ptr<Card>, Effect> &whoFrom) override;
};

#endif /* Grave_h */


