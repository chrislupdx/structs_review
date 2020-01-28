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

static const int maxLen = 1000000;
static const int max_word_len = 100;
static const int max_words = 100;
std::string userInput;
char contents[maxLen]; 

struct word_record                                       //struct arr == kwindex
{
 // char keyword_index[max_words][max_word_len]; //it should be an array of arrays
int age, charCount;
  int lines[100]; //for storing where we find the word
};

