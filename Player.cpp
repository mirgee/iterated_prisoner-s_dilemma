#include "Player.h"

Player::Player() {}

Player::Player(std::string name)
        : name(name) {
}

void Player::update(const Action& my_action, const Action& reply)
{
    history.push_back(my_action);

    if (my_action == C)
        cooperations++;
    else
        defections++;

    state_distribution[std::make_pair(my_action, reply)]++;
}

void Player::reset()
{
    cooperations = 0;
    defections = 0;
    history.clear();
    state_distribution.clear();
}
