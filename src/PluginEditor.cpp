#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processorRef (p)
{
    juce::ignoreUnused (processorRef);
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (200, 400);

	gainSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
	gainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 100, 25);
	gainSlider.setRange(-48.0, 0.0);
	gainSlider.setValue(-1.0);
	gainSlider.addListener(this); // LISTENER: Actually makes it work!
	addAndMakeVisible(gainSlider);
}

AudioPluginAudioProcessorEditor::~AudioPluginAudioProcessorEditor()
{
}

//==============================================================================
void AudioPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colour(26, 26, 30));
	
	// draw slider
	gainSlider.setBounds(getLocalBounds());
	
    // g.setColour (juce::Colour(214, 222, 223));
    // g.setFont (15.0f);
    // g.drawFittedText ("Hello!", getLocalBounds(), juce::Justification::centred, 1);
}	

void AudioPluginAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
