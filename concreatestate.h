#pragma once

#include <ai_search.h>
#include <iostream>

using namespace AI_Search;

namespace EightPuzzle {

class ConcreateState : public State<std::string, std::string>
{
    std::pair<int, int> getBlankPiecePos();
public:
    ConcreateState(std::string id, State<std::string, std::string>* father, std::string fatherOperator, int depth, double cost);
    virtual ~ConcreateState();

    bool isFinal();
    std::vector<std::string> getAllowedOperators();
    std::vector<State<std::string, std::string>*> genChilds(std::vector<std::string> allowedOperators);
    std::string applyOperator(std::string op);
};

}
