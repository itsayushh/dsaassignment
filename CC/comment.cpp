#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void checkComment(const string &com) {
    if (com.substr(0, 2) == "//") {
        cout << "It is a single-line comment." << endl;
        return;
    }
    if (com.substr(0, 2) == "/*" && com.substr(com.size() - 2) == "*/") {
        cout << "It is a multi-line comment." << endl;
        return;
    }
    cout << "It is not a comment." << endl;
}

int main() {
    string comment;
    cout << "Enter comment: ";
    getline(cin, comment);
    
    checkComment(comment);

    return 0;
}
