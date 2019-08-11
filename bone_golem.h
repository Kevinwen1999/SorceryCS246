//
//  bone_golem.h
//  Sorcery
//
//  Created by An Zhang on 2019-07-25.
//  Copyright © 2019 An Zhang. All rights reserved.
//

#ifndef SORCERY_BONE_GOLEM_H
#define SORCERY_BONE_GOLEM_H

#include "Minion.h"

class Bone_Golem : public Minion {
    
public:
    Bone_Golem(int player);
    void mlb(Subject<std::shared_ptr<Card>, Effect> &whoFrom) override;
};

#endif //SORCERY_EARTH_ELEMENTAL_H


