#include "src/WarmUp.h"
#include "src/LightSequence/TreeRotate.h"
#include "src/LightSequence/DecorRotate.h"
#include "src/LightSequence/AllOn.h"
#include "src/LightControls.h"

byte data = 0;
const int lightSequencesLength = 3;
ILightSequence *lightSequences[lightSequencesLength];

void setup()
{
  int index;
  for (index = 1; index <= 8; index++)
  {
    pinMode(index, OUTPUT);
  }

  TreeRotate rotate(500, 2);
  DecorRotate decorRotate(500, 2);
  AllOn allOnWithDelay(5000);

  lightSequences[0] = &rotate;
  lightSequences[1] = &decorRotate;
  lightSequences[2] = &allOnWithDelay;

  LightControls::AllOn();
}

bool warmedUp = true;

void loop()
{
  if (!warmedUp)
  {
    WarmUp f;
    f.Switch();
    warmedUp = true;

    delay(5000);
  }

  for (int i = 0; i < lightSequencesLength; i++)
  {
    lightSequences[i]->Play();
  }
}
