#ifndef IPD_EVALUATOR_H
#define IPD_EVALUATOR_H


#include <vector>
#include "Game.h"
#include "Player.h"
#include "Match.h"

class Evaluator {
public:
    Evaluator(Game*, Match*);

    std::vector<PayoffPair> compute_scores();

    PayoffPair compute_final_score();

    PayoffPair compute_final_score_per_turn();

    PlayerIndex compute_winner_index();

    PayoffPair compute_cooperations();

    std::vector<float> compute_normalized_cooperation();

    StateDistribution compute_state_distribution();

    std::unordered_map<DecisionPair, float> compute_normalised_state_distribution();

    StateToActionDistribution compute_state_to_action_distributioni();

    StateToActionDistribution compute_normalised_state_to_action_distribution();

private:
    std::vector<DecisionPair> interactions;
    Game* game;
    std::vector<PayoffPair> scores;
    PayoffPair final_score;
};


#endif //IPD_EVALUATOR_H
