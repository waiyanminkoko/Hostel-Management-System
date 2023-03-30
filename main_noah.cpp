#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <fstream>
#include <Windows.h>
using namespace std;
void printLine(int i);
void Booking();
void GuestRoom();
void CurrentGuests();
bool BoarderDetails();
void BoarderRoom();
void SegregatedBoarders();
void Cleaning();
void Defect();
bool AddBoarder();
bool EditBoarder();
bool RemoveBoarder();
bool ReturnOption();
bool AddUser();
bool RemoveUser();
bool ChangePassword();
bool Login();


int main()
{
    int choice;
    cout << fixed << left;
    int LOOP = 0, LOGIN;


        system("CLS");
        printLine(60);
        cout << "ABC School Management System" << endl;
        printLine(60);
        cout << endl;
        LOGIN = Login();
        if (LOGIN == 1)
        {
            while (LOOP == 0)
            {
                system("CLS");
                printLine(60);
                cout << "ABC School Management System" << endl;
                printLine(60);
                cout << "Main Menu" << endl << endl;
                cout << "1. Booking History/Listings" << endl;//kai
                cout << "2. Guest Room Allocations" << endl;//adam
                cout << "3. Current Guests" << endl;//kai
                cout << "4. Boarders Details" << endl; //noah
                cout << "5. Boarder Room Allocations" << endl; //waiyan
                cout << "6. Segregated Boarders Room Allocations" << endl; //noah
                cout << "7. Cleaning Schedule" << endl;//uc
                cout << "8. Defect Reports" << endl;//uc
                cout << "9. Exit" << endl;
                cout << "10. User Account" << endl;

                cout << "Option: ";
                cin >> choice;

                while (choice < 1 || choice > 10) {
                    cout << "Option: ";
                    cin >> choice;
                }

                if (choice == 1) {
                    Booking();
                }
                else if (choice == 2) {
                    GuestRoom();
                }
                else if (choice == 3) {
                    CurrentGuests();
                }
                else if (choice == 4) {
                    LOOP = BoarderDetails();
                }
                else if (choice == 5) {
                    BoarderRoom();
                }
                else if (choice == 6) {
                    SegregatedBoarders();
                }
                else if (choice == 7) {
                    Cleaning();
                }
                else if (choice == 8) {
                    Defect();
                }
                else if (choice == 10) {
                    LOOP = AddUser();
                }
                else {
                    cout << "Exit Program" << endl;
                    return 0;
                }
            }
        }
}

void printLine(int i) 
{
    char line = 205;
    for (int j = 0; j < i; j++) 
    {
        cout << line ;   
    } 
    cout << endl;
}

void Booking() {
    
    cout << setw(25) << "Date & Time: " << setw(20) << "Name" << setw(20) << "Room Type" << setw(20) << "Type of Guests" << setw(20) << "Check-In" << setw(20) << "Check-Out" << setw(20) << "Email" << "Phone Number"<< endl; 
    
}

void GuestRoom() {
    
    cout << setw(25) << "Name" << setw(20) << "Room Type" << setw(20) << "Type of Guests" << setw(20) << "Check-In" << setw(20) << "Check-Out" << setw(20) << "Email" << "Phone Number" << setw(20) << "Cluster/Room" << endl; 
    
}
void CurrentGuests(){

    cout << setw(25) << "Name" << setw(20) << "Room Type" << setw(20) << "Type of Guests" << setw(20) << "Check-In" << setw(20) << "Check-Out" << setw(20) << "Email" << "Phone Number" << setw(20) << "Cluster/Room" << endl;

}

