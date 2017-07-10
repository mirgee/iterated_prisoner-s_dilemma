#include "../Player.h"

class Cooperator : public Player {
public:
    Cooperator()
            : Player("Cooperator"){}

    Cooperator* clone() {
        return new Cooperator();
    }

private:
    Action strategy(Player* other_player)
    {
        return C;
    }
};
