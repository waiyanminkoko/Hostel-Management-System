#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*void bubblesort()
    {
        for( int i=1;i<n ;i++ )//for n-1 passes
        {
          //In pass i,compare the first n-i elements
          //with their next elements
          for( int j=0; j<n-1; j++)
            {
                if(arr[j] > arr[j+1])
                {
                    string temp;
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }

            }
        }
    }
*/
int main() {
//bubble sort numbers
   /*int i, j,temp;
   int a[5] = {10,2,0,43,12};
   cout <<"Input list ...\n";
   for(i = 0; i<5; i++) {
   cout <<a[i]<<"\t";
}
cout<<endl;
for(i = 0; i<5; i++) {
   for(j = i+1; j<5; j++)
   {
      if(a[j] < a[i]) {
         temp = a[i];
         a[i] = a[j];
         a[j] = temp;
      }
   }
}
cout <<"Sorted Element List ...\n";
for(i = 0; i<5; i++) {
   cout <<a[i]<<"\t";
   }*/
//bubble sort strings
string list[5] = {"a", "e", "d", "f", "c"};
for( int i=1;i<5 ;i++ )//for n-1 passes
        {
          //In pass i,compare the first n-i elements
          //with their next elements
          for( int j=0; j <5-1; j++)
            {
                if(list[j] > list[j+1])
                {
                    string temp;
                    temp = list[j];
                    list[j] = list[j+1];
                    list[j+1] = temp;
                    cout << list[j] << endl;
                }

            }
        }

}
