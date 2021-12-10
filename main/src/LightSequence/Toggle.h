#include "ILightSequence.h"
#include "LightSequenceStep.h"

/** 
 * Will turn all the lights on or Off within the given index range
*/
class Toggle : public ILightSequence, public LightSequenceStep
{
private:
    int startIndex;
    int endIndex;
    int durationMs;
    int toggleOn;

public:
    Toggle(int startIndex, int endIndex, bool toggleOn, int durationMs);
    void Play();
    bool Step();
};