#include "LightSequenceStep.h"

bool LightSequenceStep::Step(int numberOfStepsToAdvance)
{
    for (int i = 0; i < numberOfStepsToAdvance; i++)
    {
        bool result = this->Step();
        if (!result)
        {
            return false;
        }
    }
    return true;
}