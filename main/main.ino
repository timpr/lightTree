#include "src/WarmUp.h"
#include "src/LightSequence/TreeRotate.h"
#include "src/LightControls.h"

byte data = 0;

void setup()
{
  int index;
  for (index = 1; index <= 8; index++)
  {
    pinMode(index, OUTPUT);
  }
}

bool warmedUp = false;

void loop()
{
  if (!warmedUp)
  {
    WarmUp f;
    f.Switch();
    warmedUp = true;
  }

  delay(5000);

  TreeRotate rotate(750);
  rotate.Play();
  rotate.Play();
  rotate.Play();
  rotate.Play();
  rotate.Play();
  rotate.Play();
  LightControls::AllOn();
  delay(5000);
}
