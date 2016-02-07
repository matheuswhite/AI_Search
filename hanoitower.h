#pragma once

#include <object.h>

namespace HanoiTower {

class HanoiTower : public Object
{
    int* _tower;
    unsigned int _top;
    unsigned int _maxSize;
public:
    HanoiTower(int maxSize);
    virtual ~HanoiTower();

    int pop();
    void push(int value);
    int seek() const;
    unsigned int getSize() const;
    unsigned int getMaxSize() const;

    std::string toString();
    bool equal(Object* other);
};

}
