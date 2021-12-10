#include "ILightSequence.h"
#include "LightSequenceStep.h"

/** 
 * Will move from one strand to the next through the passed in index range, turning on (and leaving on) one strand at a time
 * The delayMilliseconds is the amount of time from turning one strand on to the next
*/
class SetByStrand : public ILightSequence, public LightSequenceStep
{
private:
    int delayMs;
    int startIndex;
    int endIndex;
    int currentStrand;
    bool turnOn;
    void MoveToStrand(int strandIndex);

public:
    SetByStrand(int startIndex, int endIndex, int delayMilliseconds, bool turnOn);
    void Play();
    bool Step();
};