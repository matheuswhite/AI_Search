#pragma once

#include <string>

class Object
{
public:
    Object();
    virtual ~Object();

    virtual std::string toString() = 0;
    virtual bool equal(Object* other) = 0;
};
