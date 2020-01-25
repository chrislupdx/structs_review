//file upload + keywordin
//sources: 162 demo_2/demo_3
#include "main.h"

using namespace std;

int main() 
{
  string userInput, ugh, inputName ;
  int word_count = 0; //counts the number of words in file
  bool wip = false;
  ifstream inData; //input stream
  txtRecord textRecord; //struct that stores userinput, kwIndex and the text as c string
  const int max_word_ln = 100;
  char word_buffer[max_word_ln]; //buffer for word being parsed
  
  cout << "name a file: ";
  textRecord.userInput = "text.txt"; //delete before production
  //cin >> textRecord.userInput;
  cout << "file is " << textRecord.userInput << endl;

  inputName = textRecord.userInput.c_str();

 // inData.open(inputName);
  char char_buffer = '\0'; //what is this for
  int address = 0; //whaat is this for
  int lines = 0; //what is this for
  //this first block below exists to extract the entire text and store it in one big c string bc it might be useful
 // while(inData.get(c)) //using a while loop bc we don't know how long the text will be
 // {
 //   textRecord.contents[address] = c; //putting it in by char to account for spaces
 //   address++; //increment index 
 // }
 // inData.close(); //is there a way to cleanly run multiple loops? this isn't the only way I know to flush this buffer


  //the block below is for counting lines
  inData.open(inputName); //open the stream again
  while(!inData.eof()) 
  {
    if(getline(inData, ugh )) //this is our linecounting logic, still need to situate it
    {
      ++lines;
      //cout << ugh << "*" << endl; //how do you want to parse for last char
    }
  };
  inData.close();

  //opening a new fileparse block for word counting
  inData.open(inputName);
  //ideal parsing method (from stream, not from your c stringw:q
  while(( char_buffer = inData.get()) != EOF)
  {
  if (inData.good() != true)   //If the read fais
  {
    if (wip == true)
    {
      wip = false;
      word_count++;
      //we in theory have access to the word 
    }
    //read words here
  }
  if (char_buffer == ' ')
    {
      cout << char_buffer;
    }
  if (char_buffer == '\n')
    {
      cout << "newline" << endl;
    }
  cout << char_buffer;
  }

  cout << "number of lines is " << lines << endl;

  //for(int i = 0; i < strlen(textRecord.contents); i++) //word count logic goes in here to separate concerns
  //{
  // cout << textRecord.contents[i];
  //}

  return 0;
}

