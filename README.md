# BigDecimalInt Class
This a big decimal int data type in c++

Different variations of types `int` and `float` exist in C++ and other languages. They are limited by minimum and maximum values depending on the number of bytes used to store the number. We need versions of these types with unlimited bounds. Java solves this problem by providing `BigInteger` and `BigDecimal` classes. In this problem, it is required to develop a new C++ type (class) that can hold unlimited decimal integer values and perform arithmetic operations on them.

## Problem Description

You will develop a C++ class, `BigDecimalInt`, that supports writing statements with very long integer values like these:

```cpp
BigDecimalInt num1("123456789012345678901234567890");
BigDecimalInt num2("+113456789011345678901134567890");
BigDecimalInt num3("-200000000000000000000000000000");
BigDecimalInt num4 = num2 + num1;
BigDecimalInt num5 = num2 - num1;

cout << "num1 = " << num1 << endl;
cout << "num2 = " << num2 << endl;
// Next statement will print 236913578023691357802369135780
cout << "num2 + num1 = " << num4 << endl;
// Next statement will print -313456789011345678901134567890
cout << "num2 - num1 = " << num5 << endl;
```

## Team members
| Name | ID |
|------|----|
| Mohamed Essam Mahmoud Osman | 20210346 |
| Karim Mohamed Hassib | 20210298 | 
| Ali Tarek Ahmed | 20210252 |
