#pragma once

#include <operator.h>
#include <frontier.h>

namespace AI_Search {

template <typename T>
class Solver
{
    Frontier<T>* _frontier;
    State<T>* _initialState;
    State<T>* _finalState;
    std::vector<Operator<T>*> _traceOfOperators;
    bool _isVerbose;
    bool _isStepByStep;
public:
    Solver(State<T>* initialState, State<T>* finalState, Frontier<T>* frontier, bool isVerbose = false, bool isStepByStep = false)
        : _initialState(initialState), _finalState(finalState), _isVerbose(isVerbose || isStepByStep),
          _isStepByStep(isStepByStep), _frontier(frontier)
    {
    }
    virtual ~Solver()
    {
    }

    State<T>* getInitialState() const
    {
        return _initialState;
    }
    State<T>* getFinalState() const
    {
        return _finalState;
    }
    std::vector<Operator<T>*> getTraceOfOperators() const
    {
        return _traceOfOperators;
    }

    void solveIterative(int numberOfSteps)
    {
        for (int var = 0; var < numberOfSteps; ++var) {
            solve();
        }
    }

    void solve()
    {
        _traceOfOperators.clear();

        while(!_frontier->isEmpty())
        {
            State<T>* firstState = _frontier->getFirstState();

            if (_isVerbose) std::cout << "!--" << firstState->toString() << std::endl;
            if (_isStepByStep) std::getchar();

            if (firstState->equal(_finalState))
            {
                _traceOfOperators = firstState->getTraceOfOperators();
                break;
            }

            _frontier->addStates(firstState->genChilds(firstState->getAllowedOperators()));

        }

        _frontier->clear();
    }
};

}
