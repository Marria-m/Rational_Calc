#include <iostream>
#include <string>
#include <cctype>
using namespace std;


// Affine cipher by Mariam Ehab 20231160
void check_valid_Affine_Cipher(string user_text, bool& is_valid) {
    is_valid = true;
    for (int i = 0; i < user_text.length(); i++) {
        if (!isalpha(user_text[i]) && !isspace(user_text[i])) {
            cout << "Invalid statement. Please enter another statement (contains only a to z)" << endl;
            is_valid = false;
            break;
        }
    }
}


void valid_number_Affine_Cipher(string number, bool& is_valid) {
    is_valid = true;
    for (int i = 0; i < number.length(); i++) {
        if (!isdigit(number[i])) {
            cout << "Please enter a valid number" << endl;
            is_valid = false;
            break;
        }
    }
}


void encrypt_Affine_Cipher(string statement, int factor, int sub_add) {
    string cipher_txt;
    // iterate through each character in the plaintext
    for (int i = 0; i < statement.length(); i++) {
        // if the character is an alphabet
        if (isalpha(statement[i])) {
            // get the index of the character in the alphabet
            int ind = (int) toupper(statement[i]) - 65;

            // perform the encryption operation
            int enc = ((factor * ind) + sub_add) % 26;

            // append the encrypted character to the ciphertext
            cipher_txt += char(enc + 65);

        }
            // if the character is not an alphabet
        else {
            // append the character to the ciphertext as it is
            cipher_txt += statement[i];
        }
    }

    // print the ciphertext
    cout << cipher_txt << endl;
}


void decrypt_Affine_Cipher(string statement, int sub_add, int coefficient) {
    string decipher_txt;
    // iterate through each character in the ciphertext
    for (int i = 0; i < statement.length(); i++) {
        // if the character is an alphabet
        if (isalpha(statement[i])) {
            // get the index of the character in the alphabet
            int ind = (int) toupper(statement[i]) - 65;

            // perform the decryption operation
            int dec = (ind - sub_add) * coefficient % 26;

            // if the decrypted index is negative
            if (dec < 0){
                // convert it to positive and subtract 26 from it
                dec = (abs(dec) % 26) - 26;

                // append the deciphered character
                decipher_txt += char(abs(dec) + 65);
            }
            // if decrypted index is greater than or equal 0
            else {
                dec %= 26;

                // append the deciphered character
                decipher_txt += char(dec + 65);
            }


        }
            // if the character is not an alphabet
        else {
            decipher_txt += statement[i];
        }
    }

    // print the decipher text
    cout << decipher_txt << endl;
}


// Polybius Square by Rahma Bahgat 20231056
string encrypt_Polybius_Square(const string &plaintext) {
    // the Polybius square
    char polybius_square[5][5] = {{'a', 'b', 'c', 'd', 'e'},
                                  {'f', 'g', 'h', 'i', 'k'},
                                  {'l', 'm', 'n', 'o', 'p'},
                                  {'q', 'r', 's', 't', 'u'},
                                  {'v', 'w', 'x', 'y', 'z'}};

    string ciphertext;
    for (char c : plaintext) {
        if (isalpha(c)) {
            char letter = tolower(c);
            if (letter == 'j') letter = 'i'; // Replace 'j' with 'i'
            bool found = false;
            for (int i = 0; i < 5; ++i) {
                for (int j = 0; j < 5; ++j) {
                    if (polybius_square[i][j] == letter) {
                        ciphertext += to_string(i + 1) + to_string(j + 1) ;
                        found = true;
                        break;
                    }
                }
                if (found) break;
            }
        } else if (c != ' ') {
            cout << "Invalid input. Please enter alphabetic characters and spaces only." << endl;
            return "";
        } else {
            ciphertext += " "; // Append space directly
        }
    }
    return ciphertext;
}


string decrypt_Polybius_Square(const string &ciphertext) {
    // the Polybius square
    char polybius_square[5][5] = {{'a', 'b', 'c', 'd', 'e'},
                                  {'f', 'g', 'h', 'i', 'k'},
                                  {'l', 'm', 'n', 'o', 'p'},
                                  {'q', 'r', 's', 't', 'u'},
                                  {'v', 'w', 'x', 'y', 'z'}};

    string plaintext;
    for (int i = 0; i < ciphertext.length(); i += 2) {
        if (ciphertext[i] == ' ') {
            // Append space directly
            plaintext += " ";
            i--;  // Decrement the index to account for the space
            continue;  // Skip processing if encountering a space
        }
        int row = ciphertext[i] - '0' - 1;
        int column = ciphertext[i + 1] - '0' - 1;

        if (row < 0 || row >= 5 || column < 0 || column >= 5) {
            // If the row or column is invalid, return an empty string
            return "";
        }

        plaintext += polybius_square[row][column];
    }
    return plaintext;
}


