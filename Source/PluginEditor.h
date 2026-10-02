#pragma once
#include "PluginProcessor.h"
class DrumAliveAudioProcessorEditor:public juce::AudioProcessorEditor{public:explicit DrumAliveAudioProcessorEditor(DrumAliveAudioProcessor&);void paint(juce::Graphics&)override;void resized()override;private:DrumAliveAudioProcessor& p;juce::Image bg;juce::TextButton load{"LOAD SAMPLE"};juce::Label title;std::array<std::unique_ptr<juce::Slider>,5> knobs;std::array<std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment>,5> attaches;JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(DrumAliveAudioProcessorEditor)};
