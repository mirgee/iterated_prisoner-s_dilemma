cmake_minimum_required(VERSION 3.5)
project(ipd)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Main.cpp Player.h Match.h Game.cpp Game.h Match.cpp Player.cpp Evaluator.cpp Evaluator.h Strategies/TitForTat.cpp Strategies/Cooperator.cpp Strategies/Defector.cpp Strategies/Punisher.cpp Strategies/Random.cpp Strategies/Alternator.cpp Strategies/Appeaser.cpp Strategies/Forgiver.cpp)
add_executable(ipd ${SOURCE_FILES})