bool BoarderDetails() 
{
    system("CLS");
    printLine(100);
    cout << "Boarder Details\n";
    printLine(100);
    int option;
    bool LOOP = 1;
    string name, level, type, nation, school, leave;
    char gender;
    cout << setw(25) << "Name" << setw(20) << "Gender" << setw(20) << "Level" << setw(20) << "Type" << setw(20) << "Nationality" << /*setw(20)  <<*/ "School" << /*"Leave Status"<< */endl;
    ifstream inFile;
    inFile.open("C:\\Users\\Noah\\OneDrive\\SP WORK\\sem2\\cprog\\C++\\cprog project\\Boarders Details.txt");
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
            cout << setw(25) << name << setw(20) << gender << setw(20) << level << setw(20) << type << setw(20) << nation << /*setw(20) <<*/ school << /*leave <<*/ endl;
          
        }
        
    }
    inFile.close();
    printLine(100);
    cout << "\n1. Edit data\n2. Add data\n3. Delete data\n4. Return to main menu\nOption : ";
    cin >> option;
    while (option <= 0 || option >= 5)
    {
        
        cout << "Option " << option << " is unavailable\n" << "Please enter again : ";
        cin >> option;
    }
    if (option == 1)
    {
        //edit file 
        LOOP = EditBoarder();
    }
    else if (option == 2)
    {
        //add data
        LOOP = AddBoarder();
        

    }
    else if (option == 3)
    {
        //delete data
        LOOP = RemoveBoarder();
    }
    else if (option == 4)
    {
        //back to main menu
        cout << "Returning to main menu";
        for (int i = 0; i < 5; i++)
        {
            cout << ".";
            Sleep(100);
        }
        system("CLS");
        LOOP = 0;
    }
    return LOOP;
}
bool EditBoarder()
{
    printLine(100);
    cout << "Edit Boarder Details\n";
    printLine(100);
    string Ename, Elevel, Etype, Enation, Eschool, Eleave; //E for edit
    char Egender;
    bool checkname = 0, LOOP, option;
    cout << "Enter name whose data is to be edited : ";
    cin >> Ename;
    cout << "Enter " << Ename << "'s new gender, level, type, nationality, school : \n";
    cin >> Egender >> Elevel >> Etype >> Enation >> Eschool;
    string name, level, type, nation, school, leave;

    char gender;
    ifstream inFile;
    ofstream outFile;
    inFile.open("C:\\Users\\Noah\\OneDrive\\SP WORK\\sem2\\cprog\\C++\\cprog project\\Boarders Details.txt"); //Oringinal File
    outFile.open("C:\\Users\\Noah\\OneDrive\\SP WORK\\sem2\\cprog\\C++\\cprog project\\temp.txt", ofstream::out); //Temperary File to store edited details
    if (!inFile || !outFile)
    {
        cout << "Unable to open file" << endl;
    }
    else
    {
        while (!inFile.eof())
        {
            inFile >> name >> gender >> level >> type >> nation >> school; //>> leave; //input
            if (inFile.fail()) break;//error handling
            if (name == Ename)
            {
                gender = Egender;
                level = Elevel;
                type = Etype;
                nation = Enation;
                school = Eschool;
                checkname = 1; //Figure out how to create error handling for incorrect names.COMPLETED
            }
            outFile << name << "\t" << gender << "\t" << level << "\t" << type << "\t" << nation << "\t" << school << "\t\n";
        }
        if (checkname == 0)
        {
            cout << Ename << " cannot be found.";
        }
    }
    if (checkname == 1)
    {
        inFile.close();
        outFile.close();
        //User check to see if file is edited properly.
        system("CLS");
        printLine(100);
        cout << "Edit User Account\n";
        printLine(100);
        cout << "Below is the edited file\n";
        printLine(100);
        cout << setw(25) << "Name" << setw(20) << "Gender" << setw(20) << "Level" << setw(20) << "Type" << setw(20) << "Nationality" << /*setw(20)  <<*/ "School" << /*"Leave Status"<< */endl;
        inFile.open("C:\\Users\\Noah\\OneDrive\\SP WORK\\sem2\\cprog\\C++\\cprog project\\temp.txt");//opens temp file for user checking
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
                cout << setw(25) << name << setw(20) << gender << setw(20) << level << setw(20) << type << setw(20) << nation << /*setw(20) <<*/ school << /*leave <<*/ endl;

            }

        }
        inFile.close();
        printLine(100);
        cout << "Enter 0 to save file\nEnter 1 to revert back to the original file\nOption : ";
        cin >> option;

        //below - transfer edited data from temp file to original file - save file
        if (option == 0)
        {
            remove("C:\\Users\\Noah\\OneDrive\\SP WORK\\sem2\\cprog\\C++\\cprog project\\Boarders Details.txt"); //TAKEN FROM movieTheatre.cpp from blackboard.
            rename("C:\\Users\\Noah\\OneDrive\\SP WORK\\sem2\\cprog\\C++\\cprog project\\temp.txt", "C:\\Users\\Noah\\OneDrive\\SP WORK\\sem2\\cprog\\C++\\cprog project\\Boarders Details.txt");
            /*inFile.close();
            outFile.close();
            inFile.open("C:\\Users\\Noah\\OneDrive\\SP WORK\\sem2\\cprog\\C++\\cprog project\\temp.txt");
            outFile.open("C:\\Users\\Noah\\OneDrive\\SP WORK\\sem2\\cprog\\C++\\cprog project\\Boarders Details.txt", ofstream::out);
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
                    inFile >> name >> gender >> level >> type >> nation >> school; //>> leave; //input
                    if (inFile.fail()) break;//error handling
                    outFile << name << "\t" << gender << "\t" << level << "\t" << type << "\t" << nation << "\t" << school << "\t\n";
                }
            }
            inFile.close();
            outFile.close();*/
            cout << "File saved.";
            LOOP = ReturnOption();

        }
        else
        {
            cout << "Edit is deleted. File is reverted back to original.";
            LOOP = ReturnOption();
        }
    }
    return LOOP;
}
bool AddBoarder()
{
    printLine(100);
    cout << "Add Boarder Details\n";
    printLine(100);
    ofstream outFile;
    string name, level, type, nation, school, leave;
    char gender;
    bool LOOP;
    cout << "Enter name, gender, level, type, nationality, school : \n";
    cin >> name >> gender >> level >> type >> nation >> school;
    outFile.open("C:\\Users\\Noah\\OneDrive\\SP WORK\\sem2\\cprog\\C++\\cprog project\\Boarders Details.txt", ofstream::app);
    if (!outFile)
        cout << "Unable to open file\n";
    else
    {
        cout << "Adding the following :\n" << left << setw(25) << name << setw(20) << gender << setw(20) << level << setw(20) << type << setw(20) << nation << school;
        outFile << name <<"\t" << gender << "\t" << level << "\t" << type << "\t" << nation << "\t" << school << "\t\n";
    }
    outFile.close();
    LOOP = ReturnOption();
    return LOOP;
}

