#include "priestncannibalid.h"

PriestNCannibalId::PriestNCannibalId(int startPriestAmount, int startCannibalAmount, int goalPriestAmount, int goalCannibalAmount)
    : _startPriestAmount(startPriestAmount), _goalPriestAmount(goalPriestAmount), _startCannibalAmount(startCannibalAmount), _goalCannibalAmount(goalCannibalAmount)
{
}

PriestNCannibalId::~PriestNCannibalId()
{
}

std::string PriestNCannibalId::toString()
{
    return "\nStartMargin: " + std::to_string(_startPriestAmount) + " Priests and " + std::to_string(_startCannibalAmount) + " Cannibals\nGoalMargin: "
            + std::to_string(_goalPriestAmount) + " Priests and " + std::to_string(_goalCannibalAmount) + " Cannibals";
}

int PriestNCannibalId::getStartPriestAmount() const
{
    return _startPriestAmount;
}

int PriestNCannibalId::getGoalPriestAmount() const
{
    return _goalPriestAmount;
}

int PriestNCannibalId::getStartCannibalAmount() const
{
    return _startCannibalAmount;
}

int PriestNCannibalId::getGoalCannibalAmount() const
{
    return _goalCannibalAmount;
}

bool PriestNCannibalId::equal(Object* other)
{
    PriestNCannibalId* id = dynamic_cast<PriestNCannibalId*>(other);
    if (id != nullptr)
    {
        return _startPriestAmount == id->getStartPriestAmount() && _goalPriestAmount == id->getGoalPriestAmount()
                && _startCannibalAmount == id->getStartCannibalAmount() && _goalCannibalAmount == id->getGoalCannibalAmount();
    }
    return false;
}
