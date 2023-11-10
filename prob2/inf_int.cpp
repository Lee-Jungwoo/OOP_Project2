#include "inf_int.h"

using namespace std;



bool inf_int::isSameSignWith(const inf_int &anotherNum) const
{
    if (thesign == anotherNum.thesign)
        return true;
    else
        return false;
}

/*
when num1's length is greater than num2's length,
fill num2 with zero.
*/
string padd(const string &num1, const string &num2)
{
    string s = num2;
    s.append(num1.length() - num2.length(), '0');
    return s;
}


/*
add 'zero's in front of the string.
*/
string powerOfTen(string num, int exp){
    num.insert(0,exp,'0');
    return num;
}

/*
multiply num1 with num2. num2 is a single digit number character.
returns result string.
*/
string mul(const string &num1, char num2)
{
    string result = "0";
    int a,b,prod;
    
    for(int i=0;i<num1.length();i++){
        a = num1[i] - '0';
        b = num2 - '0';
        prod = a*b;
        string tmp = to_string(prod);
        reverse(tmp.begin(),tmp.end());
        result = stringAdd(result, powerOfTen(tmp,i));
    }
    return result;
}

/*
returns the sum of absolute values.
*/
string addAbs(const inf_int &num1, const inf_int &num2) 
{
    int a, b;
    bool carry = false; // true if carry is present.

    string result;
    const inf_int *longerNum = (num1.length > num2.length) ? &num1 : &num2;
    result = "";

    int i;

    for (i = 0; i < num1.length && i < num2.length; i++)
    {
        a = num1.digits[i] - '0';
        b = num2.digits[i] - '0';

        if (carry)
            a += 1;

        if (a + b > 9)
            carry = true;
        else
            carry = false;

        result.append(1, (a + b) % 10 + '0');
    }

    for (; i < num1.length || i < num2.length; i++)
    {
        result += longerNum->digits[i];
    }
    return result;
}

/*
returns the sum of two integers in string representation.
*/
string stringAdd(const string& num1, const string& num2){
    int a, b;
    bool carry = false; // true if carry is present.

    string result;
    const string *longerNum = (num1.length() > num2.length()) ? &num1 : &num2;
    result = "";

    int i;

    for (i = 0; i < num1.length() && i < num2.length(); i++)
    {
        a = num1[i] - '0';
        b = num2[i] - '0';

        if (carry)
            a += 1;

        if (a + b > 9)
            carry = true;
        else
            carry = false;

        result.append(1, (a + b) % 10 + '0');
    }

    for (; i < num1.length() || i < num2.length(); i++)
    {
        
        
        if(carry){
            result += (*longerNum)[i] + 1;
            carry = false;    
        }
        else result += (*longerNum)[i];
    }

    return result;
}

/* 
returns the difference of absolute values.
*/
string subAbs(const inf_int &num1, const inf_int &num2) 
{
    int a, b, tmp;
    bool borrow = false;
    string result;
    string big, small;
    switch (num1.compareAbs(num2))
    {
    case 1:
    case 0:
        big = num1.digits;
        small = num2.digits;
        break;
    case -1:
        big = num2.digits;
        small = num1.digits;
        break;

    default:
        break;
    }
    small = padd(big, small);

    for (int i = 0; i < big.length(); i++)
    {
        a = big[i] - '0';
        b = small[i] - '0';

        if (borrow)
        {
            if (a == 0)
            {
                borrow = true;
                a = 9;
            }
            else
            {
                borrow = false;
                a--;
            }
        }
        if (a < b)
        {
            borrow = true;
            a += 10;
        }

        tmp = a - b;
        result += (tmp + '0');
    }
    return result;
}



/*
compares absolute value.
*/
int inf_int::compareAbs(const inf_int &num2) const
{
    if (length > num2.length)
    {
        return 1;
    }
    else if (length < num2.length)
    {
        return -1;
    }
    else
    {
        for (int i = length - 1; i >= 0; i--)
        {
            if (digits[i] > num2.digits[i])
                return 1;
            else if (digits[i] < num2.digits[i])
                return -1;
            else
                continue;
        }
        return 0;
    }
}

/*
removes the leading zeros in the string.
ex) 001254 => 1254
*/
void inf_int::removeTrail()
{
    size_t cnt = digits.find_last_not_of('0') + 1;
    digits = digits.substr(0, (cnt != 0) ? cnt : 1);
    length = digits.length();
}

