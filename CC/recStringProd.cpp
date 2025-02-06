#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int main() {
    char s[20], c;
    int state = 0, i = 0;

    cout << "\nEnter a string: ";
    cin >> s;

    while (s[i] != '\0') {
        switch (state) {
            case 0:
                c = s[i++];
                if (c == 'a') state = 1;
                else if (c == 'b') state = 2;
                else {
                    state = 6;
                    break;
                }
                break;
            case 1:
                c = s[i++];
                if (c == 'a') state = 3;
                else if (c == 'b') state = 4;
                else {
                    state = 6;
                    break;
                }
                break;
            case 2:
                c = s[i++];
                if (c == 'a') state = 6;
                else if (c == 'b') state = 2;
                else {
                    state = 6;
                    break;
                }
                break;
            case 3:
                c = s[i++];
                if (c == 'a') state = 3;
                else if (c == 'b') state = 2;
                else {
                    state = 6;
                    break;
                }
                break;
            case 4:
                c = s[i++];
                if (c == 'a') state = 6;
                else if (c == 'b') state = 5;
                else {
                    state = 6;
                    break;
                }
                break;
            case 5:
                c = s[i++];
                if (c == 'a') state = 6;
                else if (c == 'b') state = 2;
                else {
                    state = 6;
                    break;
                }
                break;
            case 6:
                cout << "\n" << s << " is not recognised." << endl;
                exit(0);
                break;
        }
    }

    if (state == 1) {
        cout << "\n" << s << " is accepted under rule 'a'" << endl;
    } else if (state == 2 || state == 4) {
        cout << "\n" << s << " is accepted under rule 'a*b+'" << endl;
    } else if (state == 5) {
        cout << "\n" << s << " is accepted under rule 'abb'" << endl;
    }

    return 0;
}
