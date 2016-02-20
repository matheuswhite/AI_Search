#pragma once

#include <operator.h>
#include <SubwayParis/subwayparisinfo.h>

using namespace AI_Search;

class SubwayParisOperator : public Operator<int>
{
    int _time;
    LineColor _lineColor;
public:
    SubwayParisOperator(State<int>* startState, int time, LineColor lineColor);
    virtual ~SubwayParisOperator();

    std::string toString();

    int getTime() const;
    LineColor getLineColor() const;
};
