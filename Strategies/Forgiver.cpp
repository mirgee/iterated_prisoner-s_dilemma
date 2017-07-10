#include "../Player.h"

class Forgiver : public Player
{
public:
    Forgiver()
            : Player("Forgiver") {}

    Forgiver* clone() {
        return new Forgiver();
    }

private:
    Action strategy(Player* other_player)
    {
        if (other_player->defections > other_player->history.size() * 0.1)
            return D;
        return C;
    }
};
