#include "ILightSequence.h"
#include "LightSequenceStep.h"

class TreeRotate : public ILightSequence, public LightSequenceStep
{
private:
    int delayMs;
    int iterations;
    int currentStrand;
    int lastStrand;

public:
    TreeRotate(int delayMilliseconds, int iterations);
    void Play();
    bool Step();
};