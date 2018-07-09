# Iterated prisoner's dilemma simulator

This is a iterated prisoner's dilemma simulator. It enables the user to create custom strategies and let them clash in a tournament of iterated prisoner's dilemma game.

To build the project, it required to have CMake 3.5 or higher installed on your system. On Linux, this is simply taken care of by

``
sudo apt-get install cmake
``.

Then

``
cmake CMakeLists.txt
make
./ipd
``

will start the program.

The user is requested to enter desired number of rounds, the probability of ending the game after each round, probability of exchanging players' actions, and the payoff matrix. Then, the tournament is run and results are printed in the console. Example:

```
  PLAYER 1       PLAYER 2   SCORE 1   SCORE 2     S/T 1     S/T 2       C/D 1       C/D 2
-----------------------------------------------------------------------------------------
Cooperator     Cooperator       303       303         3         3       101/0	101/0
Cooperator       Defector         0       505         0         5       101/0	0/101
Cooperator     Alternator       153       403   1.51485    3.9901       101/0	51/50
Cooperator       Appeaser       303       303         3         3       101/0	101/0
Cooperator      TitForTat       303       303         3         3       101/0	101/0
Cooperator         Random       153       403   1.51485    3.9901       101/0	51/50
Cooperator       Punisher       303       303         3         3       101/0	101/0
Cooperator       Forgiver       303       303         3         3       101/0	101/0
```

To create custom strategy, simply implement a new class in the `Strategies/` folder. It has to implement `Action strategy(Player* other_player)` method, returning the player's response to other player's. The parameters to consider for the response can be e.g. current action and action history of either player's and their statistics, internal data structures, randomness, etc.
