/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor* ownerFilter)
    : AudioProcessorEditor (ownerFilter)
{
    // This is where our plugin's editor size is set.
    setSize (400, 300);
}

AudioPluginAudioProcessorEditor::~AudioPluginAudioProcessorEditor()
{
}

//==============================================================================
void AudioPluginAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (Colours::white);
    g.setColour (Colours::black);
    g.setFont (15.0f);
    g.drawFittedText ("Welcome to my plugin!",
                      0, 0, getWidth(), getHeight(),
                      Justification::centred, 1);
}