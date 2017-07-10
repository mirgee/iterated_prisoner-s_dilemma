#include "Game.h"

Game::Game(const Payoff r, const Payoff p, const Payoff s, const Payoff t)
{
    gameMatrix.insert(std::pair<DecisionPair, PayoffPair>(DecisionPair(C, C), PayoffPair(r,r)));
    gameMatrix.insert(std::pair<DecisionPair, PayoffPair> (DecisionPair(D, D), PayoffPair(p,p)));
    gameMatrix.insert(std::pair<DecisionPair, PayoffPair> (DecisionPair(C, D), PayoffPair(s,t)));
    gameMatrix.insert(std::pair<DecisionPair, PayoffPair> (DecisionPair(D, C), PayoffPair(t,s)));
}

PayoffPair Game::score(const DecisionPair& dp)
{
    return gameMatrix.at(dp);
}