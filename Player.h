//
// Created by Tim Liu on 2019-07-26.
//

#ifndef CODES_PLAYER_H
#define CODES_PLAYER_H

#include <string>
#include "Card.h"


class Player : public Observer<std::shared_ptr<Card>, Effect> {
    std::string name;
    int health;
    int magic;
    int idx;
public:
    int getHealth();
    int getMagic();
    std::string getName();
    void setHealth(int n);
    void setMagic(int n);
    bool check_death();
    Player (std::string, int);
    void notify(Subject<std::shared_ptr<Card>, Effect> &whoFrom) override;
};


#endif //CODES_PLAYER_H


