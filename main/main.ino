#include "src/LightSequence/WarmUp.h"
#include "src/LightSequence/TreeRotate.h"
#include "src/LightSequence/Chase.h"
#include "src/LightSequence/ChaseReverse.h"
#include "src/LightSequence/DecorRotate.h"
#include "src/LightSequence/Toggle.h"
#include "src/LightSequence/SetByStrand.h"
#include "src/LightSequence/SetByStrandReverse.h"
#include "src/LightSequence/Composite.h"
#include "src/LightControls.h"
#include "src/Constants.h"

byte data = 0;
const int lightSequencesLength = 19;
ILightSequence *lightSequences[lightSequencesLength];

//TO Add:
// Twinkle
// Blink
// 2 Strands Alternating (Pinwheel?)

void setup()
{
  int index;
  for (index = 1; index <= 8; index++)
  {
    pinMode(index, OUTPUT);
  }

  WarmUp warmUp;
  TreeRotate rotate(500, 10);
  DecorRotate decorRotate(500, 10);
  SetByStrand onByStrand(treeStartIndex, decorEndIndex, 400, true);
  SetByStrandReverse offByStrand(decorEndIndex, treeStartIndex, 400, false);
  Chase treeChase(treeStartIndex, treeEndIndex, 200, 10);
  Chase decorChase(decorStartIndex, decorEndIndex, 200, 10);
  Chase allChase(treeStartIndex, decorEndIndex - 1, 200, 5);
  Toggle allOnWithDelay(startIndex, endIndex, true, 5000);

  Toggle allInstantOn(startIndex, endIndex, true, 0);
  Toggle allInstantOff(startIndex, endIndex, false, 0);
  Toggle decorInstantOn(decorStartIndex, decorEndIndex, false, 0);
  Toggle treeInstantOff(treeStartIndex, treeEndIndex, false, 0);
  Chase treeChaseSingle(treeStartIndex, treeEndIndex, 200, 1);
  ChaseReverse treeChaseReverseSingle(treeStartIndex + 1, treeEndIndex - 1, 200, 1);
  Composite treePingPong(15, 0, &allInstantOff, &treeChaseSingle, &allInstantOff, &treeChaseReverseSingle);
  Composite treePingPongWithDecor(15, 0, &decorInstantOn, &treeInstantOff, &treeChaseSingle, &treeInstantOff, &treeChaseReverseSingle);

  lightSequences[0] = &allInstantOff;
  lightSequences[1] = &warmUp;
  lightSequences[2] = &onByStrand;
  lightSequences[3] = &decorRotate;
  lightSequences[4] = &treePingPong;
  lightSequences[5] = &rotate;
  lightSequences[6] = &allOnWithDelay;
  lightSequences[7] = &treeChase;
  lightSequences[8] = &allInstantOn;
  lightSequences[9] = &decorChase;
  lightSequences[10] = &allOnWithDelay;
  lightSequences[11] = &treePingPongWithDecor;
  lightSequences[12] = &allOnWithDelay;
  lightSequences[13] = &allChase;
  lightSequences[14] = &allInstantOff;
  lightSequences[15] = &onByStrand;
  lightSequences[16] = &allOnWithDelay;
  lightSequences[17] = &rotate;
  lightSequences[18] = &offByStrand;

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
