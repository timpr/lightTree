#include "ILightSequence.h"

class WarmUp : public ILightSequence
{
private:
    void static FlickerToSteadyOn(int outletNumber);
    void RoundAbout();
    void static ShortBlink(int outletIndex);
    bool RunOnce = false;

public:
    WarmUp();
    void Play();
};