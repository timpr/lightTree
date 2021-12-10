#include "AllToggle.h"
#include "../Constants.h"
#include "../LightControls.h"

AllToggle::AllToggle(bool toggleOn, int durationMs)
{
    this->durationMs = durationMs;
    this->toggleOn = toggleOn;
}

void AllToggle::Play()
{
    Step();
    delay(this->durationMs);
}

bool AllToggle::Step()
{
    for (int i = startIndex; i <= endIndex; i++)
    {
        if (this->toggleOn)
        {
            LightControls::On(i);
        }
        else
        {
            LightControls::Off(i);
        }
    }

    return true;
}