#pragma once

#include <object.h>

namespace AI_Search {

class Operator : public Object
{
public:
    Operator() {}
    virtual ~Operator() {}

    virtual std::string toString() = 0;
};

}
