//file upload + keywordin
#include "main.h"

using namespace std;

int main() 
{
  string userInput, ugh, inputName ;
  ifstream inData;
  txtRecord textRecord;

  //cout << "name a file: ";
  //cin >> textRecord.userInput;
  textRecord.userInput = "short.txt"; //uncomment above two lines+delete this one before production

  cout << "file is " << textRecord.userInput << endl;

  inputName = textRecord.userInput.c_str();

  inData.open(inputName);

  char c;
  int address = 0;
  int lines = 0;
  while(inData.get(c)) //using a while loop bc we don't know how long the text will be
  {
    textRecord.contents[address] = c; //putting it in by char to account for spaces
    address++;  
  }

  inData.close(); //is there a way to cleanly run multiple loops? this is the only way I know to flush this buffer
  inData.open(inputName);

  while(!inData.eof())
  {
    if(getline(inData, ugh )) //this is our linecounting logic, still need to situate it
    {
      ++lines;
      //  cout << ugh << "*" << endl; //how do you want to parse for last char
    }
  };
  inData.close();

  inData.open(inputName);
  //parse for words!!

  int wholeLen = static_cast< int >(strlen(textRecord.contents)); //we get awful sign/unsign ereror withou static cast 
  for(int i = 0; i < wholeLen; i++) //a single traversal through the text should work
  {
    int wordCountIndex = 0; //figured we could have it in this scope because it's likely not used anywhere else
    if(textRecord.contents[i] != 32) //if char != space because words exist between spaces and sentence-ending puncatuation
    {
      textRecord.kwIndex[wordCountIndex][i] = textRecord.contents[i]; //how are we suppoesd to prase ending punctuation
    }

    //for(int i = 0; i < wordLen; i++)
    //{
    //  cout << textRecord.kwIndex[wordCountIndex]
    // }
    // cout << textRecord.kwIndex[wordCountIndex][i];
  }

  cout << "number of lines is " << lines << endl;
  cout << "total chars is " << address << endl;
  cout << "first line is x chars long " << endl;
  //for(int i = 0; i < strlen(textRecord.contents); i++) //word count logic goes in here to separate concerns
  //{
  // cout << textRecord.contents[i];
  //}

  inData.close();
  return 0;
}

