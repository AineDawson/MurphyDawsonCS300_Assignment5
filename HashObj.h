#ifndef HASHOBJ_H_
#define HASHOBJ_H_
#include <iostream>
using namespace std;
//Dawson Murphy
//Program is for HashObjects, exclusively for use by HashMap. Takes in a string as a key, and some
//object that the key points to.

template <class T>
class HashObj{
    public:
        string key;
        T object;

        //Constructor for HashObject. 
        HashObj(string _key, T _object){
            key=_key;
            object=_object;
        };
        //Default Constructor
        HashObj(){};

        //Following methods overload operators to allows HashObjects to be compared to one another
        friend bool operator==(string k, HashObj o){
            return k==o.key;
        };
        friend bool operator==(HashObj o, string k){
            return o.key==k;
        };
        friend bool operator<(HashObj o1, HashObj o2){
            return o1.key<o2.key;
        };
        friend bool operator>(HashObj o1, HashObj o2){
            return o1.key>o2.key;
        };
        friend bool operator<(string s, HashObj o2){
            return s<o2.key;
        };
        friend bool operator>(string s, HashObj o2){
            return s>o2.key;
        };

        //Allows a UPC object to take on the code and info values of another
        void operator=(HashObj o){
            key=o.key;
            object=o.object;
        }
        //overloads << to print HashObjects
        friend ostream& operator<<(ostream& os, HashObj o){
            os<<o.object<<ends;
            return os;
        }
};
#endif