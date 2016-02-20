#include "subwayparisstate.h"

SubwayParisState::SubwayParisState(int id, SubwayParisState* father, SubwayParisOperator* fatherOperator, int depth, double cost, int goalStateId)
    : State<int>(id, father, fatherOperator, depth, cost), _goalStateId(goalStateId)
{
    _info = SubwayParisInfo::Instance()->getStationInfo(id);
}

SubwayParisState::~SubwayParisState()
{
}

StationInfo* SubwayParisState::getStattionInfo() const
{
    return _info;
}

std::string SubwayParisState::toString()
{
    return "E" + std::to_string(getId());
}

void SubwayParisState::genHeuristic()
{
    _heuristic = SubwayParisInfo::Instance()->getDistanceBetween(getId(), _goalStateId);
}

std::vector<Operator<int>*> SubwayParisState::getAllowedOperators()
{
    std::vector<Operator<int>*> output;
    SubwayParisOperator* fatherOp = dynamic_cast<SubwayParisOperator*>(getFatherOperator());
    SubwayParisOperator* op = nullptr;
    StationInfo* nearStateInfo = nullptr;
    LineColor commonLineColor = LINE_COLOR::NONE;
    int distance = 0;

    for (int i = 0; i < 4; ++i)
    {
        if (_info->_nearStations[i] != 0)
        {
            nearStateInfo = SubwayParisInfo::Instance()->getStationInfo(_info->_nearStations[i]);
            commonLineColor = SubwayParisInfo::Instance()->getCommonLineColor(_info, nearStateInfo);
            distance = SubwayParisInfo::Instance()->getDistanceBetween(getId(), _info->_nearStations[i]);

            if (fatherOp->getLineColor() == LINE_COLOR::NONE)
            {
                op = new SubwayParisOperator(this, distance*2, commonLineColor);
            }
            else
            {
                op = new SubwayParisOperator(this, (distance*2) + (commonLineColor != fatherOp->getLineColor() ? 4 : 0), commonLineColor);
            }

            op->setTargetState(new SubwayParisState(_info->_nearStations[i], this, op, getDepth() + 1, op->getTime(), _goalStateId));

            output.push_back(op);
        }
    }

    return output;
}

std::vector<State<int>*> SubwayParisState::genChilds(std::vector<Operator<int>*> allowedOperators)
{
    std::vector<State<int>*> childs;

    for (int var = 0; var < allowedOperators.size(); ++var)
    {
        SubwayParisOperator* op = dynamic_cast<SubwayParisOperator*>(allowedOperators[var]);

        if (op != nullptr) childs.push_back(op->getTargetState());
    }

    return childs;
}
