/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
ImagesPluginAudioProcessorEditor::ImagesPluginAudioProcessorEditor (ImagesPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p),
fileFilter ("*.jpeg;*.jpg;*.png;*.gif", "*", "Image Filter"),
fileDirectoryThread ("Image File Scanner"),
dirContentsList (&fileFilter, fileDirectoryThread),
fileTree (dirContentsList),
resizer (&layout, 1, false)
{
    setOpaque (true);
    dirContentsList.setDirectory (File::getSpecialLocation (File::userPicturesDirectory), true, true);
    fileDirectoryThread.startThread (1);
    
    fileTree.addListener (this);
    fileTree.setColour (TreeView::backgroundColourId, Colours::whitesmoke.withAlpha (0.6f));
    addAndMakeVisible (fileTree);
    
    addAndMakeVisible (resizer);
    
    addAndMakeVisible (imagePreview);
    
    // fileTree
    layout.setItemLayout (0, -0.1, -0.9, -0.4);
    
    // resizer
    layout.setItemLayout (1, 3, 3, 3);
    
    // imagePreview
    layout.setItemLayout (2, -0.1, -0.9, -0.6);
    
    
    setResizeLimits (400, 400, 1200, 600);
    setSize (p.lastUIWidth, p.lastUIHeight);
}

ImagesPluginAudioProcessorEditor::~ImagesPluginAudioProcessorEditor()
{
    fileTree.removeListener (this);
}

//==============================================================================
void ImagesPluginAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (Colours::darkgrey);   // clear the background
    g.setColour (Colours::black);
    g.drawRect (getLocalBounds(), 0.5);
}

void ImagesPluginAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    Rectangle<int> r (getLocalBounds());
    //
    // make a list of two of our child components that we want to reposition
    Component* comps[] = { &fileTree, &resizer, &imagePreview };
    
    // this will position the 3 components, one above the other, to fit
    // vertically into the rectangle provided.
    layout.layOutComponents (comps, 3, r.getX(), r.getY(), r.getWidth(), r.getHeight(), true, true);
    
    getProcessor().lastUIWidth = getWidth();
    getProcessor().lastUIHeight = getHeight();
}
