#include "src/LightSequence/WarmUp.h"
#include "src/LightSequence/TreeRotate.h"
#include "src/LightSequence/DecorRotate.h"
#include "src/LightSequence/AllOn.h"
#include "src/LightControls.h"

byte data = 0;
const int lightSequencesLength = 4;
ILightSequence *lightSequences[lightSequencesLength];

void setup()
{
  int index;
  for (index = 1; index <= 8; index++)
  {
    pinMode(index, OUTPUT);
  }

  WarmUp warmUp;
  TreeRotate rotate(500, 2);
  DecorRotate decorRotate(500, 2);
  AllOn allOnWithDelay(5000);

  lightSequences[0] = &warmUp;
  lightSequences[1] = &rotate;
  lightSequences[2] = &decorRotate;
  lightSequences[3] = &allOnWithDelay;

  LightControls::AllOn();
}

bool warmedUp = true;

void loop()
{
  for (int i = 0; i < lightSequencesLength; i++)
  {
    lightSequences[i]->Play();
  }
}
