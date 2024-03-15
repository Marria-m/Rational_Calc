# team
### rationel calc
#### encryption and decryption assignment (bonus)
#include<iostream>
#include<iomanip>//setprecision
#include <sstream>//ostrinstream
using namespace std ;
double fraction(double n)
{
    // Declare oss as std::ostringstream
    ostringstream oss;
    
    // Write the formatted number to the stringstream
    oss << fixed << setprecision(2) << n;

    // Get the formatted string from the stringstream and convert it to double
    double d = stod(oss.str());

    // Multiply the formatted double by 100
    double value = d * 100;

    // Print the multiplied value
    //cout <<"the result is " << value << "/" << "100" << endl;
    int s = min(int(value), 100);
    while(s > 0)
    {
        if(int(value) % s == 0 && 100%s == 0)
        {
         cout << "\n========\nresult\n========\n " <<endl << value/s << "\nــــ\n"<< 100/s <<endl;
         return 0 ;
        }
        s-- ; 
    }
    cout <<"the result : " << value << "/" << "100" << endl;

    return 0;
}
int main()
{
    cout << "Enter the first number : " ;
    double num1 , num2 , n;
    cin >> num1 ;
    cout << "Enter the second number : " ;
    cin >> num2 ;
    cout <<"Insert an operation (+,-,*,/): " ;
    char oper ;
    cin >> oper ;
    while(oper != '+' && oper != '-' && oper != '*' && oper != '/' )
    {
        cout << "Please insert a valid operation : " ;
        cin >> oper ;
    }
    switch(oper)
    {
        case '+' :
            n = num1 + num2 ;
            fraction(n) ;
            break;
        
        case '-' :
            n = num1 - num2 ;
            fraction(n) ;
            break;
        
        case '*':
            n = num1 * num2 ;
            fraction(n) ;
            break;
        
        case '/':
            n = num1 / num2 ;
            fraction(n) ;
            break;

    }
}
