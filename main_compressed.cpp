#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <fstream>
#include <Windows.h>
using namespace std;
void printLine(int i);
bool Booking();
void OpenBooking();
void EditBooking();
void AddBooking();
void SendBooking();
bool GuestRoom();
void SearchGuest();
void EditGuestRoom();
bool BoarderDetails();
bool BoarderRoom();
bool SegregatedBoarders();
bool Cleaning();
bool Defect();
bool AddBoarder();
bool EditBoarder();
bool RemoveBoarder();
bool ReturnOption();
bool AccountSetting();
bool RemoveUser();
bool ChangePassword();
bool Login();
char assign_bed(int room, char bed);  
int assign_room(char bed, int room);
int assign_floor(int room, int floor);

int main(){
    int choice;
    cout << fixed << left;
    int LOOP = 0, LOGIN;

        system("CLS");
        printLine(60);
        cout << "Hwa Chong Institution Boarding School Management System" << endl;
        printLine(60);
        cout << endl;
        LOGIN = Login();
        if (LOGIN == 1)
        {
            while (LOOP == 0)
            {
                system("CLS");
                printLine(60);
                cout << "Hwa Chong Institution Boarding School Management System" << endl;
                printLine(60);
                cout << "Main Menu" << endl << endl;
                cout << "1. Booking History/Listings" << endl;//kai
                cout << "2. Guest Room Allocations" << endl;//adam
                cout << "3. Boarders Details" << endl; //noah
                cout << "4. Boarder Room Allocations" << endl; //waiyan
                cout << "5. User Account" << endl;//noah
                cout << "0. Exit" << endl;

                cout << "Option: ";
                cin >> choice;

                while (choice < 0 || choice > 5) {
                    cout << "Invalid Input!" << endl;
                    cout << "Option: ";
                    cin >> choice;
                }
                if (choice == 1) {
                    LOOP = Booking(); //Display Booking List
                }
                else if (choice == 2) {
                    LOOP = GuestRoom(); //Display and Allocate Guest Room Allocation List
                }
                else if (choice == 3) { 
                    LOOP = BoarderDetails(); //Display Boarder Details List
                }
                else if (choice == 4) {
                    LOOP = BoarderRoom(); //Display and Allocate Boarders' Rooms
                }
                else if (choice == 5) {
                    LOOP = AccountSetting(); //Enter Account Settings
                }
                else {
                    printLine(30);
                    cout << "Logged Out..." << endl;
                    printLine(30);
                    LOOP = 1;
                }
            }
        }
    return 0;
}

void printLine(int i){ //print n number of "=" characters
    char line = 205;
    for (int j = 0; j < i; j++) {cout << line;} 
    cout << endl;
}

bool Booking() { //
    int option;
    bool LOOP;
    printLine(60);
    cout << "Guest Booking List" << endl;
    printLine(60);
    OpenBooking(); //Display Guest Booking List

    cout << "Enter 1 if you want to edit, enter 2 if you want to add, enter 3 if you do not need to make futher changes" << endl;
    cin >> option;

    while(option < 1 || option > 3){
        cout << "Invalid Input!" << endl; 
        cout << "Enter 1 if you want to edit, enter 2 if you want to add, enter 3 if you do not need to make futher changes" << endl;
        cin >> option;
    }
        if(option == 1) EditBooking();
        else if(option == 2) AddBooking();

    SendBooking();
    LOOP = ReturnOption();
    return LOOP;
}

void OpenBooking(){
    fstream inFile;
    string name, RT, tog, ci, co, email; //rt=room type, tog=type of guest, ci/co=check in/out, pn=phone number
    int pn;

    cout << fixed << left 
         << setw(20) << "Name" << setw(20) << "Room type"
         << setw(20) << "Type of guest" << setw(20) << "Check-in" << setw(20) << "Check-out"
         << setw(25) << "Email" << "Phone number" << endl;
    inFile.open("Booking List.txt");//Collect Data from Booking List Text File
    if(!inFile) cout << "Unable to open file" << endl;
    else{
        while(!inFile.eof()){
            inFile >> name >> RT 
                   >> tog >> ci >> co 
                   >> email >> pn;
            if(inFile.fail()) {break;}      
            cout << setw(20) << name << setw(20) << RT 
                 << setw(20) << tog << setw(20) << ci << setw(20) << co 
                 << setw(25) << email << pn << endl;
        }
    }
    inFile.close();
}

