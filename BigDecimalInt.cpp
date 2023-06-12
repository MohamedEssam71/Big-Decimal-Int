#include "BigDecimalInt.h"
#include <regex>

bool is_Transfer = false;

// ---------------- constructors ------------------
BigDecimalInt::BigDecimalInt(string decStr) {
    regex valid("[+-]?[0-9]+");
    bool is_Valid = regex_match(decStr, valid);
    static int cnt = 1;
    if (!is_Valid) {
        cout << "Not Valid Number Follow Rules in " << cnt << " variable" << endl;
        do {
            string temp;
            cout << "Enter a Number: ";
            cin >> temp;

            is_Valid = regex_match(temp, valid);
            if (is_Valid)
                decStr = temp;
            else {
                cout << "Not Valid Number Follow Rules in " << cnt << " variable" << endl;

            }
        } while (!is_Valid);
        cnt++;
    }
    this->is_Negative = (decStr[0] == '-');

    decStr.erase(remove(decStr.begin(), decStr.end(), '-'), decStr.end());
    decStr.erase(remove(decStr.begin(), decStr.end(), '+'), decStr.end());
    reverse(decStr.begin(), decStr.end());

    bool flag = false;
    for (int i = decStr.size() - 1; i >= 0; --i) {
        if (decStr[i] == '0' && !flag) {
            decStr.pop_back();
            continue;
        }
        flag = true;
    }
    reverse(decStr.begin(), decStr.end());
    this->Decimal_String = decStr;

}

BigDecimalInt::BigDecimalInt(int decInt) {
    this->Decimal_String = to_string(decInt);
}

BigDecimalInt::BigDecimalInt() {}
// ------------------------------------------------

//--------------- mathematics operations -----------------------------
bool BigDecimalInt::operator<(BigDecimalInt anotherDec) {
    int x = this->Decimal_String.size();
    int y = anotherDec.Decimal_String.size();

    if (x == y) {
        if (this->Decimal_String < anotherDec.Decimal_String) {
            if ((!this->is_Negative || this->is_Negative) && !anotherDec.is_Negative) {
                return true;
            }
            return false;
        } else {
            if (this->is_Negative && (!anotherDec.is_Negative || anotherDec.is_Negative)) {
                return true;
            }
            return false;
        }

    } else if (y > x) {
        if (!anotherDec.is_Negative && (!this->is_Negative || this->is_Negative)) {
            return true;
        }
        return false;
    } else {
        if (this->is_Negative && (!anotherDec.is_Negative || anotherDec.is_Negative)) {
            return true;
        }
        return false;
    }


}

bool BigDecimalInt::operator>(BigDecimalInt anotherDec) {
    return !((*this < anotherDec) || *this == anotherDec);
}

bool BigDecimalInt::operator==(BigDecimalInt anotherDec) {
    return ((this->Decimal_String == anotherDec.Decimal_String) && this->is_Negative == anotherDec.is_Negative);
}

BigDecimalInt BigDecimalInt::operator+(BigDecimalInt anotherDec) {
    if (!(this->is_Negative && anotherDec.is_Negative)) {
        if ((this->is_Negative || anotherDec.is_Negative) && !is_Transfer) {
            is_Transfer = true;
            return *this - anotherDec;
        }
    }
    bool is_Swapped = false;
    if (*this < anotherDec) {
        swap(*this, anotherDec);
        is_Swapped = true;
    }
    string big = this->Decimal_String;
    string small = anotherDec.Decimal_String;

    BigDecimalInt answer;
    answer.Decimal_String;

    int carry = 0;

    std::reverse(big.begin(), big.end());
    std::reverse(small.begin(), small.end());

    for (int i = 0; i < small.size(); ++i) {
        int add = (big[i] - '0') + (small[i] - '0') + carry;
        answer.Decimal_String.push_back((add % 10) + '0');
        carry = add / 10;
    }

    for (int i = small.size(); i < big.size(); ++i) {
        int add = (big[i] - '0') + carry;
        answer.Decimal_String.push_back((add % 10) + '0');
        carry = add / 10;
    }

    if (carry) answer.Decimal_String.push_back(carry + '0');

    if (this->is_Negative) {
        answer.is_Negative = true;
    }
    if (is_Swapped) {
        swap(*this, anotherDec);
    }
    reverse(answer.Decimal_String.begin(), answer.Decimal_String.end());
    is_Transfer = false;

    return answer;

}

BigDecimalInt BigDecimalInt::operator-(BigDecimalInt anotherDec) {
    if (!(this->is_Negative && anotherDec.is_Negative)) {
        if ((this->is_Negative || anotherDec.is_Negative) && !is_Transfer) {
            is_Transfer = true;
            return *this + anotherDec;
        }
    }

    bool is_Swapped = false;
    if (*this < anotherDec) {
        swap(*this, anotherDec);
        is_Swapped = true;
    }
    string big = this->Decimal_String;
    string small = anotherDec.Decimal_String;
    BigDecimalInt answer;
    int carry = 0;

    std::reverse(big.begin(), big.end());
    std::reverse(small.begin(), small.end());

    for (int i = 0; i < small.size(); ++i) {
        int sub = (big[i] - '0') - (small[i] - '0') - carry;
        if (sub < 0) {
            carry = 1;
            sub += 10;
        } else {
            carry = 0;
        }
        answer.Decimal_String.push_back(sub + '0');
    }
    for (int i = small.size(); i < big.size(); ++i) {
        int sub = (big[i] - '0') - carry;
        if (sub < 0) {
            carry = 1;
            sub += 10;
        } else {
            carry = 0;
        }
        answer.Decimal_String.push_back(sub + '0');
    }

    string temp;
    bool found = false;
    reverse(answer.Decimal_String.begin(), answer.Decimal_String.end());
    for (int i = 0; i < answer.getSize(); ++i) {
        if ((answer.Decimal_String[i] == '0' && !found) || (answer.Decimal_String[i] == ' ')) continue;
        temp += answer.Decimal_String[i];
        found = true;

    }

    if (temp.empty()) temp.push_back('0');

    std::reverse(temp.begin(), temp.end());
    if ((this->is_Negative && anotherDec.is_Negative) || (!this->is_Negative && !anotherDec.is_Negative)) {
        if (is_Swapped) {
            this->is_Negative = !this->is_Negative;
        }

    }
    if (this->is_Negative) {
        answer.is_Negative = true;
    }
    std::reverse(temp.begin(), temp.end());

    if (is_Swapped) {
        this->is_Negative = !this->is_Negative;
        swap(*this, anotherDec);
    }

    is_Transfer = false;
    answer.Decimal_String = temp;

    return answer;

}

BigDecimalInt BigDecimalInt::operator=(BigDecimalInt anotherDec) {
    this->Decimal_String = anotherDec.Decimal_String;
    this->is_Negative = anotherDec.is_Negative;
    return *this;
}
//-------------------------------------------------------------------------

// ----------------------- getters --------------------------
int BigDecimalInt::getSize() {
    return this->Decimal_String.size();
}

char BigDecimalInt::sign() {
    if (this->is_Negative) return '-';

}
//-----------------------------------------------------------

//------------------------ friends --------------------------
ostream &operator<<(ostream &out, BigDecimalInt b) {
    out << b.sign() << b.Decimal_String;
    return out;
}
//-----------------------------------------------------------

