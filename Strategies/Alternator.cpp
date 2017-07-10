#include "../Player.h"

class Alternator : public Player {
public:
    Alternator()
            : Player("Alternator"){}

    Alternator* clone() {
        return new Alternator();
    }

private:
    Action strategy(Player* other_player)
    {
        if (this->history.empty()) return C;
        if (this->history.back() == C) return D;
    }
};
