#include <iostream>
#include <string>
using namespace std;

void valid(string number, string string1,string string2){
    int len = number.length();
    for (int i = 0; i < len; i++){
        if (number[i] == '/'){
            if (len % 2 != 0) {
                for (int j = len - i; j < len; j++) {
                    string2 += number[j];
                }
                break;
            }
            else {
                for (int j = len - i; j < len; j++) {
                    string2 += number[j + 1];
                }
                break;
            }
        }
        else {
            string1 += number[i];
        }
    }
    cout << string1 << "\n " << string2 << "\n";
}

int main() {

    
   string num1, num2, str1_1, str2_1, str1_2, str2_2;
    cout << "Enter the first number: ";
    getline(cin, num1);
    valid(num1, str1_1, str2_1);

    cout << "Enter the second number: ";
    getline(cin, num2);
    valid(num2, str1_2, str2_2);
     return 0;
}
