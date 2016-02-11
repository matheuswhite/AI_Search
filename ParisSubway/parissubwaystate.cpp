#include "parissubwaystate.h"

ParisSubway::ParisSubwayState::ParisSubwayState(Id* id, ParisSubwayState* father, Operator* fatherOperator, int depth, double cost) : State(id, father, fatherOperator, depth, cost)
{
}

ParisSubway::ParisSubwayState::~ParisSubwayState()
{
}

std::string ParisSubway::ParisSubwayState::toString()
{

}

std::vector<Operator*> ParisSubway::ParisSubwayState::getAllowedOperators()
{

}

void ParisSubway::ParisSubwayState::genHeuristic()
{

}

std::vector<State*> ParisSubway::ParisSubwayState::genChilds(std::vector<Operator*> allowedOperators, Frontier* frontier)
{

}

Id* ParisSubway::ParisSubwayState::applyOperator(Operator* op)
{

}
