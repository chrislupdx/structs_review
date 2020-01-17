//file upload + keywordin
#include "main.h"

using namespace std;

int main() {
string userInput, fileOutput, inputName ;
ifstream inData;
susan textRecord;

cout << "name a file: ";
cin >> textRecord.userInput;
cout << "file is " << textRecord.userInput << endl;
inputName = textRecord.userInput.c_str();


inData.open(inputName);
inData >> fileOutput;
do
{
cout << fileOutput;

}
while(inData >> fileOutput);

return 0;
}
