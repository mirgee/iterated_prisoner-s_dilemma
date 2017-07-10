#include "../Player.h"

class Random : public Player {
public:
    Random(double gamma = 0.5)
            : Player("Random"), gamma(gamma) {}

    Random* clone() {
        return new Random(gamma);
    }

private:
    double gamma;
    Action strategy(Player* other_player)
    {
        srand(time(NULL)*(this->history.size()+3));
        double p = ((double) rand()) / RAND_MAX;
        if (p < gamma) return C;
        else return D;
    }
};