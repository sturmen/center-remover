/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
AudioPluginAudioProcessor::AudioPluginAudioProcessor()
{
}

AudioPluginAudioProcessor::~AudioPluginAudioProcessor()
{
}

//==============================================================================
const String AudioPluginAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

int AudioPluginAudioProcessor::getNumParameters()
{
    return 0;
}

float AudioPluginAudioProcessor::getParameter (int index)
{
    return 0.0f;
}

void AudioPluginAudioProcessor::setParameter (int index, float newValue)
{
}

const String AudioPluginAudioProcessor::getParameterName (int index)
{
    return String::empty;
}

const String AudioPluginAudioProcessor::getParameterText (int index)
{
    return String::empty;
}

const String AudioPluginAudioProcessor::getInputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

const String AudioPluginAudioProcessor::getOutputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

bool AudioPluginAudioProcessor::isInputChannelStereoPair (int index) const
{
    return true;
}

bool AudioPluginAudioProcessor::isOutputChannelStereoPair (int index) const
{
    return true;
}

bool AudioPluginAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool AudioPluginAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool AudioPluginAudioProcessor::silenceInProducesSilenceOut() const
{
    return true;
}

double AudioPluginAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int AudioPluginAudioProcessor::getNumPrograms()
{
    return 0;
}

int AudioPluginAudioProcessor::getCurrentProgram()
{
    return 0;
}

void AudioPluginAudioProcessor::setCurrentProgram (int index)
{
}

const String AudioPluginAudioProcessor::getProgramName (int index)
{
    return String::empty;
}

void AudioPluginAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void AudioPluginAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void AudioPluginAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

void AudioPluginAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...

	if (getNumInputChannels() == 2) {
		float* channel0Data = buffer.getSampleData(0);
		float* channel1Data = buffer.getSampleData(1);
		float channelSide = 0;

		for (int i = 0; i < buffer.getNumSamples(); i++) {
			channelSide = *(channel0Data + i) - *(channel1Data + i);

			*(channel0Data + i) = channelSide;
			*(channel1Data + i) = channelSide;
		}
	}
    // In case we have more outputs than inputs, we'll clear any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    for (int i = getNumInputChannels(); i < getNumOutputChannels(); ++i)
    {
        buffer.clear (i, 0, buffer.getNumSamples());
    }
}

//==============================================================================
bool AudioPluginAudioProcessor::hasEditor() const
{
    return false; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* AudioPluginAudioProcessor::createEditor()
{
    return new AudioPluginAudioProcessorEditor (this);
}

//==============================================================================
void AudioPluginAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void AudioPluginAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new AudioPluginAudioProcessor();
}
