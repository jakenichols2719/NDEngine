#include <stdint.h>
#include <string>
#include <iostream>
#include <fstream>



//xxd to dump
int main(int argc, char* argv[]) {
  if(argc < 2) {
    std::cout << "Please include a filename" << std::endl;
    return 1;
  }

  //create hex file from bmp
  std::string file = argv[1];
  std::string cmd = "xxd "+file+".bmp > "+file+".hex";
  system(cmd.c_str());

  //read in from newly created hex file
  std::ifstream in (file+".hex");
  std::string line;
  while(std::getline(in,line)) {
    std::cout << line.substr(10,40) << std::endl;
  }

  //close ifstream
  in.close();
  //remove hex file
  cmd = "rm "+file+".hex";
  system(cmd.c_str());
}