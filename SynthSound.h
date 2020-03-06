/*
  ==============================================================================
    SynthSound.h
    Created: 5 March, 2020 
    Author:  Micah Stone
  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class SynthSound : public SynthesiserSound
{
public:
    bool appliesToNote (int midiNoteNumber) override
    {
        return true;
    }
    
    bool appliesToChannel (int midiNoteNumber) override
    {
        return true;
    }    
};
