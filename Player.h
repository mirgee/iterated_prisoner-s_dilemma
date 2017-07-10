#ifndef IPD_PLAYER_H
#define IPD_PLAYER_H

#include <vector>
#include <unordered_map>
#include "Game.h"


enum PlayerIndex
{
    Player1,
    Player2
};

typedef std::map<DecisionPair, int> StateDistribution;
typedef std::pair<DecisionPair, Action> StateToAction;
typedef std::map<StateToAction, float> StateToActionDistribution;

class Player {
public:
    Player();
    std::string name;
    std::vector<Action> history;
    uint cooperations, defections;
    StateDistribution state_distribution;

    virtual Action strategy(Player*) = 0;
    void update(const Action&, const Action&);
    void reset();
    virtual Player* clone() = 0;

protected:
    Player(std::string);
};
#endif //IPD_PLAYER_H
