#include "ILightSequence.h"
#include "LightSequenceStep.h"

/** 
 * Will turn all the lights on
*/
class AllOn : public ILightSequence, public LightSequenceStep
{
private:
    int durationMs;

public:
    AllOn(int durationMs);
    void Play();
    bool Step();
};