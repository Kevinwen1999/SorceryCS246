//
// Created by Tim Liu on 2019-07-22.
//

#ifndef SORCERY_OBSERVER_H
#define SORCERY_OBSERVER_H

template <typename InfoType, typename StateType> class Subject;


template <typename InfoType, typename StateType> class Observer {
public:
    virtual void notify(Subject<InfoType, StateType> &whoFrom) = 0; // pass the Subject that called the notify method
    virtual ~Observer() = default;
};


#endif //SORCERY_OBSERVER_H


