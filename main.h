#pragma once

//system libraries
#include <iostream>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>
#include <fstream>

// defined constants
//#define max_word_ln 100

struct txtRecord
{
  std::string userInput;
  static const int maxLen = 1000000;
  static const int maxWords = 100;
  char contents[maxLen]; 
  char keywordIndex[maxWords]; //it should be an array of arrays
int age, charCount;
};

