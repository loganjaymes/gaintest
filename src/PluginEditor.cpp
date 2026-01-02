#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor& p)
	: AudioProcessorEditor (&p), processorRef (p) {
	juce::ignoreUnused (processorRef);
	setSize(800, 450);

	gainSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
	gainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 100, 25);
	gainSlider.setRange(-48.0, 0.0);
	gainSlider.setValue(-1.0);
	gainSlider.addListener(this); // LISTENER: Actually makes it work!
	addAndMakeVisible(gainSlider);
}

AudioPluginAudioProcessorEditor::~AudioPluginAudioProcessorEditor() {
}

//==============================================================================
void AudioPluginAudioProcessorEditor::paint (juce::Graphics& g) {
	g.fillAll (juce::Colour(26, 26, 30));
	
	// draw slider
	gainSlider.getLookAndFeel().setColour(juce::Slider::textBoxOutlineColourId, juce::Colour(190, 81, 77));
	gainSlider.getLookAndFeel().setColour(juce::Slider::backgroundColourId, juce::Colour(134, 68, 73));
	gainSlider.getLookAndFeel().setColour(juce::Slider::trackColourId, juce::Colour(214, 222, 223));
	gainSlider.getLookAndFeel().setColour(juce::Slider::thumbColourId, juce::Colour(97, 101, 119));
	
	// g.setColour (juce::Colour(214, 222, 223));
	// g.setFont (15.0f);
	// g.drawFittedText ("Hello!", getLocalBounds(), juce::Justification::centred, 1);
}	

void AudioPluginAudioProcessorEditor::resized() {
	// This is generally where you'll want to lay out the positions of any
	// subcomponents in your editor..
	
	gainSlider.setBounds(0, 50, getWidth() / 3, getHeight() - 100);
	//gainSlider.setBounds(0, 50, 250, 350);
}

void AudioPluginAudioProcessorEditor::sliderValueChanged (juce::Slider* slider) {
	if(slider == &gainSlider) {
		// calculate decibels and display
		processorRef.rawVolume = pow(10, gainSlider.getValue() / 20); // div by 20 
	}
}
