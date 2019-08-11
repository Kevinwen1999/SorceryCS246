#ifndef SORCERY_DECK_H
#define SORCERY_DECK_H

#include "Collection.h"

class Deck : public Collection {
    int cards_left;
    
public:
    Deck();
    ~Deck();
    void load_deck(std::string filename, int num);
    void push_card(int player, std::shared_ptr<Card>) override;
    void pop_card(int player, std::shared_ptr<Card>) override;
    void pop_top(int player);
    void notify(Subject<std::shared_ptr<Card>, Effect> &whoFrom) override;
    void shuffle();
};



#endif /* Deck_h */


