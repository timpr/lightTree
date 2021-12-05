#include "AllOn.h"
#include "../Constants.cpp"
#include "../LightControls.h"

AllOn::AllOn(int durationMs)
{
    this->durationMs = durationMs;
}

void AllOn::Play()
{
    Step();
    delay(this->durationMs);
}

bool AllOn::Step()
{
    for (int i = startIndex; i <= endIndex; i++)
    {
        LightControls::On(i);
    }

    return true;
}