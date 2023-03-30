#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

void OpenBooking();
void EditBooking();
void AddBooking();
void SendBooking();
bool ReturnOption();
void printLine(int i);

int main(){

    int option;
    bool LOOP = 0;
    OpenBooking();

    cout << "Enter 1 if you want to edit, enter 2 if you want to add, enter 3 if you do not need to make futher changes" << endl;
    cin >> option;

    while(option != 3){

        if(option == 1) EditBooking();
        else if(option == 2) AddBooking();
        else{
            
            cout << "Input error. Please enter your option again." << endl;
            cin >> option;
            }
    }

    SendBooking();
    LOOP = ReturnOption;
    
    system("pause");
    return 0;
}
void OpenBooking(){

    fstream inFile;
    string name, RT, tog, ci, co, email; //rt=room type, tog=type of guest, ci/co=check in/out, pn=phone number
    int pn ;

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

    if (!inFile) cout << "Unable to open file" << endl;
    else  if (!outFile) cout << "Unable to open file\n"; 
    else{ 

        while (!inFile.eof()){ 

            inFile >> name >> RT >> tog >> ci >> co >> email >> pn; //>> leave; //input this cookc

            if (inFile.fail()) break;//error handling

            if (name == Ename){
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

            inFile >> name >> RT >> tog >> ci >> co >> email >> pn; //>> leave; //input

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

        ReturnOption(); 
    } 

    else{ //to revert back to the original file

        cout << "Edit is deleted. File is reverted back to original."; 

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

    if (!inFile)

        cout << "Unable to open file\n"; 

    else if (!outFile) 

        cout << "Unable to open file\n"; 

    else 

    { 
        while (!inFile.eof()) 

            { 

                inFile >> name >> RT >> tog >> ci >> co >> email >> pn;

                if (inFile.fail()) break;//error handling
                
                outFile<< left 
                 << setw(20) << name << setw(20) << RT 
                 << setw(20) << tog << setw(20) << ci << setw(20) << co 
                 << setw(25) << email << pn << endl << flush;
            }
            outFile<< left 
                 << setw(20) << name_add << setw(20) << RT_add 
                 << setw(20) << tog_add << setw(20) << ci_add << setw(20) << co_add 
                 << setw(25) << email_add << pn_add << endl << flush; 
    inFile.close();
    outFile.close();

    remove("Booking List.txt");
    rename("Booking List_temp.txt", "Booking List.txt");

    }
} 
         
        
bool ReturnOption(){ 

    cout << "\n"; 
    printLine(150); 
    bool option; 

    cout << "Enter 0 to return to the main menu\nEnter 1 to exit program\nOption : "; 
    cin >> option; 

    if (option==0) main(); 
} 

void printLine(int i){
   
    for (int j=0; j<i; j++) cout<< "*" ;   
   
    cout << endl;
}

void SendBooking(){
    
    fstream inFile;
    ofstream outFile;

    inFile.open("BookingL.txt");
    outFile.open("Guest Room Allocation.txt");

    if (!outFile) cout << "File Error" << endl;
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

//The data in the booking list (other than date and time) should be editable
//Send Data to Guest Room Allocation
//(If online/got guest registration system, then the data inputted in that registration system will be inputted in a text file and then listed in the booking list text file)
