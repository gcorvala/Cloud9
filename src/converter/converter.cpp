#include <iostream>
#include <string.h>
#include <libcloud/Common/PointCloud.h>
#include <libcloud/IO/FileReader.h>
#include <libcloud/IO/XYZReader.h>
#include <libcloud/IO/OBJReader.h>
#include <libcloud/IO/PCDReader.h>
#include <libcloud/IO/FileWriter.h>
#include <libcloud/IO/XYZWriter.h>
#include <libcloud/IO/OBJWriter.h>
#include <libcloud/IO/PCDWriter.h>

int
main (int argc, char** argv)
{
  FileReader *reader;
  FileWriter *writer;
  PointCloud cloud;
  char* input;
  char* output;
  char* exec;
  bool input_binary;
  bool output_binary;

  exec = *argv;

  if (argc < 7 || argc > 9) {
    std::cout << "1 Usage : " << exec << " -i type [-b] input -o type [-b] output" << std::endl;
    return -1;
  }
  argv++;
  if (strcmp ("-i", *argv++) != 0) {
    std::cout << "2 Usage : " << exec << " -i type [-b] input -o type [-b] output" << std::endl;
    return -1;
  }
  if (strcmp ("xyz", *argv) == 0) {
    reader = (FileReader*) new XYZReader ();
  }
  else if (strcmp ("obj", *argv) == 0) {
    reader = (FileReader*) new OBJReader ();
  }
  else if (strcmp ("pcd", *argv) == 0) {
    reader = (FileReader*) new PCDReader ();
  }
  else {
    std::cout << "3 Usage : " << exec << " -i type [-b] input -o type [-b] output" << std::endl;
    return -1;
  }
  argv++;
  if (strcmp ("-b", *argv) == 0) {
    input_binary = true;
    argv++;
  }
  input = *argv;
  argv++;
  if (strcmp ("-o", *argv++) != 0) {
    std::cout << "4 Usage : " << exec << " -i type [-b] input -o type [-b] output" << std::endl;
    return -1;
  }
  if (strcmp ("xyz", *argv) == 0) {
    writer = (FileWriter*) new XYZWriter ();
  }
  else if (strcmp ("obj", *argv) == 0) {
    writer = (FileWriter*) new OBJWriter ();
  }
  else if (strcmp ("pcd", *argv) == 0) {
    writer = (FileWriter*) new PCDWriter ();
  }
  else {
    std::cout << "5 Usage : " << exec << " -i type [-b] input -o type [-b] output" << std::endl;
    return -1;
  }
  argv++;
  if (strcmp ("-b", *argv) == 0) {
    output_binary = true;
    argv++;
  }
  output = *argv;

  reader->read (input, cloud, input_binary);
  writer->write (output, cloud, output_binary);

  delete (reader);
  delete (writer);
  
  return 0;
}
