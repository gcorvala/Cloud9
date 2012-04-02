#include <libsvg/Document.h>
#include <libsvg/Line.h>
#include <libsvg/Polyline.h>
#include <libsvg/Circle.h>
#include <libxml/Element.h>
#include <libxml/Document.h>
#include <libxml/DOMImplementation.h>
#include <libxml/DocumentType.h>

#include <string>
#include <iostream>

int
main (int argc, char** argv)
{
/*  SVG::Document document;
  SVG::Line line (10, 20, 100, 200);
  std::vector < std::pair <Float32, Float32> > points;

  points.push_back (std::make_pair (2000, 1000));
  points.push_back (std::make_pair (100, 1));
  points.push_back (std::make_pair (100, 100));
  points.push_back (std::make_pair (200, 100));
  points.push_back (std::make_pair (200, 200));
  points.push_back (std::make_pair (300, 200));
  points.push_back (std::make_pair (300, 300));

  SVG::Polyline polyline (points);

  SVG::Circle circle (400, 400, 100);

  document.add (line);
  document.add (polyline);
  document.add (circle);

  document.save ("test.svg");

  std::cout << document.getString () << std::endl;

  XML::Element element ("Hello");*/

  XML::DOMImplementation dom;

  XML::DocumentType* doc_type;
  doc_type = dom.createDocumentType ("svg");
  XML::Document* doc = dom.createDocument ("svg", "svg", *doc_type);
  XML::Element* root = doc->getDocumentElement ();
  XML::Element* test;

  test = doc->createElement ("test1");
  root->appendChild (test);

  test->appendChild (doc->createElement ("a"));
  test->appendChild (doc->createElement ("b"));
  test->appendChild (doc->createElement ("c"));

  test = doc->createElement ("test2");
  root->appendChild (test);

  std::cout << doc->getString () << std::endl;

  delete doc;

  return 0;
}