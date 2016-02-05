#pragma once

#include <state.h>
#include <eightpuzzleid.h>
#include <eightpuzzleoperator.h>
#include <iostream>

using namespace AI_Search;

namespace EightPuzzle {

class EightPuzzleState : public State
{
    std::pair<int, int> getBlankPiecePos();
public:
    EightPuzzleState(EightPuzzleId* id, EightPuzzleState* father, EightPuzzleOperator* fatherOperator, int depth, double cost);
    virtual ~EightPuzzleState();

    std::string toString();
protected:
    bool isFinal();
    std::vector<Operator*> getAllowedOperators();
    std::vector<State*> genChilds(std::vector<Operator*> allowedOperators, Frontier* frontier);
    Id* applyOperator(Operator* op);
};

}
