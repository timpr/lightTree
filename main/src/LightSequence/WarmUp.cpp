#include "WarmUp.h"
#include "..\LightControls.h"
#include "..\Constants.h"

WarmUp::WarmUp()
{
}

void WarmUp::Play()
{
    if (this->RunOnce)
    {
        return;
    }
    this->RunOnce = true;

    LightControls::AllOff();
    LightControls::ExecuteOnEachStrand(FlickerToSteadyOn, 0);
    this->RoundAbout();
    LightControls::AllOn();
}

void WarmUp::FlickerToSteadyOn(int outletIndex)
{
    LightControls::Blink(outletIndex, 16, 25);
    LightControls::Blink(outletIndex, 8, 50);
    LightControls::Blink(outletIndex, 4, 100);
    LightControls::Blink(outletIndex, 2, 200);
    LightControls::Blink(outletIndex, 1, 500);
    digitalWrite(outletIndex, ON);
}

void WarmUp::RoundAbout()
{
    LightControls::ExecuteOnEachStrand(ShortBlink, 0);
    LightControls::ExecuteOnEachStrand(ShortBlink, 0);
    LightControls::ExecuteOnEachStrand(ShortBlink, 0);
}

void WarmUp::ShortBlink(int outletIndex)
{
    LightControls::Blink(outletIndex, 1, 150);
}