#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


void To_Rational(int greater, int smaller, int numerator, int denominator){
    bool is_valid = false;
    for (int i = abs(greater); i > 0; --i){
        for (int j = abs(smaller); j > 0; --j){
            if (abs(smaller) % j == 0){
                if (abs(greater) % j == 0){
                    if (greater < 0 || smaller < 0){
                        cout << "-";
                    }
                    cout << (abs(numerator) / j) << '/' << (abs(denominator) / j) << endl;
                    is_valid = true;
                    break;
                }
            }
            else{
                is_valid = false;
            }
        }
        if (is_valid){
            break;
        }
    }
}


void valid(string& number, string& numerator,string& denominator, bool& valid){
    valid = true;
    int len = number.length();
    if (len >= 3) {
        for (int i = 0; i < len; i++) {
            if (number[i] == '/') {
                break;
            }
            else if (!isdigit(number[i]) && number[i] != '-' ) {
                cout << "invalid " << number[i] << ", please enter a valid number000\n";
                valid = false;
                break;
            }
            else if (isdigit(number[i]) || number[i] == '-') {
                numerator += number[i];
            }
        }
        for (int i = len - 1; i > 0; i--) {
            if (number[i] != '/') {
                if (isdigit(number[i]) || number[i] == '-') {
                    denominator += number[i];
                }
                else if (!isdigit(number[i])) {
                    cout << "invalid " << number[i] << ", please enter a valid number111\n";
                    valid = false;
                    break;
                }
            }
            else {
                break;
            }
        }
        reverse(denominator.begin(), denominator.end());
    }
    else {
        for (int i = 0; i < len; i++) {
            if (number[i] == '/') {
                break;
            }
            else if (!isdigit(number[i]) && number[i] != '-') {
                cout << "invalid " << number[i] << ", please enter a valid number333\n";
                valid = false;
                break;
            }
            else if (isdigit(number[i]) || number[i] == '-') {
                numerator += number[i];
            }
        }
        denominator += "1";
    }
}


int main() {
    
    while (true) {
        string frac1, frac2, opr, str_num1, str_num2, str_dom1, str_dom2;
        int num1, num2, dom1, dom2, new_dom, new_num;
        bool valid_num = true;
        cout << "Please enter a rational number operations: \n";
        cin >> frac1 >> opr >> frac2;
        valid(frac1, str_num1, str_dom1, valid_num);
        if (!valid_num) {
            continue;
        }
        valid(frac2, str_num2, str_dom2, valid_num);
        if (!valid_num) {
            continue;
        }

        cout << str_num1 << "\n" << str_dom1 << "\n";
        cout << str_num2 << "\n" << str_dom2 << "\n";

        num1 = stoi(str_num1);
        dom1 = stoi(str_dom1);
        num2 = stoi(str_num2);
        dom2 = stoi(str_dom2);

        if (opr == "+") {
            if (dom1 != dom2) {
                int new_num1, new_num2;
                string result;
                new_dom = int (dom1) * int (dom2);
                new_num = (dom2 * num1) + (dom1 * num2);
                if (new_dom > new_num) {
                    To_Rational(new_dom, new_num, new_num, new_dom);
                } else {
                    To_Rational(new_num, new_dom, new_num, new_dom);
                }
            }
            if (dom1 == dom2){
                string result;
                result = to_string(num1 + num2) + "/" + to_string(dom1); ;

                cout << "result: " << result << endl ;
            }
        }

        else if (opr == "-") {
            new_dom = dom1 * dom2;
            new_num = (num1 * dom2) - (num2 * dom1);
            if (new_dom > new_num) {
                To_Rational(new_dom, new_num, new_num, new_dom);
            } else {
                To_Rational(new_num, new_dom, new_num, new_dom);
            }
        }
    }
    
     return 0;
}
