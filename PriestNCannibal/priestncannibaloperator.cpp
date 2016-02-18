#include "priestncannibaloperator.h"

PriestNCannibalOperator::PriestNCannibalOperator(State<PriestNCannibalId*>* startState, int priestAmount, int cannibalAmount, bool isStartToGoal)
    : Operator<PriestNCannibalId*>(startState), _priestAmount(priestAmount), _cannibalAmount(cannibalAmount), _isStartToGoal(isStartToGoal)
{
}

PriestNCannibalOperator::~PriestNCannibalOperator()
{
}

int PriestNCannibalOperator::getPriestAmount() const
{
    return _priestAmount;
}

int PriestNCannibalOperator::getCannibalAmount() const
{
    return _cannibalAmount;
}

bool PriestNCannibalOperator::isStartToGoal() const
{
    return _isStartToGoal;
}

std::string PriestNCannibalOperator::toString()
{
    return  std::to_string(_priestAmount) + " Priests and " + std::to_string(_cannibalAmount) + " Cannibals\nFrom "
            + (_isStartToGoal ? "Start margin" : "Goal margin") + " to " + (_isStartToGoal ? "Goal margin\n" : "Start margin\n");
}
