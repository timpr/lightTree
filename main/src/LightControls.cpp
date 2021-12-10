#include "LightControls.h"
#include "Constants.h"

void LightControls::ExecuteOnEachStrand(void (*pFunc)(int outletIndex), int pIntervalMilliseconds)
{
    LightControls::ExecuteOnStrands(pFunc, startIndex, endIndex, pIntervalMilliseconds);
}

void LightControls::ExecuteOnStrands(void (*pFunc)(int outletIndex), int pStartIndex, int pEndIndex, int pIntervalMilliseconds)
{
    int index;
    // Step through each outlet
    for (index = pStartIndex; index <= pEndIndex; index++)
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

void LightControls::TreeOn()
{
    LightControls::ExecuteOnStrands(On, treeStartIndex, treeEndIndex, 0);
}

void LightControls::TreeOff()
{
    LightControls::ExecuteOnStrands(Off, treeStartIndex, treeEndIndex, 0);
}

void LightControls::DecorOn()
{
    LightControls::ExecuteOnStrands(On, decorStartIndex, decorEndIndex, 0);
}

void LightControls::DecorOff()
{
    LightControls::ExecuteOnStrands(Off, decorStartIndex, decorEndIndex, 0);
}

void LightControls::On(int outletIndex)
{
    digitalWrite(outletIndex, ON);
}

void LightControls::Off(int outletIndex)
{
    digitalWrite(outletIndex, OFF);
}