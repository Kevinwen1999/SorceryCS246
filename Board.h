//
//  Board.h
//  Sorcery
//
//  Created by An Zhang on 2019-07-25.
//  Copyright © 2019 An Zhang. All rights reserved.
//

#ifndef SORCERY_BOARD_H
#define SORCERY_BOARD_H

#include "Collection.h"

class Board : public Collection {
    std::vector<std::shared_ptr<Card>> ritual[2];
    int cur_player;

public:
    Board();
    ~Board();
    virtual void push_card(int player, std::shared_ptr<Card>in) override;
    virtual void pop_card(int player, std::shared_ptr<Card> out) override;
    void attackPlayer(int player, int idx);
    void attackMinion(int player, int idx1, int idx2);
    int useCard(int player, int idx, int magic, bool test, int tar = -1, int idx2 = -1);
    void notify_APNAP();
    virtual void notify(Subject<std::shared_ptr<Card>, Effect> &whoFrom) override;

    std::vector<std::shared_ptr<Card>> get_ritual(int p) {
        return ritual[p];
    }
};

#endif /* Board_h */


