#include "Chase.h"
#include "../LightControls.h"

Chase::Chase(int startIndex, int endIndex, int delayMilliseconds, int iterations)
{
    this->startIndex = startIndex;
    this->endIndex = endIndex;
    this->delayMs = delayMilliseconds;
    this->iterations = iterations;
    this->currentStrand = startIndex;
}

void Chase::Play()
{
    this->currentStrand = this->startIndex;

    for (int iteration = 0; iteration < this->iterations; iteration++)
    {
        int index;
        // Step through each outlet
        for (index = startIndex; index <= endIndex; index++)
        {
            Chase::MoveToStrand(index);
            delay(this->delayMs);
        }
    }
}

bool Chase::Step()
{

    if (this->currentStrand < endIndex)
    {
        this->currentStrand = this->currentStrand + 1;
    }
    else
    {
        this->currentStrand = startIndex;
    }

    Chase::MoveToStrand(this->currentStrand);

    return true;
}

void Chase::MoveToStrand(int strandIndex)
{
    //Turn prior strand off
    if (strandIndex - 1 >= startIndex)
    {
        LightControls::Off(strandIndex - 1);
    }
    else
    {
        LightControls::Off(endIndex);
    }

    //Turn new strand on
    LightControls::On(strandIndex);
}