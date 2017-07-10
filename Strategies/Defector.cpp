#include "../Player.h"

class Defector : public Player {
public:
    Defector()
            : Player("Defector"){}

    Defector* clone() {
        return new Defector();
    }

private:
    Action strategy(Player* other_player)
    {
        return D;
    }
};