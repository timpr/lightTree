#include "ILightSequence.h"
#include "LightSequenceStep.h"

/** 
 * Will turn a strand off and then back on, starting at the bottom and moving up the tree
 * The delayMilliseconds is the amount of time each strand is off.
*/
class DecorRotate : public ILightSequence, public LightSequenceStep
{
private:
    int delayMs;
    int iterations;
    int currentStrand;
    int lastStrand;

public:
    DecorRotate(int delayMilliseconds, int iterations);
    void Play();
    bool Step();
};