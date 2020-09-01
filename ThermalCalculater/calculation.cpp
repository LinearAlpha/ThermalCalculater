#include "include/calculation.h"

// privste functions
// calcuates the difference of the temperature
float Calculation::delTmper()
{
    return tmperature[1] - tmperature[0];
}

// calculate the difference of the diameter
float Calculation::delDim()
{
    return diamter[1] - diamter[0];
}

// publiv functions
Calculation::Calculation(/* args */) {}
Calculation::~Calculation() {}

// setting  the private value of the temperature
// input array (num index 2)
void Calculation::setTemperature(float* tmper)
{
    *Calculation::tmperature = *tmper;
}

// setting the private value of the diameter
// input array (num index 2)
void Calculation::setDaim(float*diman)
{
    *Calculation::diamter = *diman;
}

// seetting extra values of the for the calcuation
void Calculation::extras(float flow, float c_p, float q_heat)
{
    Calculation::flow = flow;
    Calculation::c_p = c_p;
    Calculation::q_heat = q_heat;
}

// case calcualtion for the thick wall case
float Calculation::thickWall()
{
    float tmpUp = 4 * Calculation::flow * Calculation::c_p;
    float tmpDow = M_PI * Calculation::delDim() * Calculation::q_heat;
    return (tmpUp / tmpDow) * Calculation::delTmper();
}

// case calcualtion for the thick thin wall caseS
float Calculation::thinWall()
{
    float tmpUp = Calculation::flow * Calculation::c_p;
    float tmpDow = M_PI * Calculation::delDim() * Calculation::q_heat;
    return (tmpUp / tmpDow) * Calculation::delTmper();
}