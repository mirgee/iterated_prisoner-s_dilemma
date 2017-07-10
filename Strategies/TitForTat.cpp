#include "../Player.h"

class TitForTat : public Player
{
public:
    TitForTat()
            : Player("TitForTat") {}

    TitForTat* clone() {
        return new TitForTat();
    }

private:
    Action strategy(Player* other_player)
    {
        if (this->history.size() == 0) {
            return C;
        }
        if (other_player->history.back() == C) {
            return C;
        } else {
            return D;
        }
    }
};
