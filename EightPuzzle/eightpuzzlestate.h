#pragma once

#include <state.h>
#include <EightPuzzle/eightpuzzleoperator.h>

using namespace AI_Search;

namespace EightPuzzle {

class EightPuzzleState : public State<std::string>
{
    std::pair<int, int> getBlankPiecePos();
    std::pair<int, int> getNumberPiecePos(std::string piece, std::string state);
    std::string applyOperator(EightPuzzleOperator* op);
public:
    EightPuzzleState(std::string id, EightPuzzleState* father, EightPuzzleOperator* fatherOperator, int depth, double cost);
    virtual ~EightPuzzleState();

    std::string toString();
    std::vector<Operator<std::string>*> getAllowedOperators();
    void genHeuristic();
    std::vector<State<std::string>*> genChilds(std::vector<Operator<std::string>*> allowedOperators);
};

}
