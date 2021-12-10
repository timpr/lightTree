#include "TreeRotate.h"
#include "../Constants.h"
#include "../LightControls.h"

/** 
 * Will rotate AROUND the tree one strand at a time turning the strand off and then back on.
 * The delayMilliseconds is the amount of time each strand is off.
*/
TreeRotate::TreeRotate(int delayMilliseconds, int iterations)
{
    this->delayMs = delayMilliseconds;
    this->iterations = iterations;
    this->currentStrand = treeStartIndex;
}

void TreeRotate::Play()
{
    this->currentStrand = treeStartIndex;

    for (int iteration = 0; iteration < this->iterations; iteration++)
    {
        for (int iOff = treeStartIndex; iOff <= treeEndIndex; iOff++)
        {
            Step();
            delay(this->delayMs);
            LightControls::On(this->lastStrand);
        }
    }
}

bool TreeRotate::Step()
{
    for (int i = treeStartIndex; i <= treeEndIndex; i++)
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
    if (this->currentStrand < treeEndIndex)
    {
        this->currentStrand = this->currentStrand + 1;
    }
    else
    {
        this->currentStrand = treeStartIndex;
    }

    return true;
}