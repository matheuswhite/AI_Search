#pragma once

#include <operator.h>
#include <PriestNCannibal/priestncannibalid.h>

using namespace AI_Search;

class PriestNCannibalState;

class PriestNCannibalOperator : public Operator<PriestNCannibalId*>
{
    int _priestAmount;
    int _cannibalAmount;
    bool _isStartToGoal;
public:
    PriestNCannibalOperator(State<PriestNCannibalId*>* startState, int priestAmount, int cannibalAmount, bool isStartToGoal);
    virtual ~PriestNCannibalOperator();

    int getPriestAmount() const;
    int getCannibalAmount() const;
    bool isStartToGoal() const;
};
