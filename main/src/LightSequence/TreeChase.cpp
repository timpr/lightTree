#include "TreeChase.h"
#include "../Constants.cpp"
#include "../LightControls.h"

TreeChase::TreeChase(int delayMilliseconds, int iterations)
{
    this->delayMs = delayMilliseconds;
    this->iterations = iterations;
    this->currentStrand = treeStartIndex;
}

void TreeChase::Play()
{
    this->currentStrand = treeStartIndex;

    LightControls::TreeOff();

    for (int iteration = 0; iteration < this->iterations; iteration++)
    {
        LightControls::ExecuteOnStrands(TreeChase::MoveToStrand, treeStartIndex, treeEndIndex, this->delayMs);
    }
}

bool TreeChase::Step()
{

    if (this->currentStrand < treeEndIndex)
    {
        this->currentStrand = this->currentStrand + 1;
    }
    else
    {
        this->currentStrand = treeStartIndex;
    }

    TreeChase::MoveToStrand(this->currentStrand);

    return true;
}

void TreeChase::MoveToStrand(int strandIndex)
{
    //Turn prior strand off
    if (strandIndex - 1 >= treeStartIndex)
    {
        LightControls::Off(strandIndex - 1);
    }
    else
    {
        LightControls::Off(treeEndIndex);
    }

    //Turn new strand on
    LightControls::On(strandIndex);
}