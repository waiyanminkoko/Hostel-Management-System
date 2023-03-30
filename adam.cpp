#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
using namespace std;
bool ReturnOption();
void printLine(int i);
void SearchGuest();
void EditGuestRoom();
int main()
{
	
    string name, roomtype, typeofguest, checkin, checkout, email, phonenumber;
    char hall; 
    int roomF = 0, floorF = 1, roomG = 0, floorG = 1;
	int option;
	
    ifstream inFile;
    ofstream outFile;
    inFile.open("Booking List.txt");
    outFile.open("Guest Room Allocation.txt");
    
    if (!inFile)
    {
        cout << "Unable to open file" << endl;
    }
    else  if (!outFile){
        cout << "Unable to open file\n";
    }
    
    cout << left<< setw(25) << "Name" << setw(20) << "Room Type" << setw(25) << "Type of Guest" << setw(20) << "Check-in" << setw(20) << "Check-out"
        << setw(30) << "Email" << setw(20) << "Phone Number" << "hall, Floor,Room num" << endl;
    outFile << left;
    while (!inFile.eof())
    {
        inFile >> name >> roomtype >> typeofguest >> checkin >> checkout >> email >> phonenumber;
        if (inFile.fail()) {break;}

        if (typeofguest == "Short-Term_Guest")   
        {
            hall = 'F';
            if (roomF >= 0 && roomF <= 10) 
            {
                roomF++;
            }
            else if (roomF > 10) 
            {
                floorF++;
                roomF = 1;
            }
            cout << setw(25) << name << setw(20) << roomtype << setw(25) << typeofguest << setw(20) << checkin << setw(20) << checkout << setw(30)
                        << email << setw(20) << phonenumber << hall << floorF << "(" << roomF << ")" <<  endl;
                    
            outFile << setw(25) << name << setw(20) << roomtype << setw(25) << typeofguest << setw(20) << checkin << setw(20) << checkout << setw(30)
                        << email << setw(20) << phonenumber << hall << setw(10) << floorF << roomF  <<  endl << flush;
        }
        else if (typeofguest == "Long-Term_Guest" || typeofguest == "University_Student")
        {
            hall = 'G';
            if (roomG >= 0 && roomG <= 10) 
            {
                    roomG++;
            }
            else if (roomG > 10) 
            {
                floorG++;
                roomG = 1;
            }
            cout << setw(25) << name << setw(20) << roomtype << setw(25) << typeofguest << setw(20) << checkin << setw(20) << checkout << setw(30)
                            << email << setw(20) << phonenumber << hall << floorG << "(" << roomG << ")" <<  endl;
                        
            outFile << setw(25) << name << setw(20) << roomtype << setw(25) << typeofguest << setw(20) << checkin << setw(20) << checkout << setw(30)
                            << email << setw(20) << phonenumber << hall << setw(10) << floorG << roomG <<  endl << flush; 
                
        }
        else {
            cout << "Allocation Error!" << endl;
        }
    }
    inFile.close();
    outFile.close();

    cout << "1. Seach Guest\n2.Edit Room Allocation\n3. Exit\nOption: ";
    cin >> option;

    while (option < 1 && option > 3) {
        cout << "Invalid Input!\n1. Seach Guest\n2.Edit Room Allocation\n3. Exit\nOption: ";
        cin >> option;
    }
    if (option == 1) {
        SearchGuest();
        
    }
    else if (option == 2){
        EditGuestRoom();
    }
    else {
        ReturnOption();
    }

}

