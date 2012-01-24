#include "ImageNode.h"

ImageNode::ImageNode ()
  :Node("Image")
{
  addInputAnchor (new InputAnchor (this), "image");

  addOutputAnchor (new OutputAnchor (this), "red-channel");
  addOutputAnchor (new OutputAnchor (this), "green-channel");
  addOutputAnchor (new OutputAnchor (this), "blue-channel");
}

ImageNode::~ImageNode ()
{
}

void
ImageNode::process ()
{
  Image* image;

  setRunning ();
  image = inputs["image"]->var->value<Image*> ();
  outputs["red-channel"]->var.setValue (&(image->getRedChannel ()));
  outputs["green-channel"]->var.setValue (&(image->getGreenChannel ()));
  outputs["blue-channel"]->var.setValue (&(image->getBlueChannel ()));
  endProcess ();
  unsetRunning ();
}