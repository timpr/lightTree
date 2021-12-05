#include "ILightSequence.h"

class TreeRotate : public ILightSequence
{
private:
    int delayMs;

public:
    TreeRotate(int delayMilliseconds);
    void Play();
};