#include "hanoitowerid.h"

HanoiTower::HanoiTowerId::HanoiTowerId(HanoiTower* startTower, HanoiTower* interTower, HanoiTower* goalTower)
{
    _startTower = startTower;
    _interTower = interTower;
    _goalTower = goalTower;
}

HanoiTower::HanoiTowerId::~HanoiTowerId()
{
    delete _startTower;
    delete _interTower;
    delete _goalTower;
}

HanoiTower::HanoiTower* HanoiTower::HanoiTowerId::getStartTower() const
{
    return _startTower;
}

HanoiTower::HanoiTower* HanoiTower::HanoiTowerId::getInterTower() const
{
    return _interTower;
}

HanoiTower::HanoiTower* HanoiTower::HanoiTowerId::getGoalTower() const
{
    return _goalTower;
}

HanoiTower::HanoiTower* HanoiTower::HanoiTowerId::getTower(int pos) const
{
    HanoiTower* output = nullptr;

    switch (pos) {
    case TowerPosition::START:
        output = _startTower;
        break;
    case TowerPosition::INTER:
        output = _interTower;
        break;
    case TowerPosition::GOAL:
        output = _goalTower;
        break;
    default:
        break;
    }

    return output;
}

HanoiTower::HanoiTowerId HanoiTower::HanoiTowerId::movePiece(int sourceTower, int targetTower)
{
    int pieceSource = 0;
    switch (sourceTower) {
    case 1:
        pieceSource = _startTower->pop();
        break;
    case 2:
        pieceSource = _interTower->pop();
        break;
    case 3:
        pieceSource = _goalTower->pop();
        break;
    default:
        break;
    }

    switch (targetTower) {
    case 1:
        _startTower->push(pieceSource);
        break;
    case 2:
        _interTower->push(pieceSource);
        break;
    case 3:
        _goalTower->push(pieceSource);
        break;
    default:
        break;
    }

    return *this;
}

std::string HanoiTower::HanoiTowerId::toString()
{
    std::cout << std::endl;
    std::cout << "StartTower" << _startTower->toString() << std::endl;
    std::cout << "InterTower" << _interTower->toString() << std::endl;
    std::cout << "GoalTower" << _goalTower->toString() << std::endl;
    std::cout << std::endl;
}

bool HanoiTower::HanoiTowerId::equal(Object* other)
{
    HanoiTowerId* id = dynamic_cast<HanoiTowerId*>(other);

    return id != nullptr && _startTower->equal(id->getStartTower()) && _interTower->equal(id->getInterTower()) && _goalTower->equal(id->getGoalTower());
}
