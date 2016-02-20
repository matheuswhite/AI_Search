#include "subwayparisoperator.h"

SubwayParisOperator::SubwayParisOperator(State<int> *startState, int time, LineColor lineColor)
    : Operator<int>(startState), _time(time), _lineColor(lineColor)
{
}

SubwayParisOperator::~SubwayParisOperator()
{
}

int SubwayParisOperator::getTime() const
{
    return _time;
}

LineColor SubwayParisOperator::getLineColor() const
{
    return _lineColor;
}

std::string SubwayParisOperator::toString()
{
    return getStartState()->toString() + " to " + getTargetState()->toString() + "\twith "
            + std::to_string(_time) + "mim at " + SubwayParisInfo::Instance()->getColorName(_lineColor) + " Line\n";
}
