#include <iostream>
#include "UPCHashFunctions.h"
#include "UPC.h"
#include <ctime>
using namespace std;
//Dawson Murphy
//This program reads in information for items (UPC code and descriptions) and stores it into a HashTable, the number of items
//being read in is determined by the user.
//The program then allows the user to input UPC codes, and returns the corresponding item description if there is one. The program
//also returns the time it took to complete the queuery.

int main(){
    UPCHashFunctions<UPC> hF;
    cout<<"Welcome to Barcode HashTable Scanner. You can enter a UPC barcode to retrieve data for an item."<<endl;
    cout<<"Enter Q to leave the program."<<endl;
    cout<<"How much of the database would you like to load at this time?"<<endl;
    int numb;
    cin>>numb;
    hF.readData(hF, numb);
    string entry;
    cout<<"Please enter a UPC code: "<<endl;
    cin>>entry; //Takes first user entered code
    while(entry!="Q"){ //Continues until user enters Q
        cout<<"UPC Code: "<<entry<<endl;
        try{ //Attempts to find the item
            clock_t begin=clock(); //Gets start time
            HashObj<UPC> result=hF.findItem(entry); //Searches for and returns the item
            clock_t end=clock(); //Gets end time
            double timeTaken=double(end-begin);
            cout<<result<<endl; //Prints the item description
            cout<<"Time in microseconds: "<<timeTaken<<endl; //Prints the time it took to find the item
        }catch(int e){ //If the item was not found
            cout<<"Could not find an item matching that UPC Code."<<endl;
        }
        //Asks for and accepts the next user entered code
        cout<<"Please enter a UPC code: "<<endl; 
        cin>>entry;
    }
    //When the user exits the program
    cout<<"Good Bye"<<endl;
}