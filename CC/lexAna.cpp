#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    
    cout << "Enter any operator: ";
    cin >> s; 
    
    if (s.length() == 1) { 
        switch (s[0]) {
            case '>':
                cout << "Greater than" << endl;
                break;
            case '<':
                cout << "Less than" << endl;
                break;
            case '=':
                cout << "Assignment" << endl;
                break;
            case '+':
                cout << "Addition" << endl;
                break;
            case '-':
                cout << "Subtraction" << endl;
                break;
            case '*':
                cout << "Multiplication" << endl;
                break;
            case '/':
                cout << "Division" << endl;
                break;
            case '%':
                cout << "Modulus" << endl;
                break;
            default:
                cout << "Not an operator" << endl;
                break;
        }
    }
    else if (s.length() == 2) { 
        if (s[0] == '>' && s[1] == '=') {
            cout << "Greater than or equal" << endl;
        }
        else if (s[0] == '<' && s[1] == '=') {
            cout << "Less than or equal" << endl;
        }
        else if (s[0] == '=' && s[1] == '=') {
            cout << "Equal to" << endl;
        }
        else if (s[0] == '!' && s[1] == '=') {
            cout << "Not Equal" << endl;
        }
        else if (s[0] == '&' && s[1] == '&') {
            cout << "Logical AND" << endl;
        }
        else if (s[0] == '|' && s[1] == '|') {
            cout << "Logical OR" << endl;
        }
        else {
            cout << "Not a valid operator" << endl;
        }
    }
    else {
        cout << "Not a valid operator" << endl;
    }

    return 0;
}
