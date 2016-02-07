#pragma once

#include <operator.h>

namespace HanoiTower {

enum TowerPosition {
    START = 1,
    INTER = 2,
    GOAL = 3
};

class HanoiTowerOperator : public AI_Search::Operator
{
    unsigned int _sourceTower;
    unsigned int _targetTower;

    std::string translateIntToTowerPosition(int value);
public:
    HanoiTowerOperator(int sourceTower, int targetTower);
    virtual ~HanoiTowerOperator();

    int getSourceTower() const;
    int getTargetTower() const;

    std::string toString();
    bool equal(Object* other);
};

}
