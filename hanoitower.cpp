#include "hanoitower.h"

HanoiTower::HanoiTower::HanoiTower(int maxSize)
{
    _maxSize = maxSize;
    _tower = new int[maxSize];
    _top = 0;
}

HanoiTower::HanoiTower::~HanoiTower()
{
    delete _tower;
}

int HanoiTower::HanoiTower::pop()
{
    int output = 0;
    if (_top > 0)
    {
        output = _tower[_top];
        _tower[_top] = 0;
        _top--;
    }
    return output;
}

void HanoiTower::HanoiTower::push(int value)
{
    if (_top < _maxSize)
    {
        _tower[_top] = value;
        _top++;
    }
}

int HanoiTower::HanoiTower::seek() const
{
    int output = 0;
    if (_top > 0)
    {
        output = _tower[_top];
    }
    return output;
}

unsigned int HanoiTower::HanoiTower::getSize() const
{
    return _top + 1;
}

unsigned int HanoiTower::HanoiTower::getMaxSize() const
{
    return _maxSize;
}

std::string HanoiTower::HanoiTower::toString()
{
    for (int var = 0; var < _top + 1; ++var)
    {
        std::cout << "|" <<_tower[var] << "|" << std::endl;
    }
}

bool HanoiTower::HanoiTower::equal(Object* other)
{
    HanoiTower tower = *dynamic_cast<HanoiTower*>(other);
    if (dynamic_cast<HanoiTower*>(other) != nullptr && _top + 1 == tower.getSize())
    {
        for (int var = _top; var >= 0; --var)
        {
            if (_tower[var] != tower.pop())
                return false;
        }
    }
    else
    {
        return false;
    }
    return true;
}
