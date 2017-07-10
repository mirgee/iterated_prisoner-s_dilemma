#include "../Player.h"

class Appeaser : public Player
{
public:
    Appeaser()
            : Player("Appeaser") {}

    Appeaser* clone() {
        return new Appeaser();
    }

private:
    Action strategy(Player* other_player)
    {
        if (this->history.empty() || other_player->history.empty()) {
            return C;
        }
        if (other_player->history.back() == D) {
            if (this->history.back() == C) return D;
            else return C;
        }
        return this->history.back();
    }
};
