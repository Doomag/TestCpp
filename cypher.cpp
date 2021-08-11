#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void createMessage();
void decodeFile();

int main () {
    
    int selection;
    do {
      
    cout << ("----------------------") << endl;
    cout << ("         Menu         ")<< endl;
    cout << ("----------------------") << endl;
    cout << ("1: create message") << endl;
    cout << ("2: deciper message") << endl;
    cout << ("3: Exit") << endl;
    cin >> selection;
    
switch(selection) {
    case 1: createMessage();break;
    case 2: decodeFile();break;
    case 3: break;
    default: ;
    }
    
} while(selection!=3);

cout << "Thank you";
  
return 0;
}



void createMessage(){
    // ask for the name of the file
    string fileName;
    cout << ("Choose a name for the file: ") << fileName << endl;
    cin >> fileName;
    
    // Create the file if doesn't exist.
    fstream codedFile;
    codedFile.open(fileName, ios::out);
    codedFile.close();

    // Ask for how many letter to encode. 
    int sizeArray;
    cout << "How many letters has your message?: " << endl;
    cin >> sizeArray;

    // Create a dynamic array.
    char* myArray = new char[sizeArray];

    // Ask for the letter and write into the file.
    for (int i=0; i<sizeArray; i++) {
        codedFile.open(fileName, ios::app);
        cout << "Insert " << i+1 << " letter: " << endl;
        if (codedFile.is_open()) {
            cin >> myArray[i];
            codedFile << int(myArray[i]) << endl;
            codedFile.close();
        }
}


void decodeFile() {

      // ask for the name of the file
    string fileName;
    cout << ("Choose a name for the file: ") << fileName << endl;
    cin >> fileName; 

// read from the file, and print the decoded message
    codedFile.open(fileName, ios::in);
    if (codedFile.is_open()){
        string line;
        while (getline(codedFile, line)){
            int letter= stoi(line); // use std::stoi function for convert string into int
            cout << char(letter);
        }
        codedFile.close();
    }

}