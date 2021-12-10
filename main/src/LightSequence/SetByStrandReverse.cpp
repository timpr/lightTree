#include "SetByStrandReverse.h"
#include "../LightControls.h"

SetByStrandReverse::SetByStrandReverse(int startIndex, int endIndex, int delayMilliseconds, bool turnOn)
{
    this->startIndex = startIndex;
    this->endIndex = endIndex;
    this->delayMs = delayMilliseconds;
    this->currentStrand = startIndex;
    this->turnOn = turnOn;
}

void SetByStrandReverse::Play()
{
    //LightControls::AllOff();

    this->currentStrand = this->startIndex;

    // Step through each outlet
    while (this->Step())
    {
        delay(this->delayMs);
    }
}

bool SetByStrandReverse::Step()
{
    if (this->turnOn)
    {
        LightControls::On(this->currentStrand);
    }
    else
    {
        LightControls::Off(this->currentStrand);
    }
    this->currentStrand = this->currentStrand - 1;

    return this->currentStrand >= this->endIndex;
}