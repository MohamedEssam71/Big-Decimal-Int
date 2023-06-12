#include<bits/stdc++.h>

#ifndef MAIN_CPP_BIG_DECIMAL_INT_H
#define MAIN_CPP_BIG_DECIMAL_INT_H
using namespace std;

class BigDecimalInt {
private:
    string Decimal_String;
    bool is_Negative = false;
public:
    BigDecimalInt(string decStr);

    BigDecimalInt(int decInt);

    BigDecimalInt();

    bool operator<(BigDecimalInt anotherDec);

    bool operator>(BigDecimalInt anotherDec);

    bool operator==(BigDecimalInt anotherDec);

    BigDecimalInt operator=(BigDecimalInt anotherDec);

    BigDecimalInt operator+(BigDecimalInt anotherDec);

    BigDecimalInt operator-(BigDecimalInt anotherDec);

    friend ostream &operator<<(ostream &out, BigDecimalInt b);

    int getSize();

    char sign();
};


#endif //MAIN_CPP_BIG_DECIMAL_INT_H
