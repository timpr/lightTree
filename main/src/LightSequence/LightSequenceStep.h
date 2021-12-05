#pragma once

/**
 * Implemented by classes that can support stepping through one step at a time a particular sequence.
 * This can be useful for combining more than one sequence to create a new sequence.
 */
class LightSequenceStep
{
public:
    /**
    * Will proceed a single step in the current sequence.
    * Needs to track where it is to resume when called again. If there are no further steps possible, return false.
    */
    virtual bool Step() = 0;

    /**
    * Will proceed the specified number of steps (or the max possible) in the sequence.
    * If there are no further steps possible, return false.
    */
    bool Step(int numberOfStepsToAdvance);
};