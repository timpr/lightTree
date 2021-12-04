#include "BaseLightSequence.h"

class WarmUp : BaseLightSequence
{
private:
    void static FlickerToSteadyOn(int outletNumber);
    void RoundAbout();
    void static ShortBlink(int outletIndex);

public:
    WarmUp();
    void Switch();
};