bool RemoveBoarder()
{
    printLine(100);
    cout << "Remove Boarder Details\n";
    printLine(100);
    bool checkname = 0, LOOP;
    string Ename; //E for edit
    cout << "Enter name whose data is to be deleted : ";
    cin >> Ename;
    string name, level, type, nation, school, leave, gender;
    ifstream inFile;
    ofstream outFile;
    inFile.open("C:\\Users\\Noah\\OneDrive\\SP WORK\\sem2\\cprog\\C++\\cprog project\\Boarders Details.txt"); //Oringinal File
    outFile.open("C:\\Users\\Noah\\OneDrive\\SP WORK\\sem2\\cprog\\C++\\cprog project\\temp.txt", ofstream::out); //Temperary File to store edited details
    if (!inFile || !outFile)
    {
        cout << "Unable to open file" << endl;
    }
    else
    {
        while (!inFile.eof())
        {
            inFile >> name >> gender >> level >> type >> nation >> school; //>> leave; //input
            if (inFile.fail()) break;//error handling
            if (name == Ename)
            {
                name = "";
                gender = "";
                level = "";
                type = "";
                nation = "";
                school = "";
                outFile << name << gender << level << type << nation << school<< "\n";
                checkname = 1; 
            }
            outFile << name << "\t" << gender << "\t" << level << "\t" << type << "\t" << nation << "\t" << school << "\n";
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
        inFile.open("C:\\Users\\Noah\\OneDrive\\SP WORK\\sem2\\cprog\\C++\\cprog project\\temp.txt");//opens temp file for user checking
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
                cout << setw(25) << name << setw(20) << gender << setw(20) << level << setw(20) << type << setw(20) << nation << /*setw(20) <<*/ school << /*leave <<*/ endl;

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
            remove("C:\\Users\\Noah\\OneDrive\\SP WORK\\sem2\\cprog\\C++\\cprog project\\Boarders Details.txt"); //TAKEN FROM movieTheatre.cpp from blackboard.
            rename("C:\\Users\\Noah\\OneDrive\\SP WORK\\sem2\\cprog\\C++\\cprog project\\temp.txt", "C:\\Users\\Noah\\OneDrive\\SP WORK\\sem2\\cprog\\C++\\cprog project\\Boarders Details.txt");
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

bool ReturnOption()
{
    cout << "\n";
    printLine(100);
    bool option;
    cout << "Enter 0 to return to the main menu\nEnter 1 to exit program\nOption : ";
    cin >> option;
    if (option == 0)
    {
        cout << "Returning to main menu";
        for (int i = 0; i < 5; i++)
        {
            cout << ".";
            Sleep(100);
        }
        system("CLS");
    }
    return option;
} 

bool Login()
{
    string username, password, Tusername, Tpassword; //T for Text file data
    bool Cusername = 0, Cpassword = 0, correctlogin = 0, falsePW = 1, falseACC = 1; //C for CHeck
    while (falseACC == 1)
    {
        cout << "Please enter username : ";
        cin >> username;
        falsePW = 1;


        while (falsePW == 1)
        {
            cout << "Please enter password : ";
            cin >> password;
            ifstream inFile;
            inFile.open("User Accounts.txt");
            if (!inFile) { cout << "Unable to open file\n"; }
            else
            {
                while (!inFile.eof())
                {
                    inFile >> Tusername >> Tpassword;
                    if (Tusername == username)
                    {
                        Cusername = 1;
                        if (Tpassword == password)
                        {
                            Cpassword = 1;
                            break;
                        }
                        else
                        {
                            Cpassword = 0;
                            break;
                        }
                    }
                    else Cusername = 0;
                }
            }
            inFile.close();
            if (Cusername == 1 && Cpassword == 0)
            {
                cout << "Incorrect password.\n";
                falsePW = 1;
            }
            else if (Cusername == 1 && Cpassword == 1)
            {
                correctlogin = 1;
                falsePW = 0;
                falseACC = 0;
            }
            else if (Cusername == 0)
            {
                cout << "Account not found.\n";
                falsePW = 0;
                falseACC = 1;
            }
        }
    }
    return correctlogin;
}

bool AddUser()
{
    int choice;
    bool LOGIN, LOOP;
    system("CLS");
    printLine(100);
    cout << "User Accounts\n";
    printLine(100);
    cout << "1. Add user account\n2. Remove user account\n3. Change password\n4. Return to main menu\nOption : ";
    cin >> choice;
    while (choice <= 0 || choice >= 5)
    {
        cout << "Option " << choice << " is unavailable\n" << "Please enter again : ";
        cin >> choice;
    }
    if (choice == 1)//ADD ACCOUNT
    {
        cout << "To add user account, please login again.\n";
        LOGIN = Login();
        system("CLS");
        printLine(100);
        cout << "Add User Account\n";
        printLine(100);
        if (LOGIN == 1)
        {
            string username, password;
            cout << "Please enter NEW username : ";
            cin >> username;
            cout << "Please enter NEW password : ";
            cin >> password;
            ofstream outFile;
            outFile.open("User Accounts.txt", ofstream::app);
            if (!outFile) { cout << "Unable to open file\n"; }
            else
            {
                cout << "Adding the following\nUsername : " << username << "\nPassword : " << password;
                outFile << username << "\t" << password << "\t\n";
            }
            outFile.close();
        }
        LOOP = ReturnOption();
        
    }
    else if (choice == 2) //REMOVE ACCOUNT
    {
        LOOP = RemoveUser();
       
    }
    else if (choice == 3) //CHANGE PASSWORD
    {
        LOOP = ChangePassword();
    }
    else
    {
        cout << "Returning to main menu";
        for (int i = 0; i < 5; i++)
        {
            cout << ".";
            Sleep(100);
        }
        system("CLS");
        LOOP = 0;
    }
    return LOOP;
}

bool RemoveUser()
{
    cout << "To remove user account, please login again.\n";
    bool LOGIN, LOOP;
    LOGIN = Login();
    system("CLS");
    cout << "Remove User Account\n";
    printLine(100);
    if (LOGIN == 1)
    {
        bool findacc = 0;
        string username, Fusername, Fpassword; //F for FILE
        cout << "Please enter username of account to be deleted : ";
        cin >> username;
        ifstream inFile;
        ofstream outFile;
        inFile.open("User Accounts.txt"); //Oringinal File
        outFile.open("temp.txt", ofstream::out); //Temperary File to store edited details
        if (!inFile || !outFile)
        {
            cout << "Unable to open file" << endl;
        }
        else
        {
            while (!inFile.eof())
            {
                inFile >> Fusername >> Fpassword; //>> leave; //input
                if (inFile.fail()) break;//error handling
                if (Fusername == username)
                {
                    Fusername = "";
                    Fpassword = "";
                    outFile << Fusername << Fpassword;
                    findacc = 1;
                }
                else
                {
                    outFile << Fusername << "\t" << Fpassword << "\n";
                }
            }
            if (findacc == 0)
            {
                cout << "Account not found.\n";
            }
        }
        if (findacc == 1)
        {
            inFile.close();
            outFile.close();
            //User check to see if file is edited properly.
            system("CLS");
            printLine(100);
            cout << "Remove User Account\n";
            printLine(100);
            cout << "\n" << username << "'s account have been deleted.\n";
            remove("User Accounts.txt"); //TAKEN FROM movieTheatre.cpp from blackboard.
            rename("temp.txt", "User Accounts.txt");  
        }
        LOOP = ReturnOption();
        return LOOP;
    }
}

bool ChangePassword()
{
    system("CLS");
    string currUSER, changedPW, USERnPW, username, password;
    printLine(100);
    cout << "Change Password\n";
    printLine(100);
    cout << "To change password, please login again\n";
    bool LOGIN, LOOP;
    LOGIN = Login();
    if (LOGIN == 1)
    {
        system("CLS");
        printLine(100);
        cout << "Change Password\n";
        printLine(100);
        cout << "Please enter username followed by new password : ";
        cin >> currUSER >> changedPW;
        ifstream inFile;
        ofstream outFile;
        inFile.open("User Accounts.txt"); //Oringinal File
        outFile.open("temp.txt", ofstream::out); //Temperary File to store edited details
        if (!inFile || !outFile)
        {
            cout << "Unable to open file" << endl;
        }
        else
        {
            while (!inFile.eof())
            {
                inFile >> username >> password; //>> leave; //input
                if (inFile.fail()) break;//error handling
                if (username == currUSER)
                {
                    password = changedPW;
                }
                outFile << username << "\t" << password << "\n";
            }
        }
        inFile.close();
        outFile.close();
        cout << "Password for " << currUSER << " has been changed.\n";
        remove("User Accounts.txt"); //TAKEN FROM movieTheatre.cpp from blackboard.
        rename("temp.txt", "User Accounts.txt");
        LOOP = ReturnOption();
        return LOOP;
    }
}

void BoarderRoom() {
  
    cout << setw(25) << "Name" << setw(20) << "Level"<< setw(20) << "Type" << setw(20) << "Nationality"<< setw(20) << "School"  << "Cluster/Room" << endl;

}

void SegregatedBoarders() {

    cout << setw(25) << "Name" << setw(20) << "Level"<< setw(20) << "Type" << setw(20) << "Nationality"<< setw(20) << "School"  << setw(20) << "Cluster/Room" << "Old Cluster/Room" << endl;

}

void Cleaning() {

    cout << "Coming Soon" << endl;

}

void Defect() {

    cout << "Coming Soon" << endl;

}