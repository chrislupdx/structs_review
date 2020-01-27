//file upload + keywordin
//sources: 162 demo_2/demo_3
#include "main.h"

using namespace std;
const int max_word_len = 100; //this is to clear prototype declaration

void handle_word(char word[], char kw_index[][max_word_len]);

int main() 
{
  string userInput;              //take raw userinput as a string to account for spaces
  string line_as_string;         //the output for getline (getline requires an output?)
  string inputName;
  int word_count = 0;            //counts the number of words in file
  int lines = 0;                 //counts lines (not perfect)
  bool wip = false;
  ifstream inData;               //input stream
  txtRecord textRecord;          //struct that stores userinput, kwIndex and the text as c string
  const int max_word_ln = 100;
  char word_buffer[max_word_ln]; //buffer for word being parsed
  char char_buffer = '\0';       //starting with a blank line char bc?
  int write_ptr = 0;             //write pointer exists to make sure we don't exceed how many chars a word is
  //int kw_index_pos = 0;

  cout << "name a file: ";                             //request filename 
  textRecord.userInput = "text.txt";                   //delete before production
  //cin >> textRecord.userInput;                       //take userinput as a string
  cout << "file is " << textRecord.userInput << endl;  //confirm selection
  inputName = textRecord.userInput.c_str();            //convert the input to a c string, worth checking to see if this is necesary

  //the block below is for parsing words
  inData.open(inputName);                              //opening a new fileparse block for word counting
  //ideal parsing method (from stream, not from your c stringw:q
  while(( char_buffer = inData.get()) != EOF)          // .get() the filstream, assign it the name char_buffer. Stop condition is when we reach EOF
  {
    if (inData.good() != true)                         //If the read fails 
    {
      cout <<"file is bad" << endl;
      if (wip == true)                                 //if a word is in progress
      {
        wip = false;                                   //stop counting words
        word_count++;                     
        handle_word(word_buffer, textRecord.keyword_index);                     
      }
    }
    else                                               // if the read is good (parse content for words)
    {
      if (char_buffer == '\n') ++lines;                //if we just read EOL, increment the line number
      if (isspace(char_buffer) > 0 )                   //if we just read whitespsace
      {
        if(wip == true )                               //if a word was being read and we previously just read  whitespace
        {
          word_count++;                                //that would mean we've read the start of a word, increment word_count
          wip = false;                                 //a word has been located
          handle_word(word_buffer, textRecord.keyword_index);                    //flashing 
        } 
      }
      else                                             //if we just read non-whitespace (like a letter or punctuation?)
      {
        if (wip == true)                               //if we're in the middle of parsing a word
        {
          if (write_ptr < (max_word_ln - 1))           //and we haven't exceeded the character limit for word
          {
            word_buffer[write_ptr++] = char_buffer;    //keep adding letters to the character buffer
          }
        }
        else                                           //if we're not in the middle of word|aka new word!
        {
          wip = true;                                  //turn wip on!
          write_ptr = 0;                               //reset word pointer bc new word
          for (int index = 0; index < max_word_ln; index++)
            word_buffer[index] = '\0';                 //empty the word buffer to prepare for the new word
          word_buffer[write_ptr++] = char_buffer;      //write the new word to the word buffer
        }
      }
    } 
  }
  inData.close();

  cout << setw(5) << setfill(' ') <<  "number of lines is " << lines << " "
    << setw(5) << setfill(' ') <<  "number of words is " << word_count << endl;
  return 0;
}

void handle_word(char word[], char kw_index[][max_word_len]) //i'm thinking this hsould be a struct funciton aka it returns the updated struct
{
  char c_buffer = '\0';
  int kw_index_pos = 0; //for going through the word list
  bool add = true;                   
  int wordLen = strlen(word);    

  while(strcmp(word, kw_index[kw_index_pos]) != 0)     //while the word fails to match
    do
    {
      kw_index_pos++;                                  //go through the struct
    };
    //then mark the match in KW index that we got a thing


    //compare word with letter by letter
    if(strcmp(word, kw_index[kw_index_pos]) == 0)        //if the word matches the first one
    {
      //figure out it's line number
    }
    else
    {
      // cout << "1st strcmp failed :)" << endl;
      if(strcmp(word, kw_index[kw_index_pos++]) == 0) //if the word matches the next word
      {
        //figure out its line number
      }
      while()
        do
        {
          //comparison 
        };

    }

} 
