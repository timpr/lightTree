#include "BaseLightSequence.h"

BaseLightSequence::BaseLightSequence(/* args */)
{
}

BaseLightSequence::~BaseLightSequence()
{
}

void BaseLightSequence::ExecuteOnEachStrand(void (*pFunc)(int outletIndex), int pIntervalMilliseconds)
{
    int index;
    // Step through each outlet
    for (index = startIndex; index <= endIndex; index++)
    {
        pFunc(index);
        delay(pIntervalMilliseconds);
    }
}

void BaseLightSequence::Blink(int outletIndex, int iterations, int millisecondsDelay)
{
    for (int i = 0; i < iterations; i++)
    {
        digitalWrite(outletIndex, BaseLightSequence::ON);
        delay(millisecondsDelay);
        digitalWrite(outletIndex, BaseLightSequence::OFF);
        delay(millisecondsDelay);
    }
}

void BaseLightSequence::AllOn()
{
    BaseLightSequence::ExecuteOnEachStrand(On, 0);
}

void BaseLightSequence::AllOff()
{
    BaseLightSequence::ExecuteOnEachStrand(Off, 0);
}

void BaseLightSequence::On(int outletIndex)
{
    digitalWrite(outletIndex, BaseLightSequence::ON);
}

void BaseLightSequence::Off(int outletIndex)
{
    digitalWrite(outletIndex, BaseLightSequence::OFF);
}