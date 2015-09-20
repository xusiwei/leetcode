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
#include <stdlib.h>
#include <ctype.h>

bool isNumber(const char* s) {
    const char* start;
    bool number = false; // for last scaned.
    int ns = 0, ne = 0, np = 0; // number of 'e', sign, point.
    while(isspace(*s)) s++; // trim prefix spaces.
    
    // sign check.
    for( ; *s == '-' || *s == '+'; s++) ++ns;
    if(ns > 1) return false;
    
    ns = 0;
    start = s;
    for( ; *s; s++) {
        if(isspace(*s)) { // for space
            for( ; *s; s++) {
                if(!isspace(*s)) return false;
            }
            return true;
        }
        else if(*s == '.') { // for point
            if(++np > 1 || ne > 0) return false;
            if(!isdigit(*(s+1)) && !number) return false;
            number = false;
        }
        else if(*s == 'e' || *s == 'E') { // for 'e'
            if(++ne > 1 || s == start) return false;
            s++; // skip 'e'
            if(*s == '+' || *s == '-') s++;
            if(!isdigit(*s)) return false;
            number = false;
        }
        else if(!isdigit(*s)) return false;
        number = true;
    }
    return number;
}

#define ASSERT(expr) if(expr) {      \
        printf("PASS: %s\n", #expr); \
    } else {                         \
        printf("FAIL: %s at %s:%d\n",\
         #expr, __FILE__, __LINE__); \
        exit(1);                     \
    }

int main(int argc, char* argv[])
{
    ASSERT(isNumber("0") == true);
    ASSERT(isNumber(" 0") == true);
    ASSERT(isNumber("  0") == true);
    ASSERT(isNumber("0 ") == true);
    ASSERT(isNumber(" 0 ") == true);
    ASSERT(isNumber(" 0 a") == false);
    ASSERT(isNumber("0.1") == true);
    ASSERT(isNumber(" 0.1") == true);
    ASSERT(isNumber("0.1 ") == true);
    ASSERT(isNumber(" 0.1 ") == true);
    ASSERT(isNumber(" 0.1 a") == false);
    ASSERT(isNumber("123.") == true);
    ASSERT(isNumber(" 123.") == true);
    ASSERT(isNumber(" 123. ") == true);
    ASSERT(isNumber(" 123. a") == false);
    ASSERT(isNumber(".1234") == true);
    ASSERT(isNumber(" .1234") == true);
    ASSERT(isNumber(" .1234 ") == true);
    ASSERT(isNumber(".1234 ") == true);
    ASSERT(isNumber(".1234 a") == false);
    ASSERT(isNumber("abc") == false);
    ASSERT(isNumber(" abc") == false);
    ASSERT(isNumber("abc ") == false);
    ASSERT(isNumber(" abc ") == false);
    ASSERT(isNumber("1 a") == false);
    ASSERT(isNumber("2e10") == true);
    ASSERT(isNumber(" 2e10") == true);
    ASSERT(isNumber(" 2e10 ") == true);
    ASSERT(isNumber("2e10 ") == true);
    ASSERT(isNumber("2e10 e") == false);
    ASSERT(isNumber(" 2E10 ") == true);
    ASSERT(isNumber("2E10.") == false);
    ASSERT(isNumber("2E1.0") == false);
    ASSERT(isNumber("3.0E8") == true);
    ASSERT(isNumber("3.E8") == true);
    ASSERT(isNumber(".3E9") == true);
    ASSERT(isNumber(".3E-9") == true);
    ASSERT(isNumber(".3E+9") == true);
    ASSERT(isNumber(".3E+9.") == false);
    ASSERT(isNumber("e") == false);
    ASSERT(isNumber("1e") == false);
    ASSERT(isNumber("e2") == false);
    ASSERT(isNumber("1e2") == true);
    ASSERT(isNumber(".") == false);
    ASSERT(isNumber(".1") == true);
    ASSERT(isNumber("2.") == true);
    ASSERT(isNumber("2.1") == true);
    ASSERT(isNumber("   ") == false);
    ASSERT(isNumber(" 1..2") == false);
    ASSERT(isNumber(" 1ee2") == false);
    ASSERT(isNumber(" 1e++2") == false);
    ASSERT(isNumber(" ++1e2") == false);
    ASSERT(isNumber(" 1..e2") == false);
    ASSERT(isNumber(" 1e..2") == false);

    return 0;
}

