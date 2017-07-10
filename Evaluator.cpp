#include <iostream>
#include "Evaluator.h"
#include "Match.h"

Evaluator::Evaluator(Game* game, Match* match)
: game(game) {
    interactions = match->match_results.rounds_results;
}

std::vector<PayoffPair> Evaluator::compute_scores()
{
    for (DecisionPair dp : interactions)
    {
        scores.push_back(game->score(dp));
    }

    return scores;
}

PayoffPair Evaluator::compute_final_score()
{
    if (scores.size() == 0)
    {
        compute_scores();
    }

    Payoff final_score_player1 = 0;
    Payoff final_score_player2 = 0;

    for (PayoffPair score : scores)
    {
        final_score_player1 += score.first;
        final_score_player2 += score.second;
    }

    final_score = PayoffPair(final_score_player1, final_score_player2);

    return final_score;
};

PayoffPair Evaluator::compute_final_score_per_turn()
{
    if (!final_score.first && !final_score.second)
    {
        compute_final_score();
    }

    if (scores.size() == 0) return PayoffPair(0,0);

    return PayoffPair((double)final_score.first / scores.size(), (double)final_score.second / scores.size());
}