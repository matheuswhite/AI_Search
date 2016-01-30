#pragma once

#include <state.h>

namespace AI_Search {

bool BFS_Algorithm(State* state1, State* state2)
{
    return state1->getDepth() < state2->getDepth();
}

bool DFS_Algorithm(State* state1, State* state2)
{
    return state1->getDepth() > state2->getDepth();
}

bool UniformCost_Algorithm(State* state1, State* state2)
{
    return state1->getCost() < state2->getCost();
}

}
