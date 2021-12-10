#include "ILightSequence.h"
#include "LightSequenceStep.h"

/** 
 * Will rotate AROUND the tree one strand at a time turning the strand on and then back off (all other strands are off).
 * The delayMilliseconds is the amount of time each strand is on.
*/
class TreeChase : public ILightSequence, public LightSequenceStep
{
private:
    int delayMs;
    int iterations;
    int currentStrand;
    void static MoveToStrand(int strandIndex);

public:
    TreeChase(int delayMilliseconds, int iterations);
    void Play();
    bool Step();
};