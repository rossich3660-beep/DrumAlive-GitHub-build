#pragma once
#include <JuceHeader.h>
class DrumAliveAudioProcessor : public juce::AudioProcessor {
public:
 DrumAliveAudioProcessor(); ~DrumAliveAudioProcessor() override=default;
 void prepareToPlay(double,int) override; void releaseResources() override; bool isBusesLayoutSupported(const BusesLayout&) const override;
 void processBlock(juce::AudioBuffer<float>&,juce::MidiBuffer&) override;
 juce::AudioProcessorEditor* createEditor() override; bool hasEditor() const override{return true;}
 const juce::String getName() const override{return "DrumAlive";} bool acceptsMidi() const override{return true;} bool producesMidi() const override{return false;} bool isMidiEffect() const override{return false;} double getTailLengthSeconds() const override{return 2.0;}
 int getNumPrograms() override{return 1;} int getCurrentProgram() override{return 0;} void setCurrentProgram(int) override{} const juce::String getProgramName(int) override{return {}; } void changeProgramName(int,const juce::String&) override{}
 void getStateInformation(juce::MemoryBlock&) override; void setStateInformation(const void*,int) override;
 juce::AudioProcessorValueTreeState state; void loadSample(const juce::File&); juce::String sampleName="No sample";
private:
 juce::AudioBuffer<float> sample; double sourceRate=44100, rate=44100; struct Voice{double pos=0,step=1;float gain=1,vel=1,filter=0;bool active=false;}; std::array<Voice,32> voices{}; juce::Random random; juce::AudioProcessorValueTreeState::ParameterLayout createParams(); JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(DrumAliveAudioProcessor)
};
