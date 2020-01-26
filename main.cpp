//file upload + keywordin
//sources: 162 demo_2/demo_3
#include "main.h"

using namespace std;

void handle_word(char word[]);

int main() 
{
  string userInput; //take raw userinput as a string to account for spaces
  string line_as_string;  //the output for getline (getline requires an output?)
  string inputName;
  int word_count = 0; //counts the number of words in file
  int lines = 0; //counts lines (not perfect)
  bool wip = false;
  ifstream inData; //input stream
  txtRecord textRecord; //struct that stores userinput, kwIndex and the text as c string
  const int max_word_ln = 100;
  char word_buffer[max_word_ln]; //buffer for word being parsed
  char char_buffer = '\0'; //starting with a blank line char bc?
  int write_ptr = 0; //write pointer exists to make sure we don't exceed how many chars a word is

  //Input
  cout << "name a file: ";  //request filename 
  textRecord.userInput = "text.txt"; //delete before production
  //cin >> textRecord.userInput; //take userinput as a string
  cout << "file is " << textRecord.userInput << endl; //confirm selection
  inputName = textRecord.userInput.c_str(); //convert the input to a c string, worth checking to see if this is necesary

  //the block below is for counting lines
  inData.open(inputName); //open the stream again
  while(!inData.eof()) //while you haven't hit the end of the file
  {
    if(getline(inData, line_as_string )) //this is our linecounting logic, still need to situate it
    {
      ++lines; //increment line counter
    }
  };
  inData.close();

  //this block is for parsing words
  inData.open(inputName); //opening a new fileparse block for word counting
  //ideal parsing method (from stream, not from your c stringw:q
  while(( char_buffer = inData.get()) != EOF) // .get() the filstream, assign it the name char_buffer. Stop condition is when we reach EOF
  {
    if (inData.good() != true)   //If the read fails 
    {
      if (wip == true) //if a word is in progress
      {
        wip = false; //stop counting words
        word_count++;
        handle_word(word_buffer);
      }
    }
    else // if the read is good (parse content for words)
    {
      if (char_buffer == '\n') ++lines; //if we just read EOL, increment the line number
      if (isspace(char_buffer) > 0 ) //if we just read whitespsace
      {
        if(wip == true ) //if a word was being read and we previously just read a whitespace...
        {
          word_count++; //that would mean we've read an entire word, increment word_count
          wip == false; //we've finished the word, word is no longer in progress
          handle_word(word_buffer);        
        }
      }
      else //if we just read non-whitespace (like a letter or punctuation?)
      {
        if (wip == true) //if we're in the middle of parsing a word
        {
          if (write_ptr< (max_word_ln - 1))
          {
            word_buffer[write_ptr++] = char_buffer; //write the 
          }
        }
        else //looks like we've hit a new word
        {
          wip == true;
          write_ptr = 0; //reset word pointer bc new word
          for (int index = 0; index < max_word_ln; index++)
            word_buffer[index] = '\0'; //not 100% sure why we're resetting buffer
          word_buffer[write_ptr++] = char_buffer;
        }
      }
    } 
  }

  cout << setw(5) << setfill(' ') <<  "number of lines is " << lines << " "
    << setw(5) << setfill(' ') <<  "number of words is " << " " << endl;
  return 0;
}

void handle_word(char word[])
{
  cout << "word is " << strlen(word) << " letters long" << endl;

}
