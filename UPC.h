#ifndef UPC_H_
#define UPC_H_
#include <iostream>
using namespace std;
//Dawson Murphy
//This program is for an object UPC, which holds an items UPC code and description.

class UPC{
        string code, info;
    public:
        //Constructor for UPC object. Leaves code as NUll and info as empty 
        //string if not parameters given
        UPC(string _code="", string _info=""){
            code=_code;
            info=_info;
        };
        //Following methods overload operators to allows UPC objects to be compared to one another
        friend bool operator==(string k, UPC d){
            return k==d.code;
        };
        friend bool operator==(UPC d, string k){
            return d.code==k;
        };
        friend bool operator<(UPC k1, UPC k2){
            return k1.code<k2.code;
        };
        friend bool operator>(UPC k1, UPC k2){
            return k1.code>k2.code;
        };
        //Allows a UPC object to take on the code and info values of another
        void operator=(UPC k2){
            code=k2.code;
            info=k2.info;
        }
        //overloads << to print UPC objects
        friend ostream& operator<<(ostream& os, UPC p);
        
};
//Allows UPC object to be printed. 
//When a UPC object is printed, it prints only the objects 
//information,not its code.
ostream& operator<<(ostream& os, UPC p){
            os<<p.info<<ends;
            return os;
        }

#endif