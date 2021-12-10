#include "SetByStrand.h"
#include "../LightControls.h"

SetByStrand::SetByStrand(int startIndex, int endIndex, int delayMilliseconds, bool turnOn)
{
    this->startIndex = startIndex;
    this->endIndex = endIndex;
    this->delayMs = delayMilliseconds;
    this->currentStrand = startIndex;
    this->turnOn = turnOn;
}

void SetByStrand::Play()
{
    //LightControls::AllOff();

    this->currentStrand = this->startIndex;

    // Step through each outlet
    while (this->Step())
    {
        delay(this->delayMs);
    }
}

bool SetByStrand::Step()
{
    if (this->turnOn)
    {
        LightControls::On(this->currentStrand);
    }
    else
    {
        LightControls::Off(this->currentStrand);
    }
    this->currentStrand = this->currentStrand + 1;

    return this->currentStrand <= this->endIndex;
}