#include <iostream>
#include <iomanip>
#include "Player.h"
#include "Evaluator.h"
#include "Strategies/Cooperator.cpp"
#include "Strategies/Defector.cpp"
#include "Strategies/Alternator.cpp"
#include "Strategies/Appeaser.cpp"
#include "Strategies/TitForTat.cpp"
#include "Strategies/Random.cpp"
#include "Strategies/Punisher.cpp"
#include "Strategies/Forgiver.cpp"


int main(){
//     Player* player1 = new TitForTat();
//     Player* player2 = new Random();
//     Match match(player1, player2, 500, 0.999, 0.3);
//     Game game(3,4,5,2);
//     match.play();
//     Evaluator evaluator(game, match);
//     std::cout << "Score for player1: " << evaluator.compute_final_score().first << std::endl;
//     std::cout << "Score for player2: " << evaluator.compute_final_score().second << std::endl;
//     delete player1, player2;

    std::vector<Player*> players {new Cooperator(), new Defector(), new Alternator(), new Appeaser(),
                                  new TitForTat(), new Random(0.5), new Punisher(), new Forgiver()};
    int rounds = 500;
    double gamma = 0.0001;
    double noise = 0.0001;
    int r = 3; int p = 1; int s = 0; int t = 5;
    Game* game = new Game(r,p,s,t);

    std::cout << "Enter maximum number of rounds: ";
    std::cin >> rounds;
    std::cout << "Enter the probability of ending after each round: ";
    std::cin >> gamma;
    std::cout << "Enter the probability of switching players' actions: ";
    std::cin >> noise;
    std::cout << "Payoff matrix: " << std::endl;
    std::cout << "\t Cooperate \t Defect" << std::endl;
    std::cout << "C \t (R,R) \t (S,T)" << std::endl;
    std::cout << "D \t (T,S) \t (P,P)" << std::endl;
    std::cout << "Enter payoffs T>R>P>S:" << std::endl;
    std::cout << "R: ";
    std::cin >> r;
    std::cout << "P: ";
    std::cin >> p;
    std::cout << "S: ";
    std::cin >> s;
    std::cout << "T: ";
    std::cin >> t;
    std::cout << std::endl;

    std::string rerun = "y";
    while (rerun == "y" || rerun == "Y") {
        std::cout << std::setw(10) << "PLAYER 1" << std::setw(15) << "PLAYER 2" << std::setw(10) << "SCORE 1"
                  << std::setw(10) << "SCORE 2" << std::setw(10) << "S/T 1" << std::setw(10) << "S/T 2"
                  << std::setw(12) << "C/D 1" << std::setw(12) << "C/D 2" << std::endl;
        std::cout << std::setfill('-') << std::setw(89) << '-' << std::endl << std::setfill(' ');
        Match *match;
        Evaluator *evaluator;
        for (Player *player1 : players) {
            for (Player *player2 : players) {
                if (player1 == player2) {
                    player2 = player1->clone();
                }
                std::cout << std::setw(10) << player1->name << std::setw(15) << player2->name;
                match = new Match(player1, player2, rounds, gamma, noise);
                match->play();
                evaluator = new Evaluator(game, match);
                std::cout << std::setw(10) << evaluator->compute_final_score().first;
                std::cout << std::setw(10) << evaluator->compute_final_score().second;
                std::cout << std::setw(10) << evaluator->compute_final_score_per_turn().first;
                std::cout << std::setw(10) << evaluator->compute_final_score_per_turn().second;
                std::cout << std::setw(10) << player1->cooperations << "/" << player1->defections;
                std::cout << "\t\t" << player2->cooperations << "/" << player2->defections;
                delete match, evaluator;
                std::cout << std::endl;
            }
        }
        std::cout << "Do you want to rerun with the same match parameters (Y/N)?: ";
        std::cin >> rerun;
    }

    return 0;
}