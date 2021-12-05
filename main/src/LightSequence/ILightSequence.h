#pragma once

/**
 * Implemented by classes that can play thorugh a light sequence with no additional interaction.
 */
class ILightSequence
{
public:
    virtual void Play() = 0;
};