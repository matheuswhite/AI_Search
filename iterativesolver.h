#pragma once

#include <solver.h>
#include <iterativefrontier.h>

namespace AI_Search {

class IterativeSolver : public Solver
{
    unsigned int _maxSteps;
    unsigned int _stepsMade;
public:
    IterativeSolver(State* initialState, std::function<bool(State*, State*)> searchAlgorithm, unsigned int maxSteps, bool isVerbose, bool isStepByStep);
    virtual ~IterativeSolver();

    std::vector<Operator*> solve();

    unsigned int getStepsMade() const;
};

}
