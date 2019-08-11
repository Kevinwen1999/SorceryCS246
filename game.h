//
// Created by Tim Liu on 2019-07-26.
//

#ifndef CODES_GAME_H
#define CODES_GAME_H

#include "Deck.h"
#include "Grave.h"
#include "Board.h"
#include "Hand.h"
#include "Player.h"
#include <memory>
#include <string>



class Game : public Subject<std::shared_ptr<Card>, Effect>, public Observer<std::shared_ptr<Card>, Effect>, public std::enable_shared_from_this<Collection>{
    std::shared_ptr<Player> players[2];
    int CurrPlayer; // current player
    int OtherPlayer;
    std::shared_ptr<Deck> deck = std::make_shared<Deck>();
    std::shared_ptr<Board> board = std::make_shared<Board>();
    std::shared_ptr<Hand> hand = std::make_shared<Hand>();
    std::shared_ptr<Graveyard> grave = std::make_shared<Graveyard>();
    bool game_end;
    bool game_begin;
public:
    Game(std::string, std::string); // wait for discussion, use game to add or use main
    void init_deck(int player, std::string filename);
    void prettyprint();
    void move (std::shared_ptr<Collection> source, std::shared_ptr<Collection> dest, std::shared_ptr<Card> the_card);
    int getCurrPlayer();
    int getOtherPlayer();
    std::shared_ptr<Player> getPlayer1();
    std::shared_ptr<Player> getPlayer2();
    std::shared_ptr<Deck> getDeck();
    std::shared_ptr<Hand> getHand();
    std::shared_ptr<Board> getBoard();
    void draw();
    bool getEnd();
    bool getBegin();
    void Gamepush(std::shared_ptr<Collection> where, int who, std::shared_ptr<Card> c);
    void Gamepop(std::shared_ptr<Collection> where, int who, std::shared_ptr<Card> c);
    void startTurn();
    void endTurn();
    void MinionattackPlayer(int index_1);
    void MinionattackMinion(int index_1, int index_2);
    void PlayCard(int index_1, bool test = false, int player = -1, int index_2 = -1);
    void checkAbility(int index_1);
    void UseCard(int index_1, bool test = false, int player = -1, int index_2 = -1);
    void discard(int i);
    void InspectMinion(int index_1);
    void ShowHand();
    std::string getWinner();
    void notify(Subject<std::shared_ptr<Card>, Effect> &whoFrom);
    void init_game();
    void graphics_display();
};


#endif //CODES_GAME_H


