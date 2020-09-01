#ifndef _CALCULATION_
#define _CALCULATION_

#include "stdafx.h"
#include <cmath>

class Calculation
{
private:
    float tmperature[2];
    float diamter[2];
    float flow;
    float c_p;
    float q_heat;
    // calca for delta tmperature and dimention
    float delTmper();
    float delDim();

public:
    // dafaukt setting
    Calculation();
    ~Calculation();
    // setters
    void setTemperature(float* tmper);
    void setDaim(float*diman);
    void extras(float flow, float c_p, float q_heat);
    // calculation
    float thickWall();
    float thinWall();
};

#endif // !_ CALCULATION_