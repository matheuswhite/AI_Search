#include "priestncannibalstate.h"

PriestNCannibalState::PriestNCannibalState(PriestNCannibalId* id, PriestNCannibalState* father, PriestNCannibalOperator* fatherOperator, int depth, double cost)
    : State<PriestNCannibalId*>(id, father, fatherOperator, depth, cost)
{
}

PriestNCannibalState::~PriestNCannibalState()
{
}

std::string PriestNCannibalState::toString()
{
    return getId()->toString();
}

std::vector<Operator<PriestNCannibalId*>*> PriestNCannibalState::getAllowedOperators()
{

}

std::vector<State<PriestNCannibalId*>*> PriestNCannibalState::genChilds(std::vector<Operator<PriestNCannibalId*>*> allowedOperators)
{

}

void PriestNCannibalState::genHeuristic()
{

}
