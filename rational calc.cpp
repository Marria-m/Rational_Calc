#include <iostream>
#include <string>
#include <regex>
#include <algorithm>
using namespace std;

// Mariam Ehab 20231160
// Function to print the rational number in the form of a/b
void To_Rational(int greater, int smaller, int numerator, int denominator){
    bool is_valid = false;  // flag to check if the fraction is valid

    // iterate through possible divisors of the greater number
    for (int i = abs(greater); i > 0; --i) {
        // iterate through possible divisors of the smaller number
        for (int j = abs(smaller); j > 0; --j) {
            // check if j is a divisor of the smaller number
            if (abs(smaller) % j == 0) {
                // check if j is also a divisor of the greater number
                if (abs(greater) % j == 0) {
                    // if either number is negative, print a minus sign
                    if (greater < 0 || smaller < 0) {
                        cout << "-";
                    }
                    // print the rational number
                    cout << (abs(numerator) / j) << '/' << (abs(denominator) / j) << endl;
                    // set the flag to true, indicating a valid fraction
                    is_valid = true;
                    // break out of the inner loop
                    break;
                }
            }
            else {
                // if j is not a divisor of the smaller number, set the flag to false
                is_valid = false;
            }
        }
        // if a valid fraction has been found, break out of the outer loop
        if (is_valid) {
            break;
        }
    }
}

// Mariam Ehab 20231160
// Function for case1: A/B (opr) C/D
void cs1 (string& equation, string& opr, string& num1, string& num2, string& den1, string& den2){
    int len = equation.length();

    // iterate through the equation from left to right
    for (int i = 0; i < len; i++) {
        // if the current character is a division symbol '/'
        if (equation[i] == '/') {
            // iterate through the equation from right to left
            for (int j = i + 1; j < len; j++) {
                // if the current character is a space ' ', it means we have found the operator
                if (equation[j] == ' ') {
                    opr += equation[j + 1];  // add the operator to the opr string
                    break;  // break out of the inner loop
                }
                else {
                    den1 += equation[j];  // add the current character to the denominator num1
                }
            }
            break;  // break out of the outer loop
        }
        else {
            num1 += equation[i];  // add the current character to the numerator num1
        }
    }

    // iterate through the equation from right to left
    for (int i = len; i > 0; i--) {
        // if the current character is a division symbol '/'
        if (equation[i] == '/') {
            for (int j = i - 1; j > 0; j--) {
                // if the current character is a space ' ', it means we have found the operator
                if (equation[j] == ' ') {
                    break;  // break out of the inner loop
                }
                else {
                    num2 += equation[j];  // add the current character to the numerator num2
                }
            }
            break;  // break out of the outer loop
        }
        else {
            den2 += equation[i];  // add the current character to the denominator num2
        }
    }
    // reverse the numerator num2 and denominator den2
    reverse(num2.begin(), num2.end());
    reverse(den2.begin(), den2.end());
}


// Mariam Ehab 20231160
// Function for case2: A (opr) B
void cs2(string& equation, string& opr, string& num1, string& num2, string& den1, string& den2){
    int len = equation.length();

    // iterate through the equation from left to right
    for (int i = 0; i < len; i++) {
        // if the current character is a space ' '
        if (equation[i] == ' '){
            // add the next character (the operator) to the opr string
            opr = equation[i + 1];
            // iterate through the equation from the next character after the space
            for (int j = i + 2; j < len; j++){
                // add the current character to the numerator num2
                num2 += equation[j];
            }
            break;  // break out of the outer loop
        }
        else {
            num1 += equation[i];  // add the current character to the numerator num1
        }
    }
    // set the denominator of the first, second fraction to 1
    den1 = "1";
    den2 = "1";
}


// Mariam Ehab 20231160
// Function for case3: A (opr) B/C
void cs3(string& equation, string& opr, string& num1, string& num2, string& den1, string& den2){
    int len = equation.length();

    // iterate through the equation from left to right
    for (int i = 0; i < len; i++) {
        // if the current character is a space ' '
        if (equation[i] == ' '){
            // add the next character (the operator) to the opr string
            opr = equation[i + 1];
            // iterate through the equation from the next character after the space
            for (int j = i + 3; j < len; j++){
                // if the current character is a division symbol '/'
                if (equation[j] == '/'){
                    // iterate through the equation from the next character after the division symbol
                    for (int x = j + 1; x < len; x++) {
                        den2 += equation[x];  // add the current character to the denominator den2
                    }
                    break;  // break out of the inner loop
                }
                num2 += equation[j];  // add the current character to the numerator num2
            }
            break;  // break out of the outer loop
        }
        else {
            num1 += equation[i];  // add the current character to the numerator num1
        }
    }
    den1 = "1";  // set the denominator of the first fraction to 1
}


