#pragma once

#include <state.h>
#include <hanoitowerid.h>
#include <hanoitoweroperator.h>

namespace HanoiTower {

class HanoiTowerState : public AI_Search::State
{
public:
    HanoiTowerState(HanoiTowerId* id, HanoiTowerState* father, HanoiTowerOperator* fatherOperator, int depth, double cost);
    virtual ~HanoiTowerState();

    int getMaxSize() const;

    std::string toString();
protected:
    bool isFinal();
    std::vector<AI_Search::Operator*> getAllowedOperators();
    void genHeuristic();
    std::vector<State*> genChilds(std::vector<AI_Search::Operator*> allowedOperators, AI_Search::Frontier* frontier);
    AI_Search::Id* applyOperator(AI_Search::Operator* op);
};

}
