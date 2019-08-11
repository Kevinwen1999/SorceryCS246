CXX = g++
CXXFLAGS = -g -std=c++14 -Wall -MMD -Werror=vla
EXEC = sorcery
OBJECTS = air_elemental.o apprentice_summoner.o ascii_graphics.o aura_of_power.o banish.o blizzard.o Board.o bone_golem.o Card.o Collection.o dark_ritual.o Deck.o disenchant.o earth_elemental.o Enchantment.o enrage.o fire_elemental.o game.o giant_strength.o Grave.o Hand.o haste.o magic_fatigue.o main.o master_summoner.o Minion.o novice_pyromancer.o Observer.o Player.o potion_seller.o raise_dead.o recharge.o Ritual.o silence.o Spell.o standstill.o Subject.o unsummon.o

DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}

