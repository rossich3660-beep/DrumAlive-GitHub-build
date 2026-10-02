#include "PluginEditor.h"

// Temporary diagnostic editor: keep construction minimal to isolate the
// crash from UI controls, image decoding, and parameter attachments.
DrumAliveAudioProcessorEditor::DrumAliveAudioProcessorEditor(DrumAliveAudioProcessor& proc)
    : AudioProcessorEditor(&proc), p(proc)
{
    setSize(760, 440);
}

void DrumAliveAudioProcessorEditor::paint(juce::Graphics& g)
{
    g.fillAll(juce::Colour(0xff182027));
    g.setColour(juce::Colours::white);
    g.drawText("DrumAlive diagnostic build", getLocalBounds(),
               juce::Justification::centred);
}

void DrumAliveAudioProcessorEditor::resized()
{
}
