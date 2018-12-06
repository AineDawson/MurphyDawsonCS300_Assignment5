#ifndef UPCHASHTABLEFUNCTIONS_H_
#define UPCHASHTableFUNCTIONS_H_
#include <iostream>
#include <fstream>
#include "HashTable.h"
#include "UPC.h"
using namespace std;
//Dawson Murphy
//This program contains the function readData, which reads data from the text file upc_corpus.txt into 
//a HashTable. This is for use by the program HashScanner.

template <class T>
class UPCHashFunctions: public HashTable<T>{
    public:
        void readData(UPCHashFunctions<UPC>&, int);
};

//Reads data from the file upc_corpus.txt into a HashTable.
template <class T>
void UPCHashFunctions<T>::readData(UPCHashFunctions<UPC>& dB, int numb){
    string id, data;
    ifstream upcfile;
    upcfile.open("upc_corpus.txt"); //opens the file
    getline(upcfile, id); //Gets past first line, which holds header info
    for(int i=0; i<=numb;i++){ //Gets entries
        getline(upcfile,id, ',');
        getline(upcfile, data);
        UPC temp(id,data); //Takes data from the line to create temporary UPC object
        dB.insertItem(id,temp); //Inserts item into tree
    }
}

#endif