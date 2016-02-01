#pragma once

#include <string>

class Object
{
public:
    Object();
    virtual ~Object();

    virtual std::string toString() = 0;
};