// Mariam Ehab 20231160
// Function for case3: A/B (opr) C
void cs4(string& equation, string& opr, string& num1, string& num2, string& den1, string& den2){
    int len = equation.length();

    // iterate through the equation from left to right
    for (int i = 0; i < len; i++) {
        // if the current character is a division symbol '/'
        if (equation[i] == '/') {
            // iterate through the equation from the next character after the division symbol
            for (int j = i + 1; j < len; j++) {
                // if the current character is a space ' '
                if (equation[j] == ' ') {
                    // add the next character (the operator) to the opr string
                    opr = equation[j + 1];
                    // iterate through the equation from the next character after the space
                    for (int x = j + 3; x < len; x++){
                        // add the current character to the numerator num2
                        num2 += equation[x];
                    }
                    // break out of the inner loop
                    break;
                }
                else {
                    // add the current character to the denominator den1
                    den1 += equation[j];
                }
            }
            break;  // break out of the outer loop
        }
        else {
            // add the current character to the numerator num1
            num1 += equation[i];
        }
    }

    // set the denominator of the second fraction to 1
    den2 = "1";
}


int main() {

    // Mariam Ehab 20231160
    regex case1("[-+]?[0-9]+[/][-+]?[1-9]+[ ][+-/*]{1}[ ][-+]?[1-9]+[/][-+]?[1-9]+");  // case: A/B (opr) C/D
    regex case2("[-+]?[0-9]+[ ][+-/*]{1}[ ][-+]?[1-9]+");  // case: A (opr) B
    regex case3("[-+]?[0-9]+[ ][+-/*]{1}[ ][-+]?[1-9]+[/][-+]?[1-9]+");  // case: A (opr) B/C
    regex case4("[-+]?[1-9]+[/][-+]?[1-9]+[ ][+-/*]{1}[ ][-+]?[1-9]+");  // case: A/B (opr) C

    cout << "Please enter a rational number operations (or exit):\n";
    while (true) {
        string frac1, opr, str_num1, str_num2, str_dom1, str_dom2;
        int num1, num2, dom1, dom2, new_dom, new_num;

        // Mariam Ehab 20231160
        getline(cin, frac1);
        if (frac1 == "exit") {
            cout << "Thank you for using rational number calculator";
            break;
        }
        else {
            if (regex_match(frac1, case1)) {
                cs1(frac1, opr, str_num1, str_num2, str_dom1, str_dom2);
            }
            else if (regex_match(frac1, case2)){
                cs2(frac1, opr, str_num1, str_num2, str_dom1, str_dom2);
            }
            else if (regex_match(frac1, case3)){
                cs3(frac1, opr, str_num1, str_num2, str_dom1, str_dom2);
            }
            else if (regex_match(frac1, case4)){
                cs4(frac1, opr, str_num1, str_num2, str_dom1, str_dom2);
            }
            else {
                cout << "the equation must be like A/B (the operation) C/D\n and B,D cannot be zero\n try again\n";
                continue;
            }

            num1 = stoi(str_num1);
            dom1 = stoi(str_dom1);
            num2 = stoi(str_num2);
            dom2 = stoi(str_dom2);

            
            // Rahma Bahgat 20231056
            if (opr == "+") {
                new_dom = dom1 * dom2;
                new_num = (dom2 * num1) + (dom1 * num2);
                if (new_dom > new_num) {
                    To_Rational(new_dom, new_num, new_num, new_dom);
                }
                else {
                    To_Rational(new_num, new_dom, new_num, new_dom);
                }
            }

            // Doha Yasser 20231089
            else if (opr == "-") {
                new_dom = dom1 * dom2;
                new_num = (num1 * dom2) - (num2 * dom1);
                if (new_dom > new_num) {
                    To_Rational(new_dom, new_num, new_num, new_dom);
                }
                else {
                    To_Rational(new_num, new_dom, new_num, new_dom);
                }
            }

            // Rahma Bahgat 20231056
            else if (opr == "/") {
                new_num = dom2 * num1;
                new_dom = dom1 * num2;
                if (new_dom > new_num) {
                    To_Rational(new_dom, new_num, new_num, new_dom);
                }
                else {
                    To_Rational(new_num, new_dom, new_num, new_dom);
                }
            }

            // Doha Yasser 20231089
            else if (opr == "*") {
                new_num = num1 * num2;
                new_dom = dom1 * dom2;
                if (new_dom > new_num) {
                    To_Rational(new_dom, new_num, new_num, new_dom);
                }
                else {
                    To_Rational(new_num, new_dom, new_num, new_dom);
                }
            }
        }
    }
    return 0;
}
