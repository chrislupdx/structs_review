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
  static const int maxLen = 1000000;
  char contents[maxLen]; 
  int age, charCount;
};

