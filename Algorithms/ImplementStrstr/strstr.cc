#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;

// brute force,
// time complexity: O( (m-n) * n )
int strStrBF(char* text, char* pat) {
    if(text == NULL || pat == NULL) return 0;
    if(pat[0] == '\0') return 0;
    
    for(int m = 0; text[m]; ++m) {
        for(int i = 0; text[m+i] && pat[i]; ++i) {
            if(text[m+i] != pat[i]) break;
            if(pat[i+1] == '\0') return i;
        }
    }
    return -1;
}

// refers: https://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm
int strStrKMP(char* text, char* pat) {
	int txtlen = strlen(text);
	int patlen = strlen(pat);
	if(txtlen == 0 && patlen == 0) return 0;
	if(txtlen < patlen) return -1;
	
	int* next = (int*)calloc(sizeof(int), patlen);
	next[0] = -1;
	next[1] = 0;
	
	// workout "Partial match" table
	int pos = 2, cnd = 0;
	while(pos < patlen) {
		if(pat[pos-1] == pat[cnd]) {
			cnd++;
			next[pos] = cnd;
			pos++;
		}
		else if(cnd > 0) {
			cnd = next[cnd];
		}
		else {
			cnd = 0;
			pos++;
		}
	}
	
	// searching...
	int m = 0, i = 0;
	while(m + i < txtlen) {
		if(pat[i] == text[m+i]) {
			if(i == patlen-1) goto finish; //return m;
			i++;
		}
		else {
			if(next[i] > -1) {
				m += (i - next[i]);
				i = next[i];
			}
			else {
				i = 0;
				m++;
			}
		}
	}
	m = -1;
finish:
	free(next);
	return m;
}

int strStr(char* text, char* pat) {
#ifdef BF
	return strStrBF(text, pat);
#elif(defined STD)
	char* m = strstr(text, pat);
	return m ? m-text : -1;
#else
	return strStrKMP(text, pat);
#endif
}

int main()
{
	string text, pat;
	
	cin >> text >> pat;
	cout << "len(text): " << text.length() << endl;
	cout << "len(pat) : " << pat.length()  << endl;
	cout << strStr(const_cast<char*>(text.c_str()), const_cast<char*>(pat.c_str())) << endl;
	return 0;
}
