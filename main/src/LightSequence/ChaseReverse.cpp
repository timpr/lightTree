#include "ChaseReverse.h"
#include "../LightControls.h"

ChaseReverse::ChaseReverse(int startIndex, int endIndex, int delayMilliseconds, int iterations)
{
    this->startIndex = startIndex;
    this->endIndex = endIndex;
    this->delayMs = delayMilliseconds;
    this->iterations = iterations;
    this->currentStrand = startIndex;
}

void ChaseReverse::Play()
{
    this->currentStrand = this->startIndex;

    for (int iteration = 0; iteration < this->iterations; iteration++)
    {
        int index;
        // Step through each outlet
        for (index = endIndex; index >= startIndex; index--)
        {
            ChaseReverse::MoveToStrand(index);
            delay(this->delayMs);
        }
    }
}

void ChaseReverse::MoveToStrand(int strandIndex)
{
    //Turn prior strand off
    if (strandIndex + 1 <= endIndex)
    {
        LightControls::Off(strandIndex + 1);
    }
    else
    {
        LightControls::Off(startIndex);
    }

    //Turn new strand on
    LightControls::On(strandIndex);
}