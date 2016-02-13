#pragma once

#include <state.h>
#include <PriestNCannibal/priestncannibalid.h>
#include <PriestNCannibal/priestncannibaloperator.h>

using namespace AI_Search;

class PriestNCannibalState : public State<PriestNCannibalId*>
{
public:
    PriestNCannibalState(PriestNCannibalId* id, PriestNCannibalState* father, PriestNCannibalOperator* fatherOperator, int depth, double cost);
    virtual ~PriestNCannibalState();

    std::string toString();
    std::vector<Operator<PriestNCannibalId*>*> getAllowedOperators();
    std::vector<State<PriestNCannibalId*>*> genChilds(std::vector<Operator<PriestNCannibalId*>*> allowedOperators);
    void genHeuristic();
};
