#include <iostream>
#include "Match.h"

Match::Match(Player *p1, Player *p2, int rounds_total, float gamma, float noise)
    :p1(p1), p2(p2), rounds_total(rounds_total), gamma(gamma), noise(noise)
{
    rounds_played=0;
}

MatchResults& Match::play()
{
    p1->reset();
    p2->reset();

    double p_continue = 1;
    std::vector<DecisionPair> rounds_results;
    DecisionPair round_result;
    MatchResults match_results;

    while (p_continue > gamma && rounds_played <= rounds_total)
    {
        srand(time(NULL)*(rounds_played+1));
        p_continue = ((double) rand()) / RAND_MAX;
        round_result = play_round();
        rounds_results.push_back(round_result);
        rounds_played++;
    }

    match_results = {};
    match_results.rounds_results = rounds_results;

    this->match_results = match_results;
    return match_results;
}

DecisionPair Match::play_round()
{
    Action a1 = p1->strategy(p2);
    Action a2 = p2->strategy(p1);
    DecisionPair result = DecisionPair(a1, a2);

    if (noise > 0)
        add_noise(result);

    p1->update(a1, a2);
    p2->update(a2, a1);
    return result;
}

void Match::add_noise(DecisionPair& dp)
{
    srand(time(NULL)*(rounds_played+2));
    double p_noise = ((double) rand()) / RAND_MAX;

    if (p_noise < noise)
    {
        dp = DecisionPair(dp.second, dp.first);
    }
}
