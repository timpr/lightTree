#include "Composite.h"
#include "../LightControls.h"

Composite::Composite(int iterations, int delayMs, ILightSequence *step0, ILightSequence *step1, ILightSequence *step2,
                     ILightSequence *step3, ILightSequence *step4)
{
    this->delayMs = delayMs;
    this->iterations = iterations;
    this->steps[0] = step0;
    this->steps[1] = step1;
    this->steps[2] = step2;
    this->steps[3] = step3;
    this->steps[4] = step4;
}

void Composite::Play()
{
    int iteration;
    for (iteration = 0; iteration < this->iterations; iteration++)
    {
        for (int i = 0; i < 5; i++)
        {
            ILightSequence *step = this->steps[i];
            if (step && step != 0)
            {
                step->Play();
            }
        }

        delay(delayMs);
    }
}
