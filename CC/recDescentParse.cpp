#include <iostream>
#include <string>
using namespace std;

int c = 0;
string p;

void s();
void l();
void lprime();
void s()
{
    c++;
    l();
    lprime();
    if (p[c] == 'a')
        c++;
    else if (p[c] == '(')
    {
        c++;
        l();
        if (p[c] == ')')
            c++;
        else
            c--;
    }
    else
    {
        cout << "\nInvalid Expression";
        exit(0);
    }
}

void l()
{
    s();
    lprime();
}

void lprime()
{
    if (p[c] == ',')
    {
        c++;
        s();
        lprime();
    }
}

int main()
{
    cout << "\nImplementation of RECURSIVE DESCENT PARSER\n";
    cout << "\nEnter the Expression:\n";
    cin >> p;
    s();
    if (p[c] == '$')
        cout << "\nThe String is accepted";
    else
        cout << "\nThe string is rejected";
    return 0;
}
