#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
char assign_bed(int room, char bed);  
int assign_room(char bed, int room);
int assign_floor(int room, int floor);
bool BoarderRoom();
bool ReturnOption();
void printLine(int i);



int main() {
    BoarderRoom();
    return 0;
}

bool BoarderRoom() {

    ifstream inFile;
    ofstream outFile;
    string name, level, type, school, nationality;
    string name_a[999], level_a[999],type_a[999], school_a[999],nationality_a[999]; //Hall + Floor + Room + Bed
    char hall, gender; 
    char hall_a[999], bed_a[999], gender_a[999];
    int floor_a[999], room_a[999];
    int num_boarders=0, option = 1;
    int floor, floor_aa, floor_bb, room, room_aa, room_bb;
    char bed, bed_aa, bed_bb;
    bool LOOP;

    floor_aa = 2;
    room_aa = 1;
    bed_aa = 64; //A-D 65-68, start with 64 in order to make sure the first bed is A

    floor_bb = 2;
    room_bb = 1;
    bed_bb = 64;

    inFile.open("Boarders Details.txt");
    outFile.open("Boarders Room Allocation test.txt");

    if (!inFile) {
        cout << "Error opening file.";
    }
    else if (!outFile) {
        cout << "Error writing file.";
    }
    else {
        //continue code
    cout <<left;
    cout << "******ROOM ALLOCATION*****" << endl;
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
                
            else {
                cout << "DATA Input Error" << endl;
            }
            
                num_boarders++;
        }
            
        }
        inFile.close();
        outFile.close();
        cout << "1.Search Boarder\n2.Edit Boarder's Cluster\n3.Exit.\nOption: ";
        cin >> option;

        while (option < 1 && option > 3){
            cout  << "Invalid Input!\n";
            cout << "1.Search Boarder\n2.Edit Boarder's Cluster\n3.Exit.\nOption: ";
            cin >> option;
        }
//editing boarder
    if (option == 1){
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
            inFile.open("Boarders Room Allocation test.txt");
            
            if (!inFile){
                cout << "Error opening file." << endl;
            }
            else {//continue

             while (!inFile.eof()) {
                
                inFile >> name_a[index] >> level_a[index] >> setw(20) >> type_a[index] >> setw(20) >> school_a[index] >> hall_a[index] >> floor_a[index] >> room_a[index] >> bed_a[index];
                if(inFile.fail()) {break;}
                if (name_a[index] == name_search)
                {
                    cout << setw(25) << name_a[index] << setw(20) << level_a[index] << setw(20) << type_a[index] << setw(20) << school_a[index] << hall_a[index] << floor_a[index] << room_a[index] << bed_a[index] << endl;
                    break; 
                }
                index++;

                }
                
            }
            inFile.close();
        }

    
    else if (option == 2) {
            
    //EditBoarderRoom
    bool option_exit = 1;
    while (option_exit == true) {
    string name_edit;
    char hall_edit, bed_edit;
    int floor_edit, room_edit;
    int index = 0, index_found; 
    bool found = false;
    bool save;
    ifstream inFile;
    ofstream outFile;
            
        cout << "Name of Boarder:";
        cin >> name_edit;
            
        for (int i = 0; i <= num_boarders;i++) {
                if (name_edit == name_a[i]) {
                    found = true;
                    index_found = i;
                    cout << "Index Found = " << index_found << endl;
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
                    cout << "Index Found = " << index_found << endl;
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

        inFile.open("Boarders Room Allocation test.txt");
        outFile.open("editboarderroom.txt");   

        if (save == 1) {
            if (!inFile) {
                cout << "Error opening file.";
            }
            else if (!outFile) {
                cout << "Error writing file.";
            }
            else {//continue
             while (!inFile.eof()) {
                
                inFile >> name_a[index] >> level_a[index] >> setw(20) >> type_a[index] >> setw(20) >> school_a[index] >> hall_a[index] >> floor_a[index] >> room_a[index] >> bed_a[index];
                if(inFile.fail()) {break;}
                if (name_a[index] == name_a[index_found])
                {
                    hall_a[index] = hall_edit;
                    floor_a[index] = floor_edit;
                    room_a[index] = room_edit;
                    bed_a[index] = bed_edit;
                }
                outFile << left;
                outFile << setw(25) << name_a[index] << setw(20) << level_a[index] << setw(20) << type_a[index] << setw(20) << school_a[index] << hall_a[index] << floor_a[index] << room_a[index] << bed_a[index] << endl; 
                index++;

                }
                
            }
        inFile.close();
        outFile.close();
        }
        
        cout << "1. Continue Edit\n0. Exit Edit\nOption: ";
        cin >> option_exit;
        
        }
    remove("Boarders Room Allocation test.txt");
	rename("editboarderroom.txt","Boarders Room Allocation test.txt"); 
    }

    LOOP = ReturnOption();
    return LOOP;

}

int assign_room(char bed, int room) {
    
    if ((room == 1 || room == 2 || room == 6) && bed >= 68) { //from room-3 to 5, change room if 2 beds are used
        room++;
    }
    else if ((room >= 3 && room <= 5) && bed >= 66){
        room++;
    }
    else if (bed >= 64){
        //continue
    }
    else {
        cout << "Room Assignment Error";
    }
 
    return room;
}

char assign_bed(int room, char bed) {
    
    if (room == 1 || room == 2 || room == 6) { //from room 1 to 2, change room if 4 beds are used
        
        if (bed >= 68) {
            bed = 65;
        }
        else {bed++;}
    }
    else if (room >= 3 && room <= 5) { //from room-3 to 5, change room if 2 beds are used
        if (bed >= 66) {
            bed = 65;
        }
        else {bed++;}
            
    }
    else {
        cout << "Bed Assignment Error";
    }
   
    return bed;
}

int assign_floor(int room, int floor) {
   
    if (room > 6) { //from room 1 to 2, change room if 4 beds are used
        floor++;
    }
    else if (room >= 1 && room <= 6) { //from room-3 to 5, change room if 2 beds are used
        //continue
    }
    
    else {//if room 6 is filled, change cluster left to right
        cout << "Floor Assignment Error";        
    }
   
    return floor;
}

//order from Hall A to Hall G


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
        cout<< "*" ;   
    } 
    cout << endl;
}