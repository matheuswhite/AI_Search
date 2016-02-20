#pragma once

#include <string>
#include <map>

typedef short LineColor;

enum LINE_COLOR {
    NONE = 0,
    BLUE,
    GREEN,
    RED,
    YELLOW
};

struct StationInfo
{
   LineColor _lineColor1;
   LineColor _lineColor2;
   int _nearStations[4];

   StationInfo(LineColor linecolor1, LineColor lineColor2, std::initializer_list<int> inputs)
       : _lineColor1(linecolor1), _lineColor2(lineColor2)
   {
       int j = 0;
       for (auto i : inputs)
       {
           _nearStations[j] = i;
           j++;
       }
   }

   ~StationInfo()
   {
   }
};

class SubwayParisInfo
{
    static SubwayParisInfo* _instance;
    SubwayParisInfo();

    int _distanceTable[14][14];
    std::map<int, StationInfo*> _stationsInfos;

    void fillDistanceTable();
    void fillStationInfoMap();
public:
    static SubwayParisInfo* Instance();

    int getDistanceBetween(int first, int second) const;
    StationInfo* getStationInfo(int index);
    std::string getColorName(LineColor lineColor) const;
    LineColor getCommonLineColor(StationInfo* first, StationInfo* second) const;
};
