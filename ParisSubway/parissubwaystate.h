#pragma once

#include <state.h>

using namespace AI_Search;

namespace ParisSubway {

class ParisSubwayState : public State
{
public:
    ParisSubwayState(Id* id, ParisSubwayState* father, Operator* fatherOperator, int depth, double cost);
    virtual ~ParisSubwayState();

    std::string toString();
    std::vector<Operator*> getAllowedOperators();
    void genHeuristic();
    std::vector<State*> genChilds(std::vector<Operator*> allowedOperators, Frontier* frontier);
    Id* applyOperator(Operator* op);
};

}
