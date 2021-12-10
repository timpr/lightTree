#include "DecorRotate.h"
#include "../Constants.h"
#include "../LightControls.h"

DecorRotate::DecorRotate(int delayMilliseconds, int iterations)
{
    this->delayMs = delayMilliseconds;
    this->iterations = iterations;
    this->currentStrand = decorStartIndex;
}

void DecorRotate::Play()
{
    this->currentStrand = decorStartIndex;

    for (int iteration = 0; iteration < this->iterations; iteration++)
    {
        for (int iOff = decorStartIndex; iOff <= decorEndIndex; iOff++)
        {
            Step();
            delay(this->delayMs);
            LightControls::On(this->lastStrand);
        }
    }
}

bool DecorRotate::Step()
{
    for (int i = decorStartIndex; i <= decorEndIndex; i++)
    {
        if (i == this->currentStrand)
        {
            LightControls::Off(i);
        }
        else
        {
            LightControls::On(i);
        }
    }

    this->lastStrand = this->currentStrand;
    if (this->currentStrand < decorEndIndex)
    {
        this->currentStrand = this->currentStrand + 1;
    }
    else
    {
        this->currentStrand = decorStartIndex;
    }

    return true;
}