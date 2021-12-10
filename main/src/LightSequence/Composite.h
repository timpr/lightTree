#include "ILightSequence.h"
#include "LightSequenceStep.h"

/** 
 * Used to combine multiple sequences into one new sequence
 * The delayMilliseconds is the amount of time from running the sequence to startign again
*/
class Composite : public ILightSequence
{
private:
    int delayMs;
    int iterations;
    ILightSequence *steps[5];

public:
    Composite(int iterations, int delayMs, ILightSequence *step0, ILightSequence *step1, ILightSequence *step2 = 0,
              ILightSequence *step3 = 0, ILightSequence *step4 = 0);
    void Play();
};