//file upload + keywordin
#include "main.h"

using namespace std;

int main() 
{
  string buffer, userInput, ugh, inputName ;
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
      ++lines; //  cout << ugh << "*" << endl; //how do you want to parse for last char
    }
  };
  inData.close();

  inData.open(inputName);
  //parse for words!!

  while(inData.good() == true && inData.peek() != EOF) 
  {
   inData >> buffer;
   if(inData.good() != true) continue;
   cout << "Word is :" << buffer << endl;
  }




  cout << "number of lines is " << lines << endl;
  cout << "total chars is " << address << endl;
  cout << "first line is x chars long " << endl;

  inData.close();
  return 0;
}

