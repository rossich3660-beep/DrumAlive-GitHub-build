#include "PluginEditor.h"

DrumAliveAudioProcessorEditor::DrumAliveAudioProcessorEditor(DrumAliveAudioProcessor& proc)
    : AudioProcessorEditor(&proc), p(proc)
{
    setSize(760, 440);
    title.setText("DRUMALIVE / DIAGNOSTIC", juce::dontSendNotification);
    title.setColour(juce::Label::textColourId, juce::Colours::white);
    addAndMakeVisible(title);

    const char* names[] = { "VARIATION", "HUMANIZE", "TONE", "DECAY", "OUTPUT" };
    for (int i = 0; i < 5; ++i)
    {
        knobs[i] = std::make_unique<juce::Slider>();
        knobs[i]->setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
        knobs[i]->setTextBoxStyle(juce::Slider::TextBoxBelow, false, 70, 20);
        addAndMakeVisible(*knobs[i]);
    }
}

void DrumAliveAudioProcessorEditor::paint(juce::Graphics& g)
{
    g.fillAll(juce::Colour(0xff182027));
    g.setColour(juce::Colours::white.withAlpha(.8f));
    const char* names[] = { "VARIATION", "HUMANIZE", "TONE", "DECAY", "OUTPUT" };
    for (int i = 0; i < 5; ++i)
        g.drawText(names[i], 30 + i * 145, 155, 120, 20, juce::Justification::centred);
}

void DrumAliveAudioProcessorEditor::resized()
{
    title.setBounds(28, 24, 600, 35);
    for (int i = 0; i < 5; ++i)
        knobs[i]->setBounds(30 + i * 145, 180, 120, 150);
}
