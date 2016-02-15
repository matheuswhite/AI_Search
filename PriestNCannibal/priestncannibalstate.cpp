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
    std::vector<Operator<PriestNCannibalId*>*> output;
    int size;
    int spa;
    int sca;
    int gpa;
    int gca;

    output.push_back(new PriestNCannibalOperator(this, 1, 0, true));
    output.push_back(new PriestNCannibalOperator(this, 1, 0, false));
    output.push_back(new PriestNCannibalOperator(this, 0, 1, true));
    output.push_back(new PriestNCannibalOperator(this, 0, 1, false));

    for (int i = 0; i <= 2; ++i) {
        output.push_back(new PriestNCannibalOperator(this, i, 2 - i, true));
        output.push_back(new PriestNCannibalOperator(this, i, 2 - i, false));
    }

    PriestNCannibalOperator* op;
    size = output.size();
    for (int var = 0; var < size; ++var)
    {
        spa = getId()->getStartPriestAmount() + output.at(var)->getPriestAmount() * (output.at(var)->isStartToGoal() ? -1 : 1);
        gpa = getId()->getGoalPriestAmount() + output.at(var)->getPriestAmount() * (output.at(var)->isStartToGoal() ? 1 : -1);
        sca = getId()->getStartCannibalAmount() + output.at(var)->getCannibalAmount() * (output.at(var)->isStartToGoal() ? -1 : 1);
        gca = getId()->getGoalCannibalAmount() + output.at(var)->getCannibalAmount() * (output.at(var)->isStartToGoal() ? 1 : -1);

        if (spa < sca || gpa < gca)
            output.erase(output.begin() + var);
    }

    return output;
}

std::vector<State<PriestNCannibalId*>*> PriestNCannibalState::genChilds(std::vector<Operator<PriestNCannibalId*>*> allowedOperators)
{

}
