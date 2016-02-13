#include "solver.h"

AI_Search::Solver::Solver(State* initialState, State* finalState, bool isVerbose, bool isStepByStep)
{
    _initialState = initialState;
    _frontier = new Frontier(initialState, searchAlgorithm);
    _finalState = finalState;
    _isVerbose = isVerbose || isStepByStep;
    _isStepByStep = isStepByStep;
}
AI_Search::Solver::~Solver()
{

}

AI_Search::State* AI_Search::Solver::getInitialState() const
{
    return _initialState;
}
AI_Search::State* AI_Search::Solver::getFinalState() const
{
    return _finalState;
}

std::vector<AI_Search::Operator*> AI_Search::Solver::getListOfOperators() const
{
    return _listOfOperators;
}

void AI_Search::Solver::solve()
{

}
