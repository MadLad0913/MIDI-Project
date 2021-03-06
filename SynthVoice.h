/*
  ==============================================================================
	SynthSound.h
	Created: 5 March, 2020
	Author:  Micah Stone
  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "SynthSound.h"

class SynthVoice : public SynthesiserVoice
{
public:

    bool canPlaySound (SynthesiserSound* sound) 
    {
        return dynamic_cast <SynthSound*>(sound) != nullptr;
    }
    
    //=======================================================
    
    void startNote (int midiNoteNumber, float velocity, SynthesiserSound* sound, int currentPitchWheelPosition) 
    {
        frequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
        std::cout << midiNoteNumber << std::endl;
    }
    
    //=======================================================
    
    void stopNote (float velocity, bool allowTailOff) 
    {
        clearCurrentNote();
    }
    
    //=======================================================
    
    void renderNextBlock (AudioBuffer <float> &outputBuffer, int startSample, int numSamples) 
    {
    }
    
    //=======================================================
    
    void pitchWheelMoved (int newPitchWheelValue) 
    {
    }
    
    //=======================================================
    
    void controllerMoved (int controllerNumber, int newControllerValue) 
    {   
    }
    //=======================================================
    
private:
    double level;
    double frequency;
};
