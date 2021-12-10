#include "src/LightSequence/WarmUp.h"
#include "src/LightSequence/TreeRotate.h"
#include "src/LightSequence/Chase.h"
#include "src/LightSequence/DecorRotate.h"
#include "src/LightSequence/AllToggle.h"
#include "src/LightSequence/SetByStrand.h"
#include "src/LightSequence/SetByStrandReverse.h"
#include "src/LightControls.h"
#include "src/Constants.h"

byte data = 0;
const int lightSequencesLength = 13;
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
  SetByStrand onByStrand(treeStartIndex, decorEndIndex, 400, true);
  SetByStrandReverse offByStrand(decorEndIndex, treeStartIndex, 400, false);
  Chase treeChase(treeStartIndex, treeEndIndex, 200, 10);
  Chase decorChase(decorStartIndex, decorEndIndex, 200, 10);
  Chase allChase(treeStartIndex, decorEndIndex - 1, 200, 5);
  AllToggle allOnWithDelay(true, 5000);

  AllToggle allInstantOn(true, 0);
  AllToggle allInstantOff(false, 0);

  lightSequences[0] = &allInstantOff;
  lightSequences[1] = &warmUp;
  lightSequences[2] = &onByStrand;
  lightSequences[3] = &rotate;
  lightSequences[4] = &decorRotate;
  lightSequences[5] = &treeChase;
  lightSequences[6] = &allInstantOn;
  lightSequences[7] = &decorChase;
  lightSequences[8] = &allChase;
  lightSequences[9] = &allInstantOff;
  lightSequences[10] = &onByStrand;
  lightSequences[11] = &allOnWithDelay;
  lightSequences[12] = &offByStrand;

  LightControls::AllOn();
}

bool warmedUp = true;

void loop()
{
  for (int i = 0; i < lightSequencesLength; i++)
  {
    ILightSequence *sequence = lightSequences[i];
    if (sequence)
    {
      sequence->Play();
    }
  }
}
