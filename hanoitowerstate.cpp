#include "hanoitowerstate.h"

HanoiTower::HanoiTowerState::HanoiTowerState(HanoiTowerId* id, HanoiTowerState* father, HanoiTowerOperator* fatherOperator, int depth, double cost) : State(id, father, fatherOperator, depth, cost)
{
}

HanoiTower::HanoiTowerState::~HanoiTowerState()
{

}

int HanoiTower::HanoiTowerState::getMaxSize()
{
    HanoiTowerId* id = dynamic_cast<HanoiTowerId*>(_id);
    return id->getStartTower()->getMaxSize();
}

std::string HanoiTower::HanoiTowerState::toString()
{
    _id->toString();
}

bool HanoiTower::HanoiTowerState::isFinal()
{
    HanoiTowerId* id = dynamic_cast<HanoiTowerId*>(_id);
    HanoiTower* goalTower = new HanoiTower(getMaxSize());

    for (int var = getMaxSize(); var > 0; --var)
    {
        goalTower->push(var);
    }

    return goalTower->equal(id->getGoalTower());
}

std::vector<AI_Search::Operator*> HanoiTower::HanoiTowerState::getAllowedOperators()
{
    HanoiTowerId* id = dynamic_cast<HanoiTowerId*>(_id);
    std::vector<AI_Search::Operator*> output;

    for (int i = TowerPosition::START; i <= TowerPosition::GOAL; ++i)
    {
        for (int j = TowerPosition::START; j <= TowerPosition::GOAL; ++j)
        {
            if (i != j)
            {
                if (id->getTower(i)->getSize() > 0)
                {
                    output.push_back(new HanoiTowerOperator(i, j));
                }
            }
        }
    }

    return output;
}

void HanoiTower::HanoiTowerState::genHeuristic()
{
    _heuristic = 0;
}

std::vector<AI_Search::State*> HanoiTower::HanoiTowerState::genChilds(std::vector<AI_Search::Operator*> allowedOperators, AI_Search::Frontier* frontier)
{
    std::vector<State*> childs;

    for (int var = 0; var < allowedOperators.size(); ++var) {

        AI_Search::Operator* movement = allowedOperators[var];

        State* child = new HanoiTowerState(dynamic_cast<HanoiTowerId*>(applyOperator(movement)), this, dynamic_cast<HanoiTowerOperator*>(movement),getDepth() + 1, getCost() + 1);

        bool existInFrontier = false;

        for (State* s : frontier->getVisitedStates())
        {
            if (child->equal(s))
            {
                existInFrontier = true;
            }
        }

        if (!existInFrontier)
        {
            childs.push_back(child);
        }
    }

    return childs;
}

AI_Search::Id* HanoiTower::HanoiTowerState::applyOperator(AI_Search::Operator* op)
{
    HanoiTowerOperator* op2 = dynamic_cast<HanoiTowerOperator*>(op);
    HanoiTowerId* id = dynamic_cast<HanoiTowerId*>(_id);

    id->movePiece(op2->getSourceTower(), op2->getTargetTower());
}