void EditBooking(){//edit booking list in the terminal 
    printLine(60);
    cout << "Edit Guest Booking List" << endl;
    printLine(60);
    string Ename, ERT, Etog, Eci, Eco, Eemail; //E for edit 
    int Epn; 

    cout << "Enter name whose data is to be edited : "; 
    cin >> Ename; 
    cout << "Enter " << Ename << "'s new room type, check-in, check-out, email, phone number : \n"; 
    cin >> ERT >> Eci >> Eco >> Eemail >> Epn;

    string name, RT, tog, ci, co, email; 
    ifstream inFile; 
    ofstream outFile; 
    int option, pn;

    inFile.open("Booking List.txt"); //Original File 
    outFile.open("Booking List_temp.txt"); //Temperary File to store edited details

    if (!inFile || !outFile) cout << "Unable to open file" << endl;
        else { 
            while (!inFile.eof()){ 
                inFile >> name >> RT >> tog >> ci >> co >> email >> pn; //input this cookc
                if (inFile.fail()) break;//error handling
                if (name == Ename){ //replace data if searched name is found
                    RT = ERT;
                    ci = Eci;
                    co = Eco;
                    email = Eemail;
                    pn = Epn;
                } 
                outFile  << left 
                     << setw(20) << name << setw(20) << RT 
                     << setw(20) << tog << setw(20) << ci << setw(20) << co 
                     << setw(25) << email << pn << endl;
        } 
    } 

    inFile.close(); 
    outFile.close(); 
    //User check to see if file is edited properly.
    system("CLS"); 
    cout << "Below is the edited file\n"; 
    printLine(100); 
    cout << setw(20) << "Name" << setw(20) << "Room type" 
         << setw(20) << "Type of student" << setw(20) << "Check-in" << setw(20) << "Check-out" 
         << setw(25) << "Email" << "Phone number" << endl;
    
    inFile.open("Booking List_temp.txt"); 
    if (!inFile) cout << "Unable to open file" << endl; 
    else{ 
        while (!inFile.eof()){ 
            inFile >> name >> RT >> tog >> ci >> co >> email >> pn; //input
            if (inFile.fail()) break;//error handling 
            cout << setw(20) << name << setw(20) << RT << setw(20) << tog << setw(20) << ci << setw(20) << co << setw(25) << email << pn << endl; 
        } 
    } 
    inFile.close(); 
    outFile.close(); 
    printLine(100); 
    cout << "Enter 0 to save file\nEnter 1 to revert back to the original file\nOption : "; 
    cin >> option; 
    //below - transfer edited data from temp file to original file - save file 
    if (option==0){ 
        remove("Booking List.txt"); //TAKEN FROM movieTheatre.cpp from blackboard.
        rename("Booking List_temp.txt", "Booking List.txt"); 
    } 
    else{//to revert back to the original file
        cout << "Edit is deleted. File is reverted back to original.\n";
    }
}

void AddBooking(){
    int option, pn, pn_add; 
    ifstream inFile;
    ofstream outFile; 
    string name, RT, tog, ci, co, email;
    string name_add, RT_add, tog_add, ci_add, co_add, email_add;
    
    cout << "Enter name, room type, type of guest, check-in, check-out, email, phone number : \n"; 
    cin >> name_add >> RT_add >> tog_add >> ci_add >> co_add >> email_add >> pn_add;
    cout << "Adding the following :\n" 
              << left 
              << name_add << "\t" << RT_add 
              << "\t" << tog_add << "\t" << ci_add << "\t" << co_add 
              << "\t" << email_add << "\t" << pn_add << endl;
    inFile.open("Booking List.txt");
    outFile.open("Booking List_temp.txt", ofstream::app); 
    
    if (!inFile ||!outFile) {cout << "Unable to open file\n"; }
    else{ 
        while (!inFile.eof()){ 
                inFile >> name >> RT >> tog >> ci >> co >> email >> pn;
                if (inFile.fail()) break;//error handling
                outFile<< left 
                 << setw(20) << name << setw(20) << RT 
                 << setw(20) << tog << setw(20) << ci << setw(20) << co 
                 << setw(25) << email << pn << endl << flush;
        }
    inFile.close();
    outFile.close();

    remove("Booking List.txt");
    rename("Booking List_temp.txt", "Booking List.txt");

    }
} 

void SendBooking(){
    
    fstream inFile;
    ofstream outFile;

    inFile.open("Booking List.txt");
    outFile.open("Guest Room Allocation.txt");

    if (!inFile || !outFile) cout << "Unable to open file." << endl;
    else{
        while (!inFile.eof()){
            string name, RT, tog, ci, co, email, pn ;// rt=room type, tog=type of guest, ci/co=check in/out, pn=phone number
            inFile >> name >> RT 
                   >> tog >> ci >> co 
                   >> email >> pn;
            if(inFile.fail()){break;}
            outFile << fixed << left
                    << setw(20) << setw(20) << name << setw(20) << RT 
                    << setw(20) << tog << setw(20) << ci << setw(20) << co 
                    << setw(25) << email << pn << endl << flush;
        }
    }
    inFile.close();
    outFile.close();
}

