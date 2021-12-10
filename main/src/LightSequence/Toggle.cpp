#include "Toggle.h"
#include "../Constants.h"
#include "../LightControls.h"

Toggle::Toggle(int startIndex, int endIndex, bool toggleOn, int durationMs)
{
    this->startIndex = startIndex;
    this->endIndex = endIndex;
    this->durationMs = durationMs;
    this->toggleOn = toggleOn;
}

void Toggle::Play()
{
    Step();
    delay(this->durationMs);
}

bool Toggle::Step()
{
    for (int i = this->startIndex; i <= this->endIndex; i++)
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