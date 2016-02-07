#pragma once

#include <id.h>
#include <hanoitower.h>
#include <hanoitoweroperator.h>

namespace HanoiTower {

class HanoiTowerId : public AI_Search::Id
{
    HanoiTower* _startTower;
    HanoiTower* _interTower;
    HanoiTower* _goalTower;
public:
    HanoiTowerId(HanoiTower* startTower, HanoiTower* interTower, HanoiTower* goalTower);
    virtual ~HanoiTowerId();

    HanoiTower* getStartTower() const;
    HanoiTower* getInterTower() const;
    HanoiTower* getGoalTower() const;
    HanoiTower* getTower(int pos) const;
    HanoiTowerId movePiece(int sourceTower, int targetTower);

    std::string toString();
    bool equal(Object* other);
};

}
