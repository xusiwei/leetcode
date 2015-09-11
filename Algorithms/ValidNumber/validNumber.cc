/*
copyright xu(xusiwei1236@163.com), all right reserved.

Valid Number
=============

Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.
*/
#include <stdio.h>
#include <ctype.h>

bool isNumber(char* s) {
    int prev = 0, base = 10, sign = 0, sci = 0, pt = 0;
    while(isspace(*s)) s++;
    
    // sign check.
    for( ; *s == '-' || *s == '+'; s++) if(++sign > 1) return false;
    
    if(*s == '0') {
        if(tolower(*(s+1)) == 'x') {
            base = 16;
            s += 2;
        }
        else {
            base = 8;
            s++;
        }
    }
    else if(*s == '.') {
        base = 10;
        pt = 1;
        s++;
    }
    
    // printf("base: %d\n", base);
    for( ; *s; s++) {
        if(prev && base == 10 && tolower(*s) == 'e')  {
            if(++sci > 1) return false;
        } else if(isxdigit(*s)) {
            int d = isdigit(*s) ? *s - '0' : (isxdigit(*s) ? tolower(*s) - 'a' + 10 : -1);
            if(!(0 <= d && d < base)) return false;
            prev = 1;
        } else if(*s == '.') {
            if(++pt > 1) return false;
        }
    }
    return true;
}

int main(int argc, char* argv[])
{
    int i;
    char* ss[] = {"0", " 0.1", "abc", "1 a", "2e10"};
    for(i = 0; i < sizeof(ss)/sizeof(ss[0]); i++) {
        printf("%s -> %s\n", ss[i], isNumber(ss[i]) ? "true" : "false");
    }
    for(i = 1; i < argc; i++) {
        printf("%s -> %s\n", argv[i], isNumber(argv[i]) ? "true" : "false");
    }
    return 0;
}
