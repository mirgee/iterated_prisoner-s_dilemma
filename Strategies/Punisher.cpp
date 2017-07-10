#include "../Player.h"

class Punisher : public Player {
public:
    Punisher()
        : Player("Punisher") {
        grudged = false;
        grudge_memory = 0;
    }

    Punisher* clone() {
        return new Punisher();
    }

private:
    int grudge_memory;
    bool grudged;

    Action strategy(Player* other_player)
    {
        // Forgot the grudge
        if (grudge_memory == 0) {
            grudged = false;
        }

        if (grudged) {
            grudge_memory--;
            return D;
        } else if (other_player->history.size() > 0 && other_player->history.back() == D){
            grudge_memory = (other_player->defections)*20 / other_player->history.size();
            grudged = true;
        }
        return C;
    }
};