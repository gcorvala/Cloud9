#include "ImageNode.h"

ImageNode::ImageNode ()
  :Node("Image")
{
  addInputAnchor ("image");

  addOutputAnchor ("red-channel");
  addOutputAnchor ("green-channel");
  addOutputAnchor ("blue-channel");
}

ImageNode::~ImageNode ()
{
}

void
ImageNode::process ()
{
  Image* image;

  image = inputs["image"]->var->value<Image*> ();
  outputs["red-channel"]->setValue (&(image->getRedChannel ()));
  outputs["green-channel"]->setValue (&(image->getGreenChannel ()));
  outputs["blue-channel"]->setValue (&(image->getBlueChannel ()));
  postProcess ();
}