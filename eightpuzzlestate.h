#pragma once

#include <state.h>
#include <eightpuzzleid.h>
#include <eightpuzzleoperator.h>

using namespace AI_Search;

namespace EightPuzzle {

class EightPuzzleState : public State
{
    std::pair<int, int> getBlankPiecePos();
public:
    EightPuzzleState(EightPuzzleId id, State* father, EightPuzzleOperator fatherOperator, int depth, double cost);
    virtual ~EightPuzzleState();

protected:
    bool isFinal();
    std::vector<EightPuzzleOperator> getAllowedOperators();
    std::vector<EightPuzzleState*> genChilds(std::vector<EightPuzzleOperator> allowedOperators);
    EightPuzzleId* applyOperator(EightPuzzleOperator op);
};

}
