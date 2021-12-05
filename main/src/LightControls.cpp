#include "LightControls.h"
#include "Constants.cpp"

void LightControls::ExecuteOnEachStrand(void (*pFunc)(int outletIndex), int pIntervalMilliseconds)
{
    int index;
    // Step through each outlet
    for (index = startIndex; index <= endIndex; index++)
    {
        pFunc(index);
        delay(pIntervalMilliseconds);
    }
}

void LightControls::Blink(int outletIndex, int iterations, int millisecondsDelay)
{
    for (int i = 0; i < iterations; i++)
    {
        digitalWrite(outletIndex, ON);
        delay(millisecondsDelay);
        digitalWrite(outletIndex, OFF);
        delay(millisecondsDelay);
    }
}

void LightControls::AllOn()
{
    LightControls::ExecuteOnEachStrand(On, 0);
}

void LightControls::AllOff()
{
    LightControls::ExecuteOnEachStrand(Off, 0);
}

void LightControls::On(int outletIndex)
{
    digitalWrite(outletIndex, ON);
}

void LightControls::Off(int outletIndex)
{
    digitalWrite(outletIndex, OFF);
}