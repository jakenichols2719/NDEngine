//contains functions needed to load resources
#include <stdint.h>
#include <string>
#include <iostream>
#include <fstream>


uint16_t* readBytes(std::ifstream* file, int* start, int end);
uint32_t* formatImgList(uint32_t* list);
uint32_t* loadImage(std::string);