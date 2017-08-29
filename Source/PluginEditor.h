/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#ifndef PLUGINEDITOR_H_INCLUDED
#define PLUGINEDITOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"


//==============================================================================
/**
*/
class ImagesPluginAudioProcessorEditor  : public AudioProcessorEditor,
public FileBrowserListener, public DragAndDropContainer

{
public:
    ImagesPluginAudioProcessorEditor (ImagesPluginAudioProcessor&);
    ~ImagesPluginAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    ImagesPluginAudioProcessor& processor;
    WildcardFileFilter fileFilter;
    TimeSliceThread fileDirectoryThread;
    DirectoryContentsList dirContentsList;
    StretchableLayoutManager layout;
    FileTreeComponent fileTree;
    
    ImageComponent imagePreview;
    
    
    StretchableLayoutResizerBar resizer;
    
    void selectionChanged() override
    {
        
        const File selectedFile (fileTree.getSelectedFile());
        
        if (selectedFile.existsAsFile())
            imagePreview.setImage (ImageCache::getFromFile (selectedFile));
            
        
            }
    
    void fileClicked (const File&, const MouseEvent&) override {}
    void fileDoubleClicked (const File&) override {}
    void browserRootChanged (const File&) override {}

    ImagesPluginAudioProcessor& getProcessor() const
    {
        return static_cast<ImagesPluginAudioProcessor&> (processor);
    }
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ImagesPluginAudioProcessorEditor)
};


#endif  // PLUGINEDITOR_H_INCLUDED
