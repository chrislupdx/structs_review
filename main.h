#pragma once
#include <iostream>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>
#include <fstream>

struct txtRecord
{
  std::string userInput;
  static const int maxLen = 10000;
  static const int maxWords = 100;
  static const int maxWordLen = 100;
  static const int maxLines = 100;
  char contents[maxLen]; //the entire text in a single c string
  char kwIndex[maxWords][maxWordLen]; //1st 100 unique words get put into c strings here then sorted

  int age, charCount; 
};

