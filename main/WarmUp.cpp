#include "WarmUp.h"

WarmUp::WarmUp()
{
}

void WarmUp::Switch()
{
    this->AllOff();
    // this->ExecuteOnEachStrand(FlickerToSteadyOn, 0);
    this->RoundAbout();
    this->AllOn();
}

void WarmUp::FlickerToSteadyOn(int outletIndex)
{
    Blink(outletIndex, 16, 25);
    Blink(outletIndex, 8, 50);
    Blink(outletIndex, 4, 100);
    Blink(outletIndex, 2, 200);
    Blink(outletIndex, 1, 500);
    digitalWrite(outletIndex, BaseLightSequence::ON);
}

void WarmUp::RoundAbout()
{
    this->ExecuteOnEachStrand(ShortBlink, 0);
    this->ExecuteOnEachStrand(ShortBlink, 0);
    this->ExecuteOnEachStrand(ShortBlink, 0);
}

void WarmUp::ShortBlink(int outletIndex)
{
    BaseLightSequence::Blink(outletIndex, 1, 150);
}