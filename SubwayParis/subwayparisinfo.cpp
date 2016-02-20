#include "subwayparisinfo.h"

SubwayParisInfo* SubwayParisInfo::_instance = nullptr;

SubwayParisInfo::SubwayParisInfo()
    : _distanceTable {{00,00,00,00,00,00,00,00,00,00,00,00,00,00},
                      {11,00,00,00,00,00,00,00,00,00,00,00,00,00},
                      {20, 9,00,00,00,00,00,00,00,00,00,00,00,00},
                      {27,16,07,00,00,00,00,00,00,00,00,00,00,00},
                      {40,29,20,13,00,00,00,00,00,00,00,00,00,00},
                      {43,32,22,16,03,00,00,00,00,00,00,00,00,00},
                      {39,28,19,12,02,04,00,00,00,00,00,00,00,00},
                      {28,19,15,13,21,23,22,00,00,00,00,00,00,00},
                      {18,11,10,13,25,28,25, 9,00,00,00,00,00,00},
                      {10,04,11,18,31,33,29,22,13,00,00,00,00,00},
                      {18,17,21,26,38,41,38,18,12,20,00,00,00,00},
                      {30,23,21,21,27,30,28,07,12,27,15,00,00,00},
                      {30,21,13,11,16,17,13,25,23,20,35,31,00,00},
                      {32,24,18,17,20,20,17,30,28,23,39,37,05,00}}
{
    fillDistanceTable();
    fillStationInfoMap();
}

SubwayParisInfo* SubwayParisInfo::Instance()
{
    if (_instance == nullptr)
    {
        _instance = new SubwayParisInfo();
    }
    return _instance;
}

void SubwayParisInfo::fillDistanceTable()
{
    for (int i = 0; i < 14; ++i)
    {
        for (int j = i; j < 14; ++j)
        {
            if (i != j)
            {
                _distanceTable[i][j] = _distanceTable[j][i];
            }
        }
    }
}

void SubwayParisInfo::fillStationInfoMap()
{
    _stationsInfos.insert(std::pair<int, StationInfo*>(1, new StationInfo(LINE_COLOR::BLUE, LINE_COLOR::NONE, {2,0,0,0})));
    _stationsInfos.insert(std::pair<int, StationInfo*>(2, new StationInfo(LINE_COLOR::BLUE, LINE_COLOR::YELLOW, {1,3,9,10})));
    _stationsInfos.insert(std::pair<int, StationInfo*>(3, new StationInfo(LINE_COLOR::BLUE, LINE_COLOR::RED, {2,4,9,13})));
    _stationsInfos.insert(std::pair<int, StationInfo*>(4, new StationInfo(LINE_COLOR::BLUE, LINE_COLOR::GREEN, {3,5,8,13})));
    _stationsInfos.insert(std::pair<int, StationInfo*>(5, new StationInfo(LINE_COLOR::BLUE, LINE_COLOR::YELLOW, {4,6,7,0})));
    _stationsInfos.insert(std::pair<int, StationInfo*>(6, new StationInfo(LINE_COLOR::BLUE, LINE_COLOR::NONE, {5,0,0,0})));
    _stationsInfos.insert(std::pair<int, StationInfo*>(7, new StationInfo(LINE_COLOR::YELLOW, LINE_COLOR::NONE, {5,0,0,0})));
    _stationsInfos.insert(std::pair<int, StationInfo*>(8, new StationInfo(LINE_COLOR::YELLOW, LINE_COLOR::GREEN, {4,9,5,12})));
    _stationsInfos.insert(std::pair<int, StationInfo*>(9, new StationInfo(LINE_COLOR::YELLOW, LINE_COLOR::RED, {2,3,8,11})));
    _stationsInfos.insert(std::pair<int, StationInfo*>(10, new StationInfo(LINE_COLOR::YELLOW, LINE_COLOR::NONE, {2,0,0,0})));
    _stationsInfos.insert(std::pair<int, StationInfo*>(11, new StationInfo(LINE_COLOR::RED, LINE_COLOR::NONE, {9,0,0,0})));
    _stationsInfos.insert(std::pair<int, StationInfo*>(12, new StationInfo(LINE_COLOR::GREEN, LINE_COLOR::NONE, {8,0,0,0})));
    _stationsInfos.insert(std::pair<int, StationInfo*>(13, new StationInfo(LINE_COLOR::RED, LINE_COLOR::GREEN, {3,4,14,0})));
    _stationsInfos.insert(std::pair<int, StationInfo*>(14, new StationInfo(LINE_COLOR::GREEN, LINE_COLOR::NONE, {13,0,0,0})));
}

int SubwayParisInfo::getDistanceBetween(int first, int second) const
{
    return _distanceTable[first-1][second-1];
}

StationInfo* SubwayParisInfo::getStationInfo(int index)
{
    StationInfo* info = nullptr;
    if (_stationsInfos.find(index) != _stationsInfos.end())
    {
        info = _stationsInfos.at(index);
    }
    return info;
}

std::string SubwayParisInfo::getColorName(LineColor lineColor) const
{
    std::string out = "";
    switch (lineColor) {
    case LINE_COLOR::NONE:
        out = "None";
        break;
    case LINE_COLOR::BLUE:
        out = "Blue";
        break;
    case LINE_COLOR::GREEN:
        out = "Green";
        break;
    case LINE_COLOR::RED:
        out = "Red";
        break;
    case LINE_COLOR::YELLOW:
        out = "Yellow";
        break;
    default:
        break;
    }

    return out;
}

LineColor SubwayParisInfo::getCommonLineColor(StationInfo* first, StationInfo* second) const
{
    LineColor out = LINE_COLOR::NONE;

    if (first->_lineColor1 == second->_lineColor1) out = first->_lineColor1;
    else if (first->_lineColor1 == second->_lineColor2) out = first->_lineColor1;
    else if (first->_lineColor2 == second->_lineColor1) out = first->_lineColor2;
    else if (first->_lineColor2 == second->_lineColor2) out = first->_lineColor2;

    return out;
}
