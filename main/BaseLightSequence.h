#include "stdint.h"
#include "Arduino.h"

class BaseLightSequence
{
private:
    /* data */
protected:
    int const static startIndex = 1;
    int const static endIndex = 8;
    int const static treeStartIndex = 1;
    int const static treeEndIndex = 4;

public:
    BaseLightSequence(/* args */);
    ~BaseLightSequence();

    const static uint8_t ON = LOW;
    const static uint8_t OFF = HIGH;

    /**
     * Turns the outlet on and then off with the provided parameters
     */
    void static Blink(int outletIndex, int iterations, int millisecondsDelay);

    /**
     * For each socket, executes the given function
     * pFunc: Function to execute on each strand
     * pIntervalMilliseconds: Milliseconds between applying the logic on each strand
     */
    void static ExecuteOnEachStrand(void (*pFunc)(int outletIndex), int pIntervalMilliseconds);

    void static AllOn();

    void static On(int outletIndex);

    void static AllOff();

    void static Off(int outletIndex);
};