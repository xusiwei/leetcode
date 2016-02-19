#include <ctype.h>
#include <limits.h>
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;

string randrome(int len) {
    string s = "\"";
    for (int i = 0; i < len; i++) {
        char c = 0;
        while (!isalnum(c)) {
            c = rand() % (CHAR_MAX);
        }
        s += c;
    }
    for (int i = s.length()-1; i >= 0; i--) {
        s += s[i];
    }
    return s;
}

int main(int argc, char* argv[])
{
    int len = 16;
    
    if (argc > 1) {
        len = atoi(argv[1]);
    }
    
    cout << randrome(len);
    return 0;
}
