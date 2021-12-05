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

    void static AllOn();

    void static On(int outletIndex);

    void static AllOff();

    void static Off(int outletIndex);
};