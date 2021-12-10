#include "ILightSequence.h"
#include "LightSequenceStep.h"

/** 
 * Will turn all the lights on or Off
*/
class AllToggle : public ILightSequence, public LightSequenceStep
{
private:
    int durationMs;
    int toggleOn;

public:
    AllToggle(bool toggleOn, int durationMs);
    void Play();
    bool Step();
};