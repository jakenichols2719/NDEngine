#include "load.h"

/*
read bytes of a file (made for BMP) from start (inclusive) to end (exclusive)
returns list of read bytes as uint32_t*
*/
uint16_t* readBytes(std::ifstream* file, int* start, int end) {
  int count = end-*start;
  uint16_t* bytes = new uint16_t[count];
  for(int n=0; n<count; n++) {
    bytes[n] = file->get();
    //std::cout << bytes[n] << " ";
  }
  //std::cout << std::endl;
  *start = end;
  return bytes;
}

/*
format raw bytes into an "image list" with 1 RGBA value to one variable
*/
uint32_t* formatImgList(uint16_t* list, uint32_t size) {
  uint32_t* img = new uint32_t[size/4];
  //snag 4 bytes at a time
  for(int n=0; n<size; n+=4) {
    uint32_t sum = (list[n]<<8) + (list[n+1]<<16) + (list[n+2]<<24) + (list[n+3]);
    //printf("0x%08x, ", sum);
    //if(n%16==0) printf("\n");
    img[n/4]=sum;
  }
  return img;
}

uint32_t* loadImage(std::string name) {
  //open file
  std::string path = "res/img/"+name+".bmp";
  std::ifstream in (path);
  //track current position in file
  int cpos = 0;
  //read BMP header to get size and offset; always 12 bytes
  uint16_t* head = readBytes(&in, &cpos, 12);
  uint32_t size = (head[5]<<24)+(head[4]<<16)+(head[3]<<8)+head[2];
  uint16_t offset = head[10];
  //move file forward to offset
  readBytes(&in, &cpos, offset);
  //read in image data
  uint16_t* img_raw = readBytes(&in, &cpos, size);
  uint32_t* img = formatImgList(img_raw, size-offset);
  //free up memory
  delete(head);
  delete(img_raw);
  //return image
  return img;
}


std::string* readText(std::ifstream* file, int* start, int end) {
  int count = end-*start; //number of lines to read
  std::string* out = new std::string[count]; //output array of strings
  char* temp;
  for(int n=0; n<count; n++) {
    std::getline(*file, out[n]);
  }
  *start = end; //set start to end
  return out; //return output
}

std::string* loadDialog(std::string name) {
  //open text file
  std::string path = "res/dialog/"+name+".txt";
  std::ifstream in (path);
  //track position (lines in this case)
  int cpos = 0;
  int lines = std::stoi(readText(&in, &cpos, 1)[0]);
  std::string* out = readText(&in, &cpos, lines);
  return out;
}