bool GuestRoom() {
    printLine(100);
    cout << "Guest Room Allocation (Read-Only)" << endl;
    printLine(100);
    
    string name, roomtype, typeofguest, checkin, checkout, email, phonenumber;
    char hall; 
    int roomF = 0, floorF = 1, roomG = 0, floorG = 1;
	int option;
	bool LOOP;
    int floor,room;
    int reallocate;
    ifstream inFile;
    ofstream outFile;

    inFile.open("Guest Room Allocation.txt");    
    cout << left<< setw(25) << "Name" << setw(20) << "Room Type" << setw(25) << "Type of Guest" << setw(20) << "Check-in" << setw(20) << "Check-out"
        << setw(30) << "Email" << setw(20) << "Phone Number" << "Hall, Floor,Room num" << endl;
    if (!inFile){cout << "Error opening file." << endl;}
    else {
        while (!inFile.eof()){   
                inFile >> name >> roomtype >> typeofguest >> checkin >> checkout >> email >> phonenumber >> hall >> floor >> room;
            if (inFile.fail()) break;//error handling                
                cout << setw(25) << name << setw(20) << roomtype << setw(25) << typeofguest << setw(20) << checkin << setw(20) << checkout << setw(30)
                << email << setw(20) << phonenumber << hall << floor << "(" << room << ")" <<  endl;                    
        }
    }
    inFile.close();
    cout << "1. Re-Allocate Guests\n0.Skip\nOption: ";
    cin>> reallocate;

    while (reallocate < 0 || reallocate > 1) {
        cout << "Invalid Output" << endl;
        cout << "1.Re-Allocate Guest Rooms\n0.Skip\nOption: ";                
        cin >> reallocate;
    }
    if (reallocate == 1){
        system("CLS");
        printLine(100);
        cout << "Guest Room Allocation (Edited)" << endl;
        printLine(100);
        inFile.open("Booking List.txt");
        outFile.open("Guest Room Allocation.txt");
    
        if (!inFile || !outFile){cout << "Unable to open file" << endl;}
        cout << left<< setw(25) << "Name" << setw(20) << "Room Type" << setw(25) << "Type of Guest" << setw(20) << "Check-in" << setw(20) << "Check-out"
            << setw(30) << "Email" << setw(20) << "Phone Number" << "Hall, Floor,Room num" << endl;
        outFile << left;
            while (!inFile.eof()){
            inFile >> name >> roomtype >> typeofguest >> checkin >> checkout >> email >> phonenumber;
            if (inFile.fail()) {break;}

            if (typeofguest == "Short-Term_Guest"){
                hall = 'F';
                if (roomF >= 0 && roomF <= 10){roomF++;}
                else if (roomF > 10) {
                    floorF++;
                    roomF = 1;
                }
                cout << setw(25) << name << setw(20) << roomtype << setw(25) << typeofguest << setw(20) << checkin << setw(20) << checkout << setw(30)
                        << email << setw(20) << phonenumber << hall << floorF << "(" << roomF << ")" <<  endl;
                    
                outFile << setw(25) << name << setw(20) << roomtype << setw(25) << typeofguest << setw(20) << checkin << setw(20) << checkout << setw(30)
                        << email << setw(20) << phonenumber << hall << setw(10) << floorF << roomF  <<  endl << flush;
            }
            else if (typeofguest == "Long-Term_Guest" || typeofguest == "University_Student"){
                hall = 'G';
                if (roomG >= 0 && roomG <= 10){roomG++;}
                else if (roomG > 10){ 
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
    }
    
    cout << "1. Seach Guest\n2. Edit Room Allocation\n3. Exit\nOption: ";
    cin >> option;
    while (option < 1 && option > 3) {
        cout << "Invalid Input!\n1. Seach Guest\n2. Edit Room Allocation\n3. Exit\nOption: ";
        cin >> option;
    }
    if (option == 1) {SearchGuest();}
    else if (option == 2){EditGuestRoom();}
    LOOP = ReturnOption();
    return LOOP;
}

void SearchGuest(){
    system("CLS");    
    ifstream inFile;
    string name, roomtype, typeofguest, checkin, checkout, email, phonenumber;
    char hall; 
    int room, floor;
    bool checkname = 0;
    string name_search;
    cout << "Enter Guest's Name: ";
    cin >> name_search;

    inFile.open("Guest Room Allocation.txt");
        if (!inFile){cout << "Error opening file." << endl;}
        else {//continue
            while (!inFile.eof()){   
                inFile >> name >> roomtype >> typeofguest >> checkin >> checkout >> email >> phonenumber >> hall >> floor >> room;
                if (inFile.fail()) break;//error handling
                if (name == name_search){
                    checkname = 1;
                    cout << left<< setw(25) << "Name" << setw(20) << "Room Type" << setw(25) << "Type of Guest" << setw(20) << "Check-in" << setw(20) << "Check-out"
                    << setw(30) << "Email" << setw(20) << "Phone Number" << "Hall, Floor,Room num" << endl;
                    cout << setw(25) << name << setw(20) << roomtype << setw(25) << typeofguest << setw(20) << checkin << setw(20) << checkout << setw(30)
                    << email << setw(20) << phonenumber << hall << floor << "(" << room << ")" <<  endl;           
                }
            }
            if (checkname == 0){cout << name_search << " cannot be found." << endl;}
        }
    inFile.close();
}

void EditGuestRoom(){
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
    outFile.open("temp_guestroomallocation.txt"); //Temperary File to store edited details 

    if (!inFile || !outFile){cout << "Unable to open file" << endl;}
    else{
        while (!inFile.eof()){
            inFile >> name >> roomtype >> typeofguest >> checkin >> checkout >> email >> phonenumber >> hall >> floor >> room; //>> leave; //input 
            if (inFile.fail()) break;//error handling 
            if (name == Ename){
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
    inFile.open("temp_guestroomallocation.txt");
    if (!inFile){cout << "Unable to open file" << endl;}
    else{
        while (!inFile.eof()){
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
    if (option == 0){
        remove("Guest Room Allocation.txt");
        rename("temp_guestroomallocation.txt", "Guest Room Allocation.txt");
    }
    else{
        remove("temp_guestroomallocation.txt");
        cout << "Edit is deleted. File is reverted back to original.";
    }
}

bool BoarderDetails(){
    system("CLS");
    printLine(100);
    cout << "Boarder Details" << endl;
    printLine(100);
    int option;
    bool LOOP = 1;
    string name, level, type, nation, school, leave;
    char gender;
    cout << setw(25) << "Name" << setw(20) << "Gender" << setw(20) << "Level" << setw(20) << "Type" << setw(20) << "Nationality" << "School" << endl;
    ifstream inFile;
    inFile.open("Boarders Details.txt");
    if (!inFile){cout << "Unable to open file" << endl;}
    else{
        while (!inFile.eof()){
            inFile >> name >> gender >> level >> type >> nation >> school; //>> leave; //input
            if (inFile.fail()) break;//error handling
            cout << setw(25) << name << setw(20) << gender << setw(20) << level << setw(20) << type << setw(20) << nation << school << endl;
        }
    }
    inFile.close();
    printLine(100);
    cout << "\n1. Edit data\n2. Add data\n3. Delete data\n4. Return to main menu\nOption : ";
    cin >> option;
    while (option <= 0 || option >= 5){
        cout << "Option " << option << " is unavailable\n" << "Please enter again : ";
        cin >> option;
    }
    if (option == 1){LOOP = EditBoarder();}//edit file 
    else if (option == 2){LOOP = AddBoarder();}//add data    
    else if (option == 3){LOOP = RemoveBoarder();}//delete data
    else if (option == 4){//back to main menu
        cout << "Returning to main menu";
        for (int i = 0; i < 5; i++){
            cout << ".";
            Sleep(100);
        }
        system("CLS");
        LOOP = 0;
    }
    return LOOP;
}

bool EditBoarder(){
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

    inFile.open("Boarders Details.txt"); //Oringinal File
    outFile.open("temp_boarderdetails.txt", ofstream::out); //Temperary File to store edited details
    if (!inFile || !outFile){cout << "Unable to open file" << endl;}
    else{
        while (!inFile.eof()){
            inFile >> name >> gender >> level >> type >> nation >> school; //>> leave; //input
            if (inFile.fail()) break;//error handling
            if (name == Ename){
                gender = Egender;
                level = Elevel;
                type = Etype;
                nation = Enation;
                school = Eschool;
                checkname = 1; //Figure out how to create error handling for incorrect names.COMPLETED
            }
            outFile << left << setw(24) << name << setw(8) << gender << setw(16) << level << setw(16) << type << setw(16) << nation << school << endl;
        }
        if (checkname == 0){cout << Ename << " cannot be found.";}
    }
    if (checkname == 1){
        inFile.close();
        outFile.close();
        //User check to see if file is edited properly.
        system("CLS");
        printLine(100);
        cout << "Edit User Account\n";
        printLine(100);
        cout << "Below is the edited file\n";
        printLine(100);
        cout << setw(25) << "Name" << setw(20) << "Gender" << setw(20) << "Level" << setw(20) << "Type" << setw(20) << "Nationality" << "School" << endl;
        inFile.open("temp_boarderdetails.txt");//opens temp file for user checking
        
        if (!inFile){cout << "Unable to open file" << endl;}
        else{
            while (!inFile.eof()){
                inFile >> name >> gender >> level >> type >> nation >> school; //input
                if (inFile.fail()) break;//error handling
                cout << setw(25) << name << setw(20) << gender << setw(20) << level << setw(20) << type << setw(20) << nation << school << endl;
            }
        }
        inFile.close();
        printLine(100);
        cout << "Enter 0 to save file\nEnter 1 to revert back to the original file\nOption : ";
        cin >> option;
        //below - transfer edited data from temp file to original file - save file
        if (option == 0){
            remove("Boarders Details.txt"); //TAKEN FROM movieTheatre.cpp from blackboard.
            rename("temp_boarderdetails.txt", "Boarders Details.txt");
            /*inFile.close();
            outFile.close();
            inFile.open("temp_boardersdetails.txt");
            outFile.open("Boarders Details.txt", ofstream::out);
            if (!inFile || !outFile){cout << "Unable to open file" << endl;}
            else{
                while (!inFile.eof()){
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
        else{
            cout << "Edit is deleted. File is reverted back to original.";
            LOOP = ReturnOption();
        }
    }
    return LOOP;
}

bool AddBoarder(){
    printLine(100);
    cout << "Add Boarder Details\n";
    printLine(100);
    ofstream outFile;
    string name, level, type, nation, school;
    char gender;
    bool LOOP;
    cout << "Enter name, gender, level, type, nationality, school : \n";
    cin >> name >> gender >> level >> type >> nation >> school;
    outFile.open("Boarders Details.txt", ofstream::app);
    if (!outFile){cout << "Unable to open file\n";}
    else{
        cout << "Adding the following :\n" << left << setw(25) << name << setw(20) << gender << setw(20) << level << setw(20) << type << setw(20) << nation << school;
        outFile << left << setw(24) << name << setw(8) << gender << setw(16) << level << setw(16) << type << setw(16) << nation << school << endl;
    }
    outFile.close();
    LOOP = ReturnOption();
    return LOOP;
}

bool RemoveBoarder(){
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
    if (!inFile || !outFile){cout << "Unable to open file" << endl;}
    else{
        while (!inFile.eof()){
            inFile >> name >> gender >> level >> type >> nation >> school;//input
            if (inFile.fail()) break;//error handling
            if (name == Ename){
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
        if (checkname == 0){cout << "Account not found.\n";
        }
    }
    inFile.close();
    outFile.close();
    if (checkname == 1){
        //User check to see if file is edited properly.
        system("CLS");
        printLine(100);
        cout << "Remove Boarder Details\n";
        printLine(100);
        cout << "Below is the edited file\n";
        printLine(100);
        cout << setw(25) << "Name" << setw(20) << "Gender" << setw(20) << "Level" << setw(20) << "Type" << setw(20) << "Nationality" << "School" << endl;
        inFile.open("temp_boarderdetails.txt");//opens temp file for user checking
        if (!inFile){cout << "Unable to open file" << endl;}
        else{
            while (!inFile.eof()){
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
        if (option == 0){
            remove("Boarders Details.txt"); //TAKEN FROM movieTheatre.cpp from blackboard.
            rename("temp_boarderdetails.txt", "Boarders Details.txt");
            cout << "File saved.";
            LOOP = ReturnOption();
        }
        else{
            cout << "Edit is deleted. File is reverted back to original.";
            LOOP = ReturnOption();
        }
    return LOOP;
    }
}

bool ReturnOption(){
    cout << "\n";
    printLine(100);
    bool option;
    cout << "Enter 0 to return to the main menu\nEnter 1 to exit program\nOption : ";
    cin >> option;
    if (option == 0){
        cout << "Returning to main menu";
        for (int i = 0; i < 5; i++){
            cout << ".";
            Sleep(100);
        }
    system("CLS");
    }
    return option;
} 

bool Login(){
    string username, password, Tusername, Tpassword; //T for Text file data
    bool Cusername = 0, Cpassword = 0, correctlogin = 0, falsePW = 1, falseACC = 1; //C for CHeck
    while (falseACC == 1){
        cout << "Please enter username : ";
        cin >> username;
        falsePW = 1;
        while (falsePW == 1){
            cout << "Please enter password : ";
            cin >> password;
            ifstream inFile;
            inFile.open("User Accounts.txt");
            if (!inFile) { cout << "Unable to open file\n"; }
            else{
                while (!inFile.eof()){
                    inFile >> Tusername >> Tpassword;
                    if (Tusername == username){
                        Cusername = 1;
                        if (Tpassword == password){
                            Cpassword = 1;
                            break;
                        }
                        else{
                            Cpassword = 0;
                            break;
                        }
                    }
                    else Cusername = 0;
                }
            }
            inFile.close();
            if (Cusername == 1 && Cpassword == 0){
                cout << "Incorrect password.\n";
                falsePW = 1;
            }
            else if (Cusername == 1 && Cpassword == 1){
                correctlogin = 1;
                falsePW = 0;
                falseACC = 0;
            }
            else if (Cusername == 0){
                cout << "Account not found.\n";
                falsePW = 0;
                falseACC = 1;
            }
        }
    }
    return correctlogin;
}

bool AccountSetting(){
    int choice;
    bool LOGIN, LOOP;
    system("CLS");
    printLine(100);
    cout << "User Accounts\n";
    printLine(100);
    cout << "1. Add user account\n2. Remove user account\n3. Change password\n4. Return to main menu\nOption : ";
    cin >> choice;
    while (choice <= 0 || choice >= 5){
        cout << "Option " << choice << " is unavailable\n" << "Please enter again : ";
        cin >> choice;
    }
    if (choice == 1){//ADD ACCOUNT
        cout << "To add user account, please login again.\n";
        LOGIN = Login();
        system("CLS");
        printLine(100);
        cout << "Add User Account\n";
        printLine(100);
        if (LOGIN == 1){
            string username, password;
            cout << "Please enter NEW username : ";
            cin >> username;
            cout << "Please enter NEW password : ";
            cin >> password;
            ofstream outFile;
            outFile.open("User Accounts.txt", ofstream::app);
            if (!outFile) { cout << "Unable to open file\n"; }
            else{
                cout << "Adding the following\nUsername : " << username << "\nPassword : " << password;
                outFile << username << "\t" << password << "\t\n";
            }
            outFile.close();
        }
        LOOP = ReturnOption();        
    }
    else if (choice == 2){ LOOP = RemoveUser();}//REMOVE ACCOUNT
    else if (choice == 3){LOOP = ChangePassword();}//CHANGE PASSWORD
    else{
        cout << "Returning to main menu";
        for (int i = 0; i < 5; i++){
            cout << ".";
            Sleep(100);
        }
        system("CLS");
        LOOP = 0;
    }
    return LOOP;
}

bool RemoveUser(){
    cout << "To remove user account, please login again.\n";
    bool LOGIN, LOOP;
    LOGIN = Login();
    system("CLS");
    cout << "Remove User Account\n";
    printLine(100);
    if (LOGIN == 1){
        bool findacc = 0;
        string username, Fusername, Fpassword; //F for FILE
        cout << "Please enter username of account to be deleted : ";
        cin >> username;
        ifstream inFile;
        ofstream outFile;
        inFile.open("User Accounts.txt"); //Oringinal File
        outFile.open("temp_useraccounts.txt", ofstream::out); //Temperary File to store edited details
        if (!inFile || !outFile){cout << "Unable to open file" << endl;}
        else{
            while (!inFile.eof()){
                inFile >> Fusername >> Fpassword; //>> leave; //input
                if (inFile.fail()) break;//error handling
                if (Fusername == username){
                    Fusername = "";
                    Fpassword = "";
                    outFile << Fusername << Fpassword;
                    findacc = 1;
                }
                else{outFile << Fusername << "\t" << Fpassword << "\n";}
            }
            if (findacc == 0){cout << "Account not found.\n";}
        }
        if (findacc == 1){
            inFile.close();
            outFile.close();
            //User check to see if file is edited properly.
            system("CLS");
            printLine(100);
            cout << "Remove User Account\n";
            printLine(100);
            cout << "\n" << username << "'s account have been deleted.\n";
            remove("User Accounts.txt"); //TAKEN FROM movieTheatre.cpp from blackboard.
            rename("temp_useraccounts.txt", "User Accounts.txt");  
        }
        LOOP = ReturnOption();
        return LOOP;
    }
}

bool ChangePassword(){
    system("CLS");
    string currUSER, changedPW, USERnPW, username, password;
    printLine(100);
    cout << "Change Password\n";
    printLine(100);
    cout << "To change password, please login again\n";
    bool LOGIN, LOOP;
    LOGIN = Login();
    if (LOGIN == 1){
        system("CLS");
        printLine(100);
        cout << "Change Password\n";
        printLine(100);
        cout << "Please enter username followed by new password : ";
        cin >> currUSER >> changedPW;
        ifstream inFile;
        ofstream outFile;
        inFile.open("User Accounts.txt"); //Oringinal File
        outFile.open("temp_useraccounts.txt", ofstream::out); //Temperary File to store edited details
        if (!inFile || !outFile){cout << "Unable to open file" << endl;}
        else{
            while (!inFile.eof()){
                inFile >> username >> password; //>> leave; //input
                if (inFile.fail()) break;//error handling
                if (username == currUSER){password = changedPW;}
                outFile << username << "\t" << password << "\n";
            }
        }
        inFile.close();
        outFile.close();
        cout << "Password for " << currUSER << " has been changed.\n";
        remove("User Accounts.txt"); //TAKEN FROM movieTheatre.cpp from blackboard.
        rename("temp_useraccounts.txt", "User Accounts.txt");
        LOOP = ReturnOption();
        return LOOP;
    }
}

bool BoarderRoom() {
    system("CLS");
    ifstream inFile;
    ofstream outFile;
    string name, level, type, school, nationality;
    string name_a[999], level_a[999],type_a[999], school_a[999],nationality_a[999]; 
    char hall, gender; 
    char hall_a[999], bed_a[999], gender_a[999];
    int floor_a[999], room_a[999];
    int num_boarders=0, option = 1;
    int floor, floor_aa, floor_bb, room, room_aa, room_bb;
    char bed, bed_aa, bed_bb;
    bool LOOP; 
    int reallocate;
    floor_aa = 2;
    room_aa = 1;
    bed_aa = 64; //A-D 65-68, start with 64 in order to make sure the first bed is A

    floor_bb = 2;
    room_bb = 1;
    bed_bb = 64;

    inFile.open("Boarders Room Allocation.txt");
    

    if (!inFile || !outFile) {cout << "Error opening file.";}
    else {//continue code  
        cout <<left;
        printLine(100);
        cout << "ROOM ALLOCATION (Read-Only)" << endl;
        printLine(100);
        cout << setw(25) << "Name" << setw(20) << "Level"<< setw(20) << "Type" << setw(20) << "School"  << "Hall,Floor,Room,Bed" << endl; //Output titles
        while (!inFile.eof()){ // read data only
            inFile >> name_a[num_boarders] >> level_a[num_boarders] >> setw(20) >> type_a[num_boarders] >> setw(20) >> school_a[num_boarders] >> hall_a[num_boarders] >> floor_a[num_boarders] >> room_a[num_boarders] >> bed_a[num_boarders];
            if(inFile.fail()) {break;}    
            cout << setw(25) << name_a[num_boarders] << setw(20) << level_a[num_boarders] << setw(20) << type_a[num_boarders] << setw(20) << school_a[num_boarders] << hall_a[num_boarders] << floor_a[num_boarders] << "/" << room_a[num_boarders] << "(" << bed_a[num_boarders] << ")" << endl;
            num_boarders++;
        }
        inFile.close();
            /*if(hall_a[num_boarders] > hall_a[num_boarders+1]){
                char temp;
                temp = hall_a[num_boarders];
                hall_a[num_boarders] = hall_a[num_boarders+1];
                hall_a[num_boarders+1] = temp;
                cout << setw(25) << name_a[num_boarders] << setw(20) << level_a[num_boarders] << setw(20) << type_a[num_boarders] << setw(20) << school_a[num_boarders] << hall_a[num_boarders] << floor_a[num_boarders] << "/" << room_a[num_boarders] << "(" << bed_a[num_boarders] << ")" << endl;
            }*/
            cout << "1.Re-Allocate Boarders Room\n0.Skip\nOption: ";                
            cin >> reallocate;
            while (reallocate < 0 || reallocate > 1){
            cout << "Invalid Output" << endl;
            cout << "1.Re-Allocate Boarders Room\n0.Skip\nOption: ";                
            cin >> reallocate;
        }
        if (reallocate == 1) {
            system("CLS");
            num_boarders=0;
            cout <<left;
            printLine(100);
            cout << "ROOM ALLOCATION (Reallocated)" << endl;
            printLine(100);

            inFile.open("Boarders Details.txt");
            outFile.open("Boarders Room Allocation.txt");
            cout << setw(25) << "Name" << setw(20) << "Level"<< setw(20) << "Type" << setw(20) << "School"  << "Hall,Floor,Room,Bed" << endl; //Output titles
            while (!inFile.eof()){ // read data and go through algorithms
                inFile>> name_a[num_boarders] >> gender_a[num_boarders] >> level_a[num_boarders] >> type_a[num_boarders] >> nationality_a[num_boarders] >> school_a[num_boarders];
                if(inFile.fail()) {break;}
                    if (gender_a[num_boarders] == 'M') {
                        hall = 'A';

                        room_a[num_boarders] = assign_room(bed_aa, room_aa);
                        room_aa = room_a[num_boarders];
                        bed_a[num_boarders] = assign_bed(room_aa, bed_aa);
                        bed_aa = bed_a[num_boarders];
                        floor_a[num_boarders] = assign_floor(room_aa, floor_aa);
                        floor_aa = floor_a[num_boarders];
                        hall_a [num_boarders] = hall;


                        cout << setw(25) << name_a[num_boarders] << setw(20) << level_a[num_boarders] << setw(20) << type_a[num_boarders] << setw(20) << school_a[num_boarders] << hall_a[num_boarders] << floor_a[num_boarders] << "/" << room_a[num_boarders] << "(" << bed_a[num_boarders] << ")" << endl;
                        outFile << left;
                        outFile << setw(25) << name_a[num_boarders] << setw(20) << level_a[num_boarders] << setw(20) << type_a[num_boarders] << setw(20) << school_a[num_boarders] << hall_a[num_boarders] << setw(20) <<  floor_a[num_boarders] << room_a[num_boarders] << bed_a[num_boarders] << endl << flush;    
                    }
                    else if (gender_a[num_boarders] == 'F' ) {
                        hall = 'B';

                        room_a [num_boarders] = assign_room(bed_bb, room_bb);
                        room_bb = room_a[num_boarders];
                        bed_a[num_boarders] = assign_bed(room_bb, bed_bb); 
                        bed_bb = bed_a[num_boarders];
                        floor_a [num_boarders] = assign_floor(room_bb, floor_bb);
                        floor_bb = floor_a[num_boarders];
                        hall_a [num_boarders] = hall;

                        cout << setw(25) << name_a[num_boarders] << setw(20) << level_a[num_boarders] << setw(20) << type_a[num_boarders] << setw(20) << school_a[num_boarders] << hall_a[num_boarders] << floor_a[num_boarders] << "/" << room_a[num_boarders] << "(" << bed_a[num_boarders] << ")" << endl;
                        outFile << setw(25) << name_a[num_boarders] << setw(20) << level_a[num_boarders] << setw(20) << type_a[num_boarders] << setw(20) << school_a[num_boarders] << hall_a[num_boarders] << setw(20) << floor_a[num_boarders] << room_a[num_boarders] << bed_a[num_boarders] << endl << flush;     
                }
                /*if(hall_a[num_boarders] > hall_a[num_boarders+1])
                    {
                        char temp;
                        temp = hall_a[num_boarders];
                        hall_a[num_boarders] = hall_a[num_boarders+1];
                        hall_a[num_boarders+1] = temp;
                        cout << setw(25) << name_a[num_boarders] << setw(20) << level_a[num_boarders] << setw(20) << type_a[num_boarders] << setw(20) << school_a[num_boarders] << hall_a[num_boarders] << floor_a[num_boarders] << "/" << room_a[num_boarders] << "(" << bed_a[num_boarders] << ")" << endl;
                    }*/
                
                else {cout << "DATA Input Error" << endl;}
            
                num_boarders++;
            }
        }  
            
    }
    inFile.close();
    outFile.close();
    cout << "1.Search Boarder\n2.Edit Boarder's Cluster\n3.Exit Boarder Room Allocation Menu.\nOption: ";
    cin >> option;
    while (option < 1 && option > 3){
        cout  << "Invalid Input!\n";
        cout << "1.Search Boarder\n2.Edit Boarder's Cluster\n3.Exit.\nOption: ";
        cin >> option;
    }
        
//Search Boarder
    if (option == 1){
        system("CLS");
        printLine(50);
        cout << "Search Boarder's Room Allocation Details" << endl;
        printLine(50);
        int index = 0;
        string name_search;
        bool found = false;
        cout << "Enter Name: ";
        cin >> name_search;
        for (int i = 0; i <= num_boarders;i++) {
            if (name_search == name_a[i]) {
                found = true;
                break;
            }
        }
        while (found == false) {        
            if (found == false) {
                cout << "Name Not Found.\nRe-Enter Boarder's Name: ";
                cin >> name_search;
            for (int i = 0; i <= num_boarders;i++) {
                if (name_search == name_a[i]) {
                    found = true;
                    break;
                    }
                }
            }
        }
        cout << setw(25) << "Name" << setw(20) << "Level"<< setw(20) << "Type" << setw(20) << "School"  << "Hall,Floor,Room,Bed" << endl; //Output titles
        inFile.open("Boarders Room Allocation.txt");
        if (!inFile){cout << "Error opening file." << endl;}
            else {//continue
                while (!inFile.eof()) {
                    inFile >> name_a[index] >> level_a[index] >> setw(20) >> type_a[index] >> setw(20) >> school_a[index] >> hall_a[index] >> floor_a[index] >> room_a[index] >> bed_a[index];
                    if(inFile.fail()) {break;}
                    if (name_a[index] == name_search){
                        cout << setw(25) << name_a[index] << setw(20) << level_a[index] << setw(20) << type_a[index] << setw(20) << school_a[index] << hall_a[index] << floor_a[index] << "/" << room_a[index] << "(" << bed_a[index] << ")" << endl;
                        break; 
                    }
                    index++;
                }                
            }
        inFile.close();
    }
    
    else if (option == 2) {
        printLine(50);
        cout << "Editing Boarder's Room Allocation" << endl;
        printLine(50);
        //EditBoarderRoom
        bool option_edit = 1;
        while (option_edit == true) {
            string name_edit;
            char hall_edit, bed_edit;
            int floor_edit, room_edit;
            int index = 0, index_found; 
            bool found = false;
            int save;
            ifstream inFile;
            ofstream outFile;
            
            cout << "Name of Boarder:";
            cin >> name_edit;
            
            for (int i = 0; i <= num_boarders;i++) {
                if (name_edit == name_a[i]) {
                    found = true;
                    index_found = i;
                    break;
                }
            }
            while (found == false) {                        
                if (found == false) {
                    cout << "Name Not Found.\nRe-Enter Boarder's Name: ";
                    cin >> name_edit;
                }
                for (int i = 0; i <= num_boarders;i++) {
                    if (name_edit == name_a[i]) {
                        found = true;
                        index_found = i;
                        break;
                    }
                }
            }
            cout << setw(25) << "Name" << setw(20) << "Level"<< setw(20) << "Type" << setw(20) << "School"  << "Hall,Floor,Room,Bed" << endl;
            cout << setw(25) << name_a[index_found] << setw(20) << level_a[index_found] << setw(20) << type_a[index_found] << setw(20) << school_a[index_found] << hall_a[index_found] << floor_a[index_found] << "/" << room_a[index_found] << "(" << bed_a[index_found] << ")" << endl;
            cout << name_edit << "'s new Hall, Floor, Room, Bed: ";
            cin >> hall_edit >> floor_edit >> room_edit >> bed_edit;
            printLine(100);
            cout << "Edited Boarder's Room" << endl;
            cout << setw(25) << "Name" << setw(20) << "Level"<< setw(20) << "Type" << setw(20) << "School"  << "Hall,Floor,Room,Bed" << endl;
            cout << setw(25) << name_a[index_found] << setw(20) << level_a[index_found] << setw(20) << type_a[index_found] << setw(20) << school_a[index_found] << hall_edit << floor_edit << "/" << room_edit << "(" << bed_edit<< ")" << endl;
            cout << "1. Save Changes\n0.Discard Changes\nOption: ";
            cin >> save;
 
            while (save < 0 || save > 1){
                cout << "Invalid Input" << endl;
                cout << "1. Save Changes\n0. Discard Changes\nOption: ";
                cin >> save;
            }

            inFile.open("Boarders Room Allocation.txt");
            outFile.open("editboarderroom.txt");   

            if (save == 1) {
                if (!inFile||!outFile) {cout << "Error opening file.";}
                else {//continue
                    while (!inFile.eof()) {                
                        inFile >> name_a[index] >> level_a[index] >> setw(20) >> type_a[index] >> setw(20) >> school_a[index] >> hall_a[index] >> floor_a[index] >> room_a[index] >> bed_a[index];
                        if(inFile.fail()) {break;}
                        if (name_a[index] == name_a[index_found]){
                            hall_a[index] = hall_edit;
                            floor_a[index] = floor_edit;
                            room_a[index] = room_edit;
                            bed_a[index] = bed_edit;
                        }
                    outFile << left;
                    outFile << setw(25) << name_a[index] << setw(20) << level_a[index] << setw(20) << type_a[index] << setw(20) << school_a[index] << hall_a[index] << setw(20) << floor_a[index] << room_a[index] << bed_a[index] << endl; 
                    index++;
                    }    
                }
                inFile.close();
                outFile.close();
            }
            cout << "1. Continue Edit\n0. Exit Edit\nOption: ";
            cin >> option_edit;
        }
    remove("Boarders Room Allocation.txt");
	rename("editboarderroom.txt","Boarders Room Allocation.txt"); 
    }
    LOOP = ReturnOption();
    return LOOP;

}

int assign_room(char bed, int room) {
    if ((room == 1 || room == 2 || room == 6) && bed >= 68) {room++;}//from room-3 to 5, change room if 2 beds are used
    else if ((room >= 3 && room <= 5) && bed >= 66){room++;}
    else if (bed >= 64){}//continue
    else {cout << "Room Assignment Error";}
    return room;
}

char assign_bed(int room, char bed) {
    if (room == 1 || room == 2 || room == 6) { //from room 1 to 2, change room if 4 beds are used
        if (bed >= 68) {bed = 65;}
        else {bed++;}
    }
    else if (room >= 3 && room <= 5) { //from room-3 to 5, change room if 2 beds are used
        if (bed >= 66) {bed = 65;}
        else {bed++;}  
    }
    else {cout << "Bed Assignment Error";}
    return bed;
}

int assign_floor(int room, int floor) {
    if (room > 6) {floor++;}//from room 1 to 2, change room if 4 beds are used
    else if (room >= 1 && room <= 6) {//continue //from room-3 to 5, change room if 2 beds are used
    }
    else {cout << "Floor Assignment Error";}//if room 6 is filled, change cluster left to right   
    return floor;
}