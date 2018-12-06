#ifndef HASHTABLE_H_
#define HASHTABLE_H_
#include <iostream>
#include <list>
#include "HashObj.h"
#include "BinarySearchTree.h"
using namespace std;
//Dawson Murphy
//Implementation for a HashTable using Seperate Chaining collision resolution. This does so by using 
//an array of Binary Search Trees. The hash function determines were in the array to put the object, and then the
//BST handles storing the collided objects. This program requires that the keys be string values.

template <class T>
class HashTable: private BinarySearchTree<T>{
    int size; //size of hash
    BinarySearchTree<HashObj<T>> table[10];

    public:
        //Constructor
        HashTable(int _size=10) { 
            size=_size; 
            table[size];
        } 
        int hashFunction(string key);
        void insertItem(string, T&);
        HashObj<T> findItem(string key);

        //Overloads ostream operator to print hashmap,
        //this is mainly for testing
        friend ostream& operator<<(ostream& os,HashTable& hash) { 
            for (int i=0;i<hash.size;i++) { 
                os<<i<<": "; 
                hash.table[i].printInOrder();
                cout<<endl;
            } 
            return os;
        } 
};

//Takes strings and returns a key by getting asc values
template <class T>
int HashTable<T>::hashFunction(string key){
    int val=0; 
    for(int i=0;i<key.length(); i++)
        val+=key[i]; 
    return val%this->size; 
}

//Inserts the keys into the hashmap
template <class T>
void HashTable<T>::insertItem(string key, T& object) { 
    HashObj<T> temp(key,object);
    int index=hashFunction(key); 
    table[index].insert(temp);
} 

//Finds an object based on its key
template <class T>
HashObj<T> HashTable<T>::findItem(string key) { 
    // get the hash index of key 
    int index=hashFunction(key);  
    return table[index].search(key);
} 


#endif