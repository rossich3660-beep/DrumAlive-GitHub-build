#include "PluginEditor.h"

DrumAliveAudioProcessorEditor::DrumAliveAudioProcessorEditor(DrumAliveAudioProcessor& proc)
    : AudioProcessorEditor(&proc), p(proc)
{
    setSize(760, 440);

    title.setText("DRUMALIVE   /   SAMPLE RESYNTHESIS", juce::dontSendNotification);
    title.setColour(juce::Label::textColourId, juce::Colours::white);
    title.setFont(juce::Font(18, juce::Font::bold));
    addAndMakeVisible(title);

    addAndMakeVisible(load);
    load.onClick = [this]
    {
        auto chooser = std::make_shared<juce::FileChooser>("Load one-shot");
        chooser->launchAsync(
            juce::FileBrowserComponent::openMode | juce::FileBrowserComponent::canSelectFiles,
            [this, chooser](const juce::FileChooser& fc)
            {
                const auto file = fc.getResult();
                if (file.existsAsFile())
                    p.loadSample(file);
            });
    };

    const char* ids[] = { "variation", "humanize", "tone", "decay", "output" };
    for (int i = 0; i < 5; ++i)
    {
        knobs[i] = std::make_unique<juce::Slider>();
        knobs[i]->setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
        knobs[i]->setTextBoxStyle(juce::Slider::TextBoxBelow, false, 70, 20);
        knobs[i]->setColour(juce::Slider::rotarySliderFillColourId, juce::Colour(0xff69d4d0));
        addAndMakeVisible(*knobs[i]);
        attaches[i] = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(
            p.state, ids[i], *knobs[i]);
    }
}

void DrumAliveAudioProcessorEditor::paint(juce::Graphics& g)
{
    g.fillAll(juce::Colour(0xff182027));
    g.setColour(juce::Colours::white.withAlpha(.8f));
    const char* names[] = { "VARIATION", "HUMANIZE", "TONE", "DECAY", "OUTPUT" };
    for (int i = 0; i < 5; ++i)
        g.drawText(names[i], 30 + i * 145, 155, 120, 20, juce::Justification::centred);
    g.setColour(juce::Colour(0xff69d4d0));
    g.drawText(p.sampleName, 30, 105, 500, 24, juce::Justification::left);
}

void DrumAliveAudioProcessorEditor::resized()
{
    title.setBounds(28, 24, 600, 35);
    load.setBounds(28, 65, 150, 30);
    for (int i = 0; i < 5; ++i)
        knobs[i]->setBounds(30 + i * 145, 180, 120, 150);
}
