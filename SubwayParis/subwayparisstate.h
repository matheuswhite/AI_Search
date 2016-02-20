#pragma once

#include <state.h>
#include <SubwayParis/subwayparisoperator.h>
#include <SubwayParis/subwayparisinfo.h>

using namespace AI_Search;

class SubwayParisState : public State<int>
{
    StationInfo* _info;
    int _goalStateId;
public:
    SubwayParisState(int id, SubwayParisState* father, SubwayParisOperator* fatherOperator, int depth, double cost, int goalStateId);
    virtual ~SubwayParisState();

    StationInfo *getStattionInfo() const;

    std::string toString();
    void genHeuristic();
    std::vector<Operator<int>*> getAllowedOperators();
    std::vector<State<int>*> genChilds(std::vector<Operator<int>*> allowedOperators);
};
