#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
int Menu();
void printLine(int i);
void BoarderRoom();




int main() {
ifstream inFile;
ofstream outFile;

inFile.open("Books.txt");
outFile.open("Books_saved.txt");
    string serial_number;
    char u_a;
    string title;
    if (!inFile) {
        cout << "Error opening file.";
    }
    else if (!outFile){
        cout << "Error opening file.";
    }
    else {
        //continue code
    
    cout << "******Books******" << endl;
    cout << left<<setw(20) << "Serial Number" << setw(35) << "Title"<< "U/A" << endl; //Output titles

    while (!inFile.eof()){ // read data and go through algorithms
        inFile>> serial_number >> title >> u_a;
        if(inFile.fail()) {break;}
        cout << setw(20) << serial_number << setw(35)  << title << u_a << endl;
        outFile << left << setw(20) << serial_number << setw(35)  << title << u_a << endl;
    }
       
    }

inFile.close();
}