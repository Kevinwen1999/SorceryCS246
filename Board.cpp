//
// Created by kevinwen on 7/26/19.
//

#include "Board.h"
#include "all_cards.h"

Board::Board() {
    cur_player = 0;
}

Board::~Board() {
    for (int i = 0; i < 2; i++) {
        while (!cardlist[i].empty()) {
            // delete cardlist[i].back();
            cardlist[i].pop_back();
        }
        while (!ritual[i].empty()) {
            //delete ritual[i].back();
            ritual[i].pop_back();
        }
    }
}

void Board::push_card(int player, std::shared_ptr<Card> in) {
    if (in->get_type() == "Ritual") {
        if (!ritual[player].empty()) {
            // detach(ritual[player][0]);
            ritual[player][0]->set_belong(CollectionType::GRAVE);
            ritual[player].pop_back();
        }
        in->set_belong(CollectionType::BOARD);
        ritual[player].push_back(in);
        ritual[player][0]->attach(shared_from_this());
        attach(ritual[player][0]);
    } else {
        if (cardlist[player].size() == 5) {
            throw 9;
        }
        in->set_belong(CollectionType::BOARD);
        cardlist[player].emplace_back(in);
        int new_size = (int) cardlist[player].size();
        cardlist[player][new_size - 1]->attach(shared_from_this());
        attach(cardlist[player][new_size - 1]);
        if (in->get_type() == "Minion") {
            std::shared_ptr<Card> t = getInfo();
            Effect tt = getState();
            setInfo(in);
            setState(Effect(EffectType::MEC, player, new_size - 1, CollectionType::BOARD));
            notify_APNAP();
            setInfo(t);
            setState(tt);
        }
    }
}

void Board::pop_card(int place, std::shared_ptr<Card>out) {
    CollectionType where = place == 0 ? CollectionType::GRAVE : CollectionType::HAND;
    for (int player = 0; player < 2; player ++) {
        int i = 0;
        for (auto it = cardlist[player].begin(); it != cardlist[player].end(); it++, i++) {
            if (*it != out) continue;
            Effect tt = getState();
            std::shared_ptr<Card> t = getInfo();
            setInfo(out);
            setState(Effect(EffectType::MLC, player, i, where));
            notify_APNAP();
            // detach(*it);
            setState(tt);
            setInfo(t);
            out->set_belong(where);
            out->reset();
            cardlist[player].erase(it);
            return;
        }
        for (auto it = ritual[player].begin(); it != ritual[player].end(); it++) {
            if (*it != out) continue;
            // detach(*it);
            out->set_belong(where);
            ritual[player].erase(it);
            return;
        }
    }
}

void Board::attackPlayer(int player, int idx) {
    if (cardlist[player].size() < idx) {
        throw 7;
    }
    if (cardlist[player][idx - 1]->get_action_left() <= 0) {
        throw 11;
    }
    cardlist[player][idx - 1]->add_action();
    Effect tt = getState();
    setState(Effect(EffectType::DMG, 1 - player, 5, CollectionType::BOARD, cardlist[player][idx - 1]->get_attack(), 0, 3));
    notify_APNAP();
    setState(tt);
}

void Board::attackMinion(int player, int idx1, int idx2) {
    if (cardlist[player].size() < idx1) {
        throw 7;
    } else if (cardlist[1 - player].size() < idx2) {
        throw 7;
    }
    if (cardlist[player][idx1 - 1]->get_action_left() <= 0) {
        throw 11;
    }
    cardlist[player][idx1 - 1]->add_action();
    std::shared_ptr<Card> t = getInfo();
    Effect tt = getState();
    setInfo(cardlist[player][idx1 - 1]);
    int val1 = cardlist[1 - player][idx2 - 1]->get_attack(), val2 = cardlist[player][idx1 - 1]->get_attack();
    setState(Effect(EffectType::DMG, player, 0, CollectionType::BOARD, val1, 0, 0, player));
    //notifyObservers();
    notify_APNAP();
    setInfo(cardlist[1 - player][idx2 - 1]);
    setState(Effect(EffectType::DMG, 1 - player, 0, CollectionType::BOARD, val2, 0, 0, 1 - player));
    //notifyObservers();
    notify_APNAP();
    setInfo(t);
    setState(tt);
}

void Board::notify_APNAP() {
    setState(Effect(getState().type, getState().player, getState().target, getState().destination, getState().value1, getState().value2, 0, cur_player));
    notifyObservers();
    setState(Effect(getState().type, getState().player, getState().target, getState().destination, getState().value1, getState().value2, 1, cur_player));
    notifyObservers();
    setState(Effect(getState().type, getState().player, getState().target, getState().destination, getState().value1, getState().value2, 0, 1 - cur_player));
    notifyObservers();
    setState(Effect(getState().type, getState().player, getState().target, getState().destination, getState().value1, getState().value2, 1, 1 - cur_player));
    notifyObservers();
    setState(Effect(getState().type, getState().player, getState().target, getState().destination, getState().value1, getState().value2, 2));
    notifyObservers();
    setState(Effect(getState().type, getState().player, getState().target, getState().destination, getState().value1, getState().value2, 3));
    notifyObservers();
}

