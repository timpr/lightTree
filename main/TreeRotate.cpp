#include "TreeRotate.h"
#include "Constants.cpp"
#include "BaseLightSequence.h"

void TreeRotate::Next()
{
    for (int iOff = treeStartIndex; iOff <= treeEndIndex; iOff++)
    {
        for (int i = treeStartIndex; i <= treeEndIndex; i++)
        {
            if (i == iOff)
            {
                BaseLightSequence::Off(i);
            }
            else
            {
                BaseLightSequence::On(i);
            }
        }
        delay(750);
    }
}