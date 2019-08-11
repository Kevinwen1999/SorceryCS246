//
// Created by Tim Liu on 2019-07-22.
//

#ifndef SORCERY_COLLECTION_H
#define SORCERY_COLLECTION_H

#include <vector>
#include <memory>
#include "Card.h"

class Collection : public Subject<std::shared_ptr<Card> , Effect>, public Observer<std::shared_ptr<Card>, Effect>, public std::enable_shared_from_this<Collection>{
protected:
    std::vector<std::shared_ptr<Card>> cardlist[2];
public:
    virtual void push_card(int player, std::shared_ptr<Card> in) = 0;
    virtual void pop_card(int player, std::shared_ptr<Card> out) = 0;
    int get_size(int player);
    std::vector<std::shared_ptr<Card>> get_list(int p);
};

#endif //SORCERY_COLLECTION_H