int Board::useCard(int player, int idx, int magic, bool test, int tar, int idx2) {
    if (cardlist[player].size() < idx) {
        throw 7;
    }
    if (cardlist[player][idx - 1]->get_action_left() <= 0) {
        throw 11;
    }
    if (!cardlist[player][idx - 1]->has_activated()) {
        throw 12;
    }
    if (!test && cardlist[player][idx - 1]->get_activated_cost() > magic) {
        throw 14;
    }
    int val = cardlist[player][idx - 1]->get_activated_cost();
    if (cardlist[player][idx - 1]->can_target()) {
        if (tar == -1) {
            throw 10;
        }
        if (cardlist[tar].size() < idx2) {
            throw 7;
        }
        Effect tt = getState();
        setState(cardlist[player][idx - 1]->get_effect());
        std::shared_ptr<Card> t = getInfo();
        setInfo(cardlist[tar][idx2 - 1]);
        notify_APNAP();
        setInfo(t);
        setState(tt);
    } else {
        if (tar != -1) {
            throw 8;
        }
        if (cardlist[player].size() >= 5) {
            throw 9;
        }
        for (int i = 0; i < cardlist[player][idx - 1]->get_effect().target && cardlist[player].size() < 5; i++) {
            push_card(player, std::make_shared<Air_Elemental>(player));
        }
    }
    return val;
}

void Board::notify(Subject<std::shared_ptr<Card>, Effect> &whoFrom) {
    if (whoFrom.getState().notified_type != 2) return;
    if (whoFrom.getState().type == EffectType::SOT) {
        Effect tt = getState();
        setState(whoFrom.getState());
        notify_APNAP();
        setState(tt);
    } else if (whoFrom.getState().type == EffectType::EOT) {
        Effect tt = getState();
        setState(whoFrom.getState());
        notify_APNAP();
        setState(tt);
        cur_player = 1 - cur_player;
    } else if (whoFrom.getState().type == EffectType::MLC) {
         pop_card(0, whoFrom.getInfo());
    } else if (whoFrom.getState().type == EffectType::DMG) {
        std::shared_ptr<Card> t = getInfo();
        Effect tt = getState();
        setInfo(whoFrom.getInfo());
        setState(whoFrom.getState());
        notify_APNAP();
        setInfo(t);
        setState(tt);
    } else if (whoFrom.getState().type == EffectType::BUF) {
        std::shared_ptr<Card> t = getInfo();
        Effect tt = getState();
        setInfo(whoFrom.getInfo());
        setState(whoFrom.getState());
        notify_APNAP();
        setInfo(t);
        setState(tt);
    } else if (whoFrom.getState().type == EffectType::MEC) {
        push_card(whoFrom.getInfo()->get_player(), whoFrom.getInfo());
    } else if (whoFrom.getState().type == EffectType::MOV) {
        if (whoFrom.getState().destination == CollectionType::BOARD) {
            std::shared_ptr<Card> c = whoFrom.getInfo();
            if (c->get_type() == "Minion") {
                if (whoFrom.getState().target != -1) {
                    throw 8;
                }
                if (cardlist[whoFrom.getState().player].size() >= 5) {
                    throw 9;
                }
                push_card(whoFrom.getState().player, c);
            } else if (c->get_type() == "Ritual") {
                if (whoFrom.getState().target != -1) {
                    throw 8;
                }
                push_card(whoFrom.getState().player, c);
            } else if (c->get_type() == "Spell") {
                if (c->can_target()) {
                    if (whoFrom.getState().target == -1) {
                        throw 10;
                    }
                    if (whoFrom.getState().value1 <= 5) {
                        if (cardlist[whoFrom.getState().target].size() < whoFrom.getState().value1) {
                            throw 7;
                        }
                        if (whoFrom.getState().type == EffectType::DEC) {
                            cardlist[whoFrom.getState().target][whoFrom.getState().value1 - 1]->dec();
                            return;
                        }
                        Effect tt = getState();
                        setState(c->get_effect());
                        std::shared_ptr<Card> t = getInfo();
                        setInfo(cardlist[whoFrom.getState().target][whoFrom.getState().value1 - 1]);
                        notify_APNAP();
                        setInfo(t);
                        setState(tt);
                    } else {
                        if (ritual[whoFrom.getState().target].size() < 1) {
                            throw 7;
                        }
                        Effect tt = getState();
                        setState(c->get_effect());
                        std::shared_ptr<Card> t = getInfo();
                        setInfo(ritual[whoFrom.getState().target][0]);
                        notify_APNAP();
                        setInfo(t);
                        setState(tt);
                    }
                } else {
                    if (whoFrom.getState().target != -1) {
                        throw 8;
                    }
                    Effect tt = getState();
                    setState(c->get_effect());
                    notify_APNAP();
                    setState(tt);
                }
            } else if (c->get_type() == "Enchantment") {
                if (whoFrom.getState().target == -1) {
                    throw 10;
                }
                if (cardlist[whoFrom.getState().target].size() < whoFrom.getState().value1) {
                    throw 7;
                }
                cardlist[whoFrom.getState().target][whoFrom.getState().value1 - 1]->add_enc(c);
            }
        } else if (whoFrom.getState().destination == CollectionType::GRAVE) {
            pop_card(0, whoFrom.getInfo());
        } else if (whoFrom.getState().destination == CollectionType::HAND) {
            pop_card(1, whoFrom.getInfo());
        }
    }
}


