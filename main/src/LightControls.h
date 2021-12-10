#include "stdint.h"
#include "Arduino.h"

class LightControls
{
private:
    /* data */
protected:
public:
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

    /**
     * For each socket in the given index range, executes the given function
     * pFunc: Function to execute on each strand
     * pIntervalMilliseconds: Milliseconds between applying the logic on each strand
     */
    void static ExecuteOnStrands(void (*pFunc)(int outletIndex), int pStartIndex, int pEndIndex, int pIntervalMilliseconds);

    void static AllOn();

    void static On(int outletIndex);

    void static AllOff();

    void static Off(int outletIndex);

    void static TreeOn();
    void static TreeOff();
    void static DecorOn();
    void static DecorOff();
};