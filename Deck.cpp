#include "Deck.h"
#include "all_cards.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <utility>

Deck::Deck() {
    cards_left = 0;
}

Deck::~Deck() {}

void Deck::load_deck(std::string filename, int num) {
    std::string cardname;
    std::ifstream ifs(filename);
    while(getline(ifs, cardname)) {
        if (cardname == "Air Elemental")
            push_card(num, std::make_shared<Air_Elemental>(num));
        if (cardname == "Earth Elemental")
            push_card(num, std::make_shared<Earth_Elemental>(num));
        if (cardname == "Bone Golem")
            push_card(num, std::make_shared<Bone_Golem>(num));
        if (cardname == "Apprentice Summoner")
            push_card(num, std::make_shared<Apprentice_Summoner>(num));
        if (cardname == "Fire Elemental")
            push_card(num, std::make_shared<Fire_Elemental>(num));
        if (cardname == "Master Summoner")
            push_card(num, std::make_shared<Master_Summoner>(num));
        if (cardname == "Novice Pyromancer")
            push_card(num, std::make_shared<Novice_Pyromancer>(num));
        if (cardname == "Potion Seller")
            push_card(num, std::make_shared<Potion_Seller>(num));
        if (cardname == "Silence")
            push_card(num, std::make_shared<Silence>(num));
        if (cardname == "Giant Strength")
            push_card(num, std::make_shared<Giant_Strength>(num));
        if (cardname == "Magic Fatigue")
            push_card(num, std::make_shared<Magic_Fatigue>(num));
        if (cardname == "Haste")
            push_card(num, std::make_shared<Haste>(num));
        if (cardname == "Enrage")
            push_card(num, std::make_shared<Enrage>(num));
        if (cardname == "Dark Ritual")
            push_card(num, std::make_shared<Dark_Ritual>(num));
        if (cardname == "Aura of Power")
            push_card(num, std::make_shared<Aura_of_Power>(num));
        if (cardname == "Standstill")
            push_card(num, std::make_shared<Standstill>(num));
        if (cardname == "Raise Dead")
            push_card(num, std::make_shared<Raise_Dead>(num));
        if (cardname == "Recharge")
            push_card(num, std::make_shared<Recharge>(num));
        if (cardname == "Banish")
            push_card(num, std::make_shared<Banish>(num));
        if (cardname == "Blizzard")
            push_card(num, std::make_shared<Blizzard>(num));
        if (cardname == "Disenchant")
            push_card(num, std::make_shared<Disenchant>(num));
        if (cardname == "Unsummon")
            push_card(num, std::make_shared<Unsummon>(num));
    }
}

void Deck::push_card(int player, std::shared_ptr<Card> in) {
    cardlist[player].emplace_back(in);
    cards_left ++;
}

void Deck::pop_card(int player, std::shared_ptr<Card> out) {
    cardlist[player].pop_back();
}

void Deck::pop_top(int player) {
    setState(Effect(EffectType::MLC, player, 0, CollectionType::HAND, 0, 0, 2));
    setInfo(cardlist[player].back());
    notifyObservers();
    cardlist[player].pop_back();
}

void Deck::notify(Subject<std::shared_ptr<Card>, Effect> &whoFrom) {}

void Deck::shuffle() {
    srand(time(0));
    for (int i = 0; i < 100; ++ i) {
        int random_1 = rand() % get_list(0).size();
        int random_2 = rand() % get_list(0).size();
        std::swap(cardlist[0][random_1], cardlist[0][random_2]);
    }
    
    for (int i = 0; i < 100; ++ i) {
        srand(time(nullptr));
        int random_1 = rand() % get_list(1).size();
        srand(time(nullptr));
        int random_2 = rand() % get_list(1).size();
        std::swap(cardlist[1][random_1], cardlist[1][random_2]);
    }
}


