#pragma once

#include <state.h>
#include <EightPuzzle/eightpuzzleid.h>
#include <EightPuzzle/eightpuzzleoperator.h>
#include <iostream>

using namespace AI_Search;

namespace EightPuzzle {

class EightPuzzleState : public State
{
    std::pair<int, int> getBlankPiecePos();
    std::pair<int, int> getNumberPiecePos(std::string piece, std::string state);
public:
    EightPuzzleState(EightPuzzleId* id, EightPuzzleState* father, EightPuzzleOperator* fatherOperator, int depth, double cost);
    virtual ~EightPuzzleState();

    std::string toString();
    std::vector<Operator*> getAllowedOperators();
    void genHeuristic();
    std::vector<State*> genChilds(std::vector<Operator*> allowedOperators, Frontier* frontier);
    Id* applyOperator(Operator* op);
};

}
