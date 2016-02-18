#include "priestncannibalstate.h"

PriestNCannibalState::PriestNCannibalState(PriestNCannibalId* id, PriestNCannibalState* father, PriestNCannibalOperator* fatherOperator, int depth, double cost)
    : State<PriestNCannibalId*>(id, father, fatherOperator, depth, cost)
{
}

PriestNCannibalState::~PriestNCannibalState()
{
}

bool PriestNCannibalState::equal(Object* other)
{
    PriestNCannibalState* s = dynamic_cast<PriestNCannibalState*>(other);
    if (s != nullptr)
    {
        return getId()->equal(s->getId());
    }
    return false;
}

std::string PriestNCannibalState::toString()
{
    return getId()->toString();
}

std::vector<Operator<PriestNCannibalId*>*> PriestNCannibalState::getAllowedOperators()
{
    std::vector<Operator<PriestNCannibalId*>*> output;
    int size = 0;
    int spa = 0;
    int sca = 0;
    int gpa = 0;
    int gca = 0;
    bool isDeleted = false;

    output.push_back(new PriestNCannibalOperator(this, 1, 0, true));
    output.push_back(new PriestNCannibalOperator(this, 1, 0, false));
    output.push_back(new PriestNCannibalOperator(this, 0, 1, true));
    output.push_back(new PriestNCannibalOperator(this, 0, 1, false));

    for (int i = 0; i <= 2; ++i) {
        output.push_back(new PriestNCannibalOperator(this, i, 2 - i, true));
        output.push_back(new PriestNCannibalOperator(this, i, 2 - i, false));
    }

    size = output.size();
    for (int var = 0; var < size; ++var)
    {
        if (isDeleted)
        {
            //std::cout << var << "|" << size;
            var--;
            size--;
            isDeleted = false;
            //std::cout << " Deleted - " << var << "|" << size << std::endl;
            //std::getchar();
        }
        PriestNCannibalOperator* op = dynamic_cast<PriestNCannibalOperator*>(output.at(var));
        spa = getId()->getStartPriestAmount() + op->getPriestAmount() * (op->isStartToGoal() ? -1 : 1);
        gpa = getId()->getGoalPriestAmount() + op->getPriestAmount() * (op->isStartToGoal() ? 1 : -1);
        sca = getId()->getStartCannibalAmount() + op->getCannibalAmount() * (op->isStartToGoal() ? -1 : 1);
        gca = getId()->getGoalCannibalAmount() + op->getCannibalAmount() * (op->isStartToGoal() ? 1 : -1);

        if (spa < sca || gpa < gca || spa < 0 || sca < 0 || gpa < 0 || gca < 0)
        {
            output.erase(output.begin() + var);
            isDeleted = true;
        }
        else
        {
            PriestNCannibalId* id = new PriestNCannibalId(spa, sca, gpa, gca);
            op->setTargetState(new PriestNCannibalState(id, this, op, getDepth() + 1, getCost() + 1));
        }
    }

    return output;
}

std::vector<State<PriestNCannibalId*>*> PriestNCannibalState::genChilds(std::vector<Operator<PriestNCannibalId*>*> allowedOperators)
{
    std::vector<State<PriestNCannibalId*>*> childs;

    for (int var = 0; var < allowedOperators.size(); ++var)
    {
        PriestNCannibalOperator* op = dynamic_cast<PriestNCannibalOperator*>(allowedOperators[var]);

        childs.push_back(op->getTargetState());
    }

    return childs;
}
