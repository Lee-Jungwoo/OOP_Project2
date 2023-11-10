#ifndef _INF_INT_H_
#define _INF_INT_H_

#include <iostream>
#include <cmath>

using namespace std;

class inf_int
{
private :
    string digits;  // You may modify this to "string digits;" if you want.
    unsigned int length;
    bool thesign;   // true if positive , false if negative.
    // ex) 15311111111111111 -> digits="11111111111111351", length=17, thesign=true;
    // ex) -12345555555555 -> digits="55555555554321", length=14, thesign=false
    // You may modify or add private members of inf_int class. So, it is OK to insert Add() private member function in inf_int class. However, You may not modify public members of inf_int class.
    
    bool isSameSignWith(const inf_int& anotherNum) const;
    
    friend string addAbs(const inf_int&, const inf_int&); // add two inf_int's absolute values.
    
    friend string subAbs(const inf_int&, const inf_int&); // subtract two inf_int's absolute values.
    
    int compareAbs(const inf_int&) const;
    void removeTrail();
    

public :


    inf_int() : digits("0"), length(0), thesign(true){};               // assign 0 as a default value
    inf_int(int a) : inf_int(to_string(a)){};
    inf_int(const string&);   // you may modify this to "inf_int(const string);"
    inf_int(const inf_int& n): digits(n.digits), length(n.length), thesign(n.thesign){}; // copy constructor
    ~inf_int(){}; // destructor

    inf_int& operator=(const inf_int&); // assignment operator

    friend bool operator==(const inf_int& , const inf_int&);
    friend bool operator!=(const inf_int& , const inf_int&);
    friend bool operator>(const inf_int& , const inf_int&);
    friend bool operator<(const inf_int& , const inf_int&);

    friend inf_int operator+(const inf_int& , const inf_int&);
    friend inf_int operator-(const inf_int& , const inf_int&);
    friend inf_int operator*(const inf_int& , const inf_int&);
    // friend inf_int operator/(const inf_int& , const inf_int&); // not required

    friend ostream& operator<<(ostream& , const inf_int&);
    // friend istream& operator>>(istream& , inf_int&);    // not required
};

    string padd(const string&, const string&); //fill deficient digits with Zero.
                                                      /*
                                                        first argument is longer
                                                      */
    string powerOfTen(string num,int exp);          //add 'zero's in front of the string.
    string stringAdd(const string&, const string&); //add two numbers in string representation
    string mul(string &num1, char num2);            //multiply num1 with num2. num2 is a single digit number character.


#endif