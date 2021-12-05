#include "WarmUp.h"
#include "TreeRotate.h"
#include "LightControls.h"

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

  TreeRotate rotate;
  rotate.Next();
  rotate.Next();
  rotate.Next();
  rotate.Next();
  rotate.Next();
  rotate.Next();
  LightControls::AllOn();
  delay(5000);
}