void SearchGuest(){
    
    ifstream inFile;
    string name, roomtype, typeofguest, checkin, checkout, email, phonenumber;
    char hall; 
    int room, floor;
    bool checkname = 0;
    string name_search;
    cout << "Enter Guest's Name: ";
    cin >> name_search;

    inFile.open("Guest Room Allocation.txt");
            
            if (!inFile){
                cout << "Error opening file." << endl;
            }
            else {//continue
            
            while (!inFile.eof()){   
                inFile >> name >> roomtype >> typeofguest >> checkin >> checkout >> email >> phonenumber >> hall >> floor >> room;
                if (inFile.fail()) break;//error handling
                if (name == name_search)
                {
                    checkname = 1;
                    cout << left<< setw(25) << "Name" << setw(20) << "Room Type" << setw(25) << "Type of Guest" << setw(20) << "Check-in" << setw(20) << "Check-out"
                    << setw(30) << "Email" << setw(20) << "Phone Number" << "Hall, Floor,Room num" << endl;
                    cout << setw(25) << name << setw(20) << roomtype << setw(25) << typeofguest << setw(20) << checkin << setw(20) << checkout << setw(30)
                    << email << setw(20) << phonenumber << hall << floor << "(" << room << ")" <<  endl;
                    
                }
            }

        if (checkname == 0)
        {
            cout << name_search << " cannot be found." << endl;
        }
                
    }
    inFile.close();

}

void EditGuestRoom()

{

    string Ename; 
    char Ehall;
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

            outFile <<left << setw(25) << name << setw(20) << roomtype << setw(25) << typeofguest << setw(20) << checkin << setw(20) << checkout << setw(30)
                            << email << setw(20) << phonenumber << hall << setw(10) << floor << room <<  endl << flush;
        }

    }

    inFile.close();

    outFile.close();

    //User check to see if file is edited properly. 

    system("CLS");

    cout << "Below is the edited file\n";

    printLine(100);

    cout << left<< setw(25) << "Name" << setw(20) << "Room Type" << setw(25) << "Type of Guest" << setw(20) << "Check-in" << setw(20) << "Check-out"
                    << setw(30) << "Email" << setw(20) << "Phone Number" << "Hall, Floor,Room num" << endl;

    inFile.open("temp.txt");

    if (!inFile)

    {

        cout << "Unable to open file" << endl;

    }

    else

    {

        while (!inFile.eof())

        {

            inFile >> name >> roomtype >> typeofguest >> checkin >> checkout >> email >> phonenumber >> hall >> floor >> room; //>> leave; //input 

            if (inFile.fail()) break;//error handling 

            cout << setw(25) << name << setw(20) << roomtype << setw(25) << typeofguest << setw(20) << checkin << setw(20) << checkout << setw(30)
                            << email << setw(20) << phonenumber << hall << floor << "(" << room << ")" << endl;

        }

    }

    inFile.close();

    printLine(100);

    cout << "Enter 0 to save file\nEnter 1 to revert back to the original file\nOption : ";

    cin >> option;

    //below - transfer edited data from temp file to original file - save file 

    if (option == 0)

    {

        inFile.close();

        outFile.close();

        inFile.open("temp.txt");

        outFile.open("Guest Room Allocation.txt", ofstream::out);

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

                inFile  >> name >> roomtype >> typeofguest >> checkin >> checkout >> email >> phonenumber >> hall >> floor >> room; //>> leave; //input 

                if (inFile.fail()) break;//error handling 

                outFile << setw(25) << name << setw(20) << roomtype << setw(25) << typeofguest << setw(20) << checkin << setw(20) << checkout << setw(30)
                            << email << setw(20) << phonenumber << hall << setw(10) << floor << room <<  endl << flush;

            }

        }

        inFile.close();

        outFile.close();

        cout << "File saved.";

        LOOP = ReturnOption();
    }

    else

    {
        cout << "Edit is deleted. File is reverted back to original.";

        LOOP = ReturnOption();
    }

    //return LOOP;

}

bool ReturnOption()

{
    cout << "\n";
    
    printLine(100);
    
    bool option;
    
    cout << "Enter 0 to return to the main menu\nEnter 1 to exit program\nOption : ";
    
    cin >> option;
    
    return option;
}
void printLine(int i) {
    for (int j = 0; j < i; j++) {
        cout << "*";
    }
    cout << endl;       //Wai Yan is sexy
}