// Rail fence by Doha Yasser 20231089
void check_len_Rail_fence(string row_1 ,string row_2 , string row_3){
    int repeat ;
    cout << "\nYour statement is '" << row_1 << row_2 << row_3  << "'" ; // print statement after ciphering
    cout << "\nPress '1' to start again (another thing will exit):"; // another thing will exit
    char again ;
    cin >> again ;
    if (again == '1') {// start again
        repeat = 1 ;
    }
    else{ // exit a program
        cout << "Thanks for using my program " ;
        repeat = 0 ;
        exit(0) ;
    }
}


void cipher_Rail_fence(){
    string row_1 , row_2, row_3,statement ;//declare variables
    cout << "\nPlease enter your statement :" ; // get message to ciphering
    cin.ignore() ; // to ignore the last input
    getline (cin , statement) ;
    int len = statement.length() ; // length of  the message
    int n = 0 ;
    while (true) {
        if (len == 0){
            check_len_Rail_fence(row_1 , row_2, row_3) ;
            break ;
        }
        else{
            row_1 += statement[n]; // add the selected character to the first row
            len -- ;
            if (len == 0) {// check if the statment finishes
                check_len_Rail_fence(row_1 , row_2, row_3) ;
                break ;
            }
            else {
                row_2 += statement[n+1] ; // add the character to the second row
                len -- ;
                if (len == 0) {
                    check_len_Rail_fence(row_1 , row_2, row_3) ;
                    break ;
                }
                else {
                    row_3 += statement[n+2] ;//add the character to the third row
                    len -- ;
                    if (len == 0) {// check if statment finishes
                        check_len_Rail_fence(row_1 , row_2, row_3) ;
                        break ;
                    }
                    else {
                        row_2 += statement[n+3] ; //add the character to the second row
                        len -- ;
                        if (len == 0){
                            check_len_Rail_fence(row_1 , row_2, row_3) ;
                            break ;
                        }
                    }
                }
            }
            n += 4 ;
        }
    }
}


void decipher_Rail_fence()
{
    int repeat = 0 ;
    string row_x ,row_y ,row_z ,stat ,final;
    cout << "Enter your statement for decypher : " ; // insert a message to decipher
    cin.ignore() ; // ignore the last input
    getline (cin , stat) ;
    int len = stat.length()  ;
    int index ;
    index = len - 1 ;// as computer starts with index 0
    for (int i=0 ; i < int(index/3) ;i++) {//  as 3 rows
        row_x += stat[i] ; //  add the selected chracter to the first row
        row_x += "   "; //add spaces
    }
    for (int j = int(index/3) ; j <= 2*(index/3)+1 ;j++){// from the next index {3,5,3}...{4,6,4}
        row_y += " "; // add spaces
        row_y += stat[j] ; //add the selected chracter to the second row
    }
    row_z += "  ";
    for (int k = 2*(index/3)+2 ; k < index ;k++){
        row_z += stat[k] ; // add the selected chracter to the third row
        row_z += "   "; // ...
    }
    int m = 0 ;
    int n = 1 ;
    int p = 2 ;
    while (m < row_x.length() || n < row_y.length() || p < row_z.length() ){
        if (m < row_x.length()) {
            final += row_x[m];// add the selected character to the string
            m += 4;
        }
        if (n < row_y.length()) {
            final += row_y[n];
            n += 2;
        }
        if (p < row_z.length()) {
            final +=row_z[p];
            p += 4;
        }
    }
    for (char ch : final){
        if(ch != ' '){// if not space .... print character
            cout << ch ;
        }
    }
    cout << "\nPress '1' to start again (another thing will exit) :";
    char again ;
    cin >> again ;
    if (again == '1'){// start again
        repeat = 1 ;
    }
    else {// end
        cout << "Thanks for using my program " ;
        exit(0) ;
    }
}


