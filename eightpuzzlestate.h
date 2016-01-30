#pragma once

#include <state.h>
#include <eightpuzzleid.h>
#include <eightpuzzleoperator.h>
#include <algorithm>

using namespace AI_Search;

namespace EightPuzzle {

class EightPuzzleState : public State
{
    std::pair<int, int> getBlankPiecePos();
public:
    EightPuzzleState(EightPuzzleId* id, State* father, EightPuzzleOperator* fatherOperator, int depth, double cost);
    virtual ~EightPuzzleState();

protected:
    bool isFinal();
    std::vector<Operator*> getAllowedOperators();
    std::vector<State*> genChilds(std::vector<Operator*> allowedOperators);
    Id* applyOperator(Operator* op);
};

}
