#include "TreeRotate.h"
#include "../Constants.cpp"
#include "../LightControls.h"

TreeRotate::TreeRotate(int delayMilliseconds)
{
    this->delayMs = delayMilliseconds;
}

void TreeRotate::Play()
{
    for (int iOff = treeStartIndex; iOff <= treeEndIndex; iOff++)
    {
        for (int i = treeStartIndex; i <= treeEndIndex; i++)
        {
            if (i == iOff)
            {
                LightControls::Off(i);
            }
            else
            {
                LightControls::On(i);
            }
        }
        delay(this->delayMs);
    }
}