#include "ILightSequence.h"
#include "LightSequenceStep.h"

/** 
 * Will move from one strand to the next through the passed in index range, turning each strand on and then off
 * The delayMilliseconds is the amount of time each strand is on.
*/
class Chase : public ILightSequence, public LightSequenceStep
{
private:
    int delayMs;
    int startIndex;
    int endIndex;
    int iterations;
    int currentStrand;
    void MoveToStrand(int strandIndex);

public:
    Chase(int startIndex, int endIndex, int delayMilliseconds, int iterations);
    void Play();
    bool Step();
};