//
// Created by Tim Liu on 2019-07-22.
//

#include "Collection.h"

int Collection::get_size(int player) {
    return cardlist[player].size();
}

std::vector<std::shared_ptr<Card>> Collection::get_list(int p) {
    return cardlist[p];
}


