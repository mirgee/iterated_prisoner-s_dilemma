#ifndef IPD_MATCH_H
#define IPD_MATCH_H

#include "Player.h"
#include "Game.h"

struct MatchResults {
    std::vector<DecisionPair> rounds_results;
    Payoff score[2];
    std::vector<DecisionPair> history[2];
    StateDistribution state_distribution;
    PlayerIndex winner;
    // Many others to come
};

class Match
{
public:
    Match(Player *p1, Player *p2, int rounds_total = 500, float gamma = 1, float noise = 0);
    MatchResults& play();
    MatchResults match_results;

private:
    DecisionPair play_round();
    Player *p1, *p2;
    int rounds_total;
    int rounds_played;
    float gamma, noise;

    void add_noise(DecisionPair&);
};

#endif //IPD_MATCH_H
