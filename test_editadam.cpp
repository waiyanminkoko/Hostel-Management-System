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
char Ehall; //E for edit 
string Ename;
int Efloor, Eroom; //E for edit 

    bool checkname = 0, LOOP, option;

    cout << "Enter name whose data is to be edited : ";

    cin >> Ename;

    cout << "Enter " << Ename << "'s new Hall, Floor, and Room number : \n";

    cin >> Ehall >> Efloor >> Eroom;

    string name, roomtype, typeofguest, checkin, checkout, email, phonenumber; 
    char hall;
    int floor, room;

    ifstream inFile;

    ofstream outFile;

    inFile.open("Guest Room Allocation.txt"); //Oringinal File 

    outFile.open("temp.txt"); //Temperary File to store edited details 

    if (!inFile)

    {
        cout << "Unable to open file" << endl;
    }

    else  if (!outFile)

        cout << "Unable to open file\n";

    else

    {
        while (!inFile.eof())

        {
            inFile >> name >> roomtype >> typeofguest >> checkin >> checkout >> email >> phonenumber >> hall >> floor >> room; //>> leave; //input 

            if (inFile.fail()) break;//error handling 

            if (name == Ename)

            {

                hall = Ehall;

                floor = Efloor;

                room = Eroom;

                checkname = 1; //Figure out how to create error handling for incorrect names.!!!! 
            }
            cout <<left << setw(25) << name << setw(20) << roomtype << setw(25) << typeofguest << setw(20) << checkin << setw(20) << checkout << setw(30)
                            << email << setw(20) << phonenumber << hall << setw(10) << floor << room <<  endl << flush;
            outFile <<left << setw(25) << name << setw(20) << roomtype << setw(25) << typeofguest << setw(20) << checkin << setw(20) << checkout << setw(30)
                            << email << setw(20) << phonenumber << hall << setw(10) << floor << room <<  endl << flush;
        }

    }

    inFile.close();

    outFile.close();
}