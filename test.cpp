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
 
    bool RemoveBoarder()
{
    printLine(100);
    cout << "Remove Boarder Details\n";
    printLine(100);
    bool checkname = 0, LOOP;
    string Ename; //E for edit
    cout << "Enter name whose data is to be deleted : ";
    cin >> Ename;
    string name, level, type, nation, school, gender;
    ifstream inFile;
    ofstream outFile;
    inFile.open("Boarders Details.txt"); //Oringinal File
    outFile.open("temp_boarderdetails.txt", ofstream::out); //Temperary File to store edited details
    if (!inFile || !outFile)
    {
        cout << "Unable to open file" << endl;
    }
    else
    {
        while (!inFile.eof())
        {
            inFile >> name >> gender >> level >> type >> nation >> school;//input
            if (inFile.fail()) break;//error handling
            if (name == Ename)
            {
                name = "";
                gender = "";
                level = "";
                type = "";
                nation = "";
                school = "";
                outFile << left << setw(24) << name << setw(8) << gender << setw(16) << level << setw(16) << type << setw(8) << nation << school << endl;
                checkname = 1; 
            }
            outFile << left << setw(24) << name << setw(8) << gender << setw(16) << level << setw(16) << type << setw(16) << nation << school << endl;
            
        }
        if (checkname == 0)
        {
            cout << "Account not found.\n";
        }
    }
    inFile.close();
    outFile.close();
    if (checkname == 1)
    {
        //User check to see if file is edited properly.
        system("CLS");
        printLine(100);
        cout << "Remove Boarder Details\n";
        printLine(100);
        cout << "Below is the edited file\n";
        printLine(100);
        cout << setw(25) << "Name" << setw(20) << "Gender" << setw(20) << "Level" << setw(20) << "Type" << setw(20) << "Nationality" << /*setw(20)  <<*/ "School" << /*"Leave Status"<< */endl;
        inFile.open("temp_boarderdetails.txt");//opens temp file for user checking
        if (!inFile)
        {
            cout << "Unable to open file" << endl;
        }
        else
        {
            while (!inFile.eof())
            {

                inFile >> name >> gender >> level >> type >> nation >> school; //>> leave; //input
                if (inFile.fail()) break;//error handling
                cout << setw(25) << name << setw(20) << gender << setw(20) << level << setw(20) << type << setw(20) << nation <<  school <<  endl;

            }

        }
        inFile.close();
        printLine(100);
        bool option;
        cout << "Enter 0 to save file\nEnter 1 to revert back to the original file\nOption : ";
        cin >> option;

        //below - transfer edited data from temp file to original file - save file
        if (option == 0)
        {
            remove("Boarders Details.txt"); //TAKEN FROM movieTheatre.cpp from blackboard.
            rename("temp_boarderdetails.txt", "Boarders Details.txt");
            cout << "File saved.";
            LOOP = ReturnOption();

        }
        else
        {
            cout << "Edit is deleted. File is reverted back to original.";
            LOOP = ReturnOption();
        }
        return LOOP;
    }
    
}
    
}

