#ifndef IPD_GAME_H
#define IPD_GAME_H

#include <tuple>
#include <map>

enum Action
{
    C,
    D
};

typedef float Payoff;
typedef std::pair<Action,Action> DecisionPair;
typedef std::pair<Payoff, Payoff> PayoffPair;

class Game
{
public:
    Game(const Payoff r, const Payoff p, const Payoff s, const Payoff t);

    PayoffPair score(const DecisionPair&);

    //~Game();

private:
    std::map<DecisionPair, PayoffPair> gameMatrix;
};

#endif //IPD_GAME_H
