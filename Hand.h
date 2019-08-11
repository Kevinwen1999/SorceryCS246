//
//  Hand.h
//  Sorcery
//
//  Created by An Zhang on 2019-07-25.
//  Copyright © 2019 An Zhang. All rights reserved.
//

#ifndef SORCERY_HAND_H
#define SORCERY_HAND_H
#include "Collection.h"

class Hand : public Collection {
    
public:
    Hand() = default;
    ~Hand();
    void push_card(int player, std::shared_ptr<Card> in) override;
    void pop_card(int player, std::shared_ptr<Card> out) override;
    int pop_selected(int player, int idx, int, int, int, bool = false);
    void discard(int player, int i);
    void notify(Subject<std::shared_ptr<Card>, Effect> &whoFrom) override;
};


#endif /* Hand_h */


