#include "hanoitoweroperator.h"

HanoiTower::HanoiTowerOperator::HanoiTowerOperator(int sourceTower, int targetTower)
{
    _sourceTower = sourceTower;
    _targetTower = targetTower;
}

HanoiTower::HanoiTowerOperator::~HanoiTowerOperator()
{

}

int HanoiTower::HanoiTowerOperator::getSourceTower() const
{
    return _sourceTower;
}

int HanoiTower::HanoiTowerOperator::getTargetTower() const
{
    return _targetTower;
}

std::string HanoiTower::HanoiTowerOperator::translateIntToTowerPosition(int value)
{
    std::string output = "";
    switch (value) {
    case TowerPosition::START:
        output = "Start";
        break;
    case TowerPosition::INTER:
        output = "Inter";
        break;
    case TowerPosition::GOAL:
        output = "Goal";
        break;
    default:
        break;
    }

    return output;
}

std::string HanoiTower::HanoiTowerOperator::toString()
{
    std::cout << "From " << translateIntToTowerPosition(_sourceTower) << "Tower to " << translateIntToTowerPosition(_targetTower) << "Tower" << std::endl;
}

bool HanoiTower::HanoiTowerOperator::equal(Object* other)
{
    HanoiTowerOperator* op = dynamic_cast<HanoiTowerOperator*>(other);

    return op != nullptr && _sourceTower == op->getSourceTower() && _targetTower == op->getTargetTower();
}