int main() {

    // variables to store the values of factor, sub_add, and coefficient for Affine cipher
    string x, y, z;
    int factor, sub_add, coefficient;

    // variable to store the plaintext and ciphertext for Affine cipher
    string statement;

    string plaintext, ciphertext;

    // infinite loop to perform encryption or decryption until the user chooses to exit
    while (true) {
        string choice, choose;
        cout << "1) encryption" << endl << "2) decryption" << endl << "3) Exit" << endl;
        cin >> choice;

        // if the user chooses to encrypt the plaintext
        if (choice == "1") {
            // let the user choose any cipher they want to use
            cout << "1) Affine Cipher" << endl << "2) Polybius Square" << endl << "3) Rail-fence Cipher" << endl << "4) Exit" << endl;
            cin >> choose;

            if (choose == "1"){
                // welcome message
                cout << "welcome to Affine Cipher\n" << endl;

                // Ignore the newline character in the input buffer
                cin.ignore();
                // get the plaintext from the user
                cout << "enter your statement \n";
                getline(cin, statement);

                // check valid statement
                bool is_valid_statement = true;
                check_valid_Affine_Cipher(statement, is_valid_statement);
                if (!is_valid_statement) {
                    continue;
                }

                // get the values of factor, sub_add, and coefficient from the user
                cout << "(factor * coefficient) reminder of 26 should be equal to 1 \n";
                cout << "Enter the value of factor: \n";
                cin >> x;
                valid_number_Affine_Cipher(x, is_valid_statement);
                if (!is_valid_statement) {
                    continue;
                }
                else {
                    factor = stoi(x);
                }
                cout << "Enter the value of sub_add: \n";
                cin >> y;
                valid_number_Affine_Cipher(y, is_valid_statement);
                if (!is_valid_statement) {
                    continue;
                }
                else {
                    sub_add = stoi(y);
                }
                cout << "Enter the value of coefficient: \n";
                cin >> z;
                valid_number_Affine_Cipher(z, is_valid_statement);
                if (!is_valid_statement) {
                    continue;
                }
                else {
                    coefficient = stoi(z);
                }

                if ((factor * coefficient) % 26 != 1){
                    cout << "invalid, please enter a valid number for factor and coefficient \n";
                    continue;
                }

                encrypt_Affine_Cipher(statement, factor, sub_add);
            }

            else if (choose == "2") {
                // Ignore the newline character in the input buffer
                cin.ignore();

                // welcome message
                cout << "welcome to Polybius Square cipher\n";
                // Fixed key
                cout << "The key is fixed '12345'\n";

                cout << "Enter the plaintext: ";
                getline(cin, plaintext);
                ciphertext = encrypt_Polybius_Square(plaintext);
                if (!ciphertext.empty()) {
                    cout << "Cipher text: " << ciphertext << endl;
                }
            }
            else if (choose == "3"){
                cout << "\n===============\n";
                cout << "Note :- the key value is 3\n"; // 3 rows
                cipher_Rail_fence();
            }
            else if (choose == "4"){
                continue;
            }
            else {
                cout << "please enter a valid choice\n";
            }

        } else if (choice == "2") {
            // let the user choose any cipher they want to use
            cout << "1) Affine Cipher" << endl << "2) Polybius Square" << endl << "3) Rail-fence Cipher" << endl << "4) Exit" << endl;
            cin >> choose;

            if (choose == "1"){
                // welcome message
                cout << "welcome to Affine Cipher\n" << endl;

                // ignore the newline character in the input buffer
                cin.ignore();

                // get the ciphertext from the user
                cout << "enter your statement \n";
                getline(cin, statement);

                // check valid statement
                bool is_valid_statement = true;
                check_valid_Affine_Cipher(statement, is_valid_statement);
                if (!is_valid_statement) {
                    continue;
                }

                // get the values of factor, sub_add, and coefficient from the user
                cout << "(factor * coefficient) reminder of 26 should be equal to 1 \n";
                cout << "Enter the value of factor: \n";
                cin >> x;
                valid_number_Affine_Cipher(x, is_valid_statement);
                if (!is_valid_statement) {
                    continue;
                }
                else {
                    factor = stoi(x);
                }
                cout << "Enter the value of sub_add: \n";
                cin >> y;
                valid_number_Affine_Cipher(y, is_valid_statement);
                if (!is_valid_statement) {
                    continue;
                }
                else {
                    sub_add = stoi(y);
                }
                cout << "Enter the value of coefficient: \n";
                cin >> z;
                valid_number_Affine_Cipher(z, is_valid_statement);
                if (!is_valid_statement) {
                    continue;
                }
                else {
                    coefficient = stoi(z);
                }

                if ((factor * coefficient) % 26 != 1){
                    cout << "invalid, please enter a valid number for factor and coefficient \n";
                    continue;
                }
                decrypt_Affine_Cipher(statement, sub_add, coefficient);
            }
            else if (choose == "2"){
                // ignore the newline character in the input buffer
                cin.ignore();

                // welcome message
                cout << "welcome to Polybius Square cipher\n";
                // Fixed key
                cout << "The key is fixed '12345'\n";

                cout << "Enter the ciphertext: ";
                getline(cin, ciphertext);
                plaintext = decrypt_Polybius_Square(ciphertext);
                if (!plaintext.empty()) {
                    cout << "Plain text: " << plaintext << endl;
                }
            }
            else if (choose == "3"){
                cout << "\n===============\n";
                cout << "Note :- the key value is 3\n"; // 3 rows
                decipher_Rail_fence();
            }
            else if (choose == "4"){
                continue;
            }
            else {
                cout << "please enter a valid choice\n";
            }
        }
            // if the user choose to exit the program
        else if (choice == "3") {
            cout << "exiting...";
            // stop the program
            break;
        }
            // if the user entered an invalid choice
        else {
            // print an error message
            cout << "enter a valid choice \n";
        }
    }

    return 0;
}