/*
copy constructor
*/
inf_int::inf_int(const string &num)
{
    string tmp;
    if (!isnumber(num[0]))
    {
        tmp = num.substr(1, digits.length() - 1);
        thesign = (num[0] == '+') ? true : false;
    }
    else
    {
        tmp = num;
        thesign = true;
    }

    reverse(tmp.begin(), tmp.end());
    digits = tmp;

    length = digits.length();
}


inf_int& inf_int::operator=(const inf_int &number)
{ 
    if((*this) == number)
        return *this;
    digits = number.digits;
    length = number.length;
    thesign = number.thesign;
    return *this;
}

bool operator==(const inf_int &num1, const inf_int &num2)
{
    if (num1.digits == num2.digits && num1.thesign == num2.thesign)
        return true;
    else
        return false;
}

bool operator!=(const inf_int &num1, const inf_int &num2)
{
    if (num1.digits == num2.digits && num1.thesign == num2.thesign)
        return false;
    else
        return true;
}

bool operator>(const inf_int &num1, const inf_int &num2)
{
    if (num1.thesign && !num2.thesign)
    {
        return true;
    }
    else if (!num1.thesign && num2.thesign)
    {
        return false;
    }
    else if (num1.thesign)
    {
        if (num1.length > num2.length)
            return true;
        else if (num1.length == num2.length)
        {
            for (int i = 0; i < num1.length; i++)
            {
                if (num1.digits[i] > num2.digits[i])
                    return true;
                else if (num1.digits[i] < num2.digits[i])
                    return false;
                else
                    continue;
            }
        }
        else
            return false;
    }
    else
    {
        if (num1.length > num2.length)
            return false;
        else if (num1.length == num2.length)
        {
            for (int i = 0; i < num1.length; i++)
            {
                if (num1.digits[i] > num2.digits[i])
                    return false;
                else if (num1.digits[i] < num2.digits[i])
                    return true;
                else
                    continue;
            }
        }
        else
            return true;
    }
    return false;
}

bool operator<(const inf_int &num1, const inf_int &num2)
{
    return !(num1 > num2) && (num1 != num2) ? true : false;
}

inf_int operator+(const inf_int &num1, const inf_int &num2)
{
    inf_int resultNum;
    if (num1.isSameSignWith(num2))
    {
        resultNum.digits = addAbs(num1, num2);
        resultNum.length = resultNum.digits.length();
        resultNum.thesign = num1.thesign;
    }
    else
    {
        resultNum.digits = subAbs(num1, num2);
        resultNum.length = resultNum.digits.length();
        if (num1.compareAbs(num2) >= 0)
            resultNum.thesign = true;
        else
            resultNum.thesign = false;
    }
    resultNum.removeTrail();
    return resultNum;
}

inf_int operator-(const inf_int &num1, const inf_int &num2)
{
    inf_int resultNum;
    if (!num1.isSameSignWith(num2))
    {
        resultNum.digits = addAbs(num1, num2);
        resultNum.thesign = num1.thesign;
        resultNum.length = resultNum.digits.length();
    }
    else
    {
        resultNum.digits = subAbs(num1, num2);
        resultNum.thesign = !(num1.thesign xor (num1.compareAbs(num2) >= 0));
        resultNum.length = resultNum.digits.length();
    }
    resultNum.removeTrail();
    return resultNum;
}

inf_int operator*(const inf_int &num1, const inf_int &num2)
{
    inf_int result(0);
    result.thesign = !(num1.thesign xor num2.thesign);

    for(int i=0; i<num2.length; i++)
        result.digits = stringAdd(result.digits,powerOfTen(mul(num1.digits,num2.digits[i]),i));

    result.length = result.digits.length();
    return result;
}

/*inf_int operator/(const inf_int& , const inf_int&){

    } // not required
*/

ostream &operator<<(ostream &os, const inf_int &num)
{
    string tmp = "";

    for (int i = num.digits.length() - 1; i >= 0; i--)
    {
        tmp.append(1, num.digits[i]);
    }
    os << (num.thesign ? "+" : "-") << " " << tmp;

    return os;
}

/*istream& operator>>(istream& , inf_int&){

    }    // not required 
*/
