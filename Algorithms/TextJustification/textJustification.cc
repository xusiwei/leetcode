/*
copyright xu(xusiwei1236@163.com), all right reserved.

Text Justification
===================

Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:

[
   "This    is    an",
   "example  of text",
   "justification.  "
]

Note: Each word is guaranteed not to exceed L in length.

click to show corner cases.
Corner Cases:

    A line other than the last line might contain only one word. What should you do in this case?
    In this case, that line should be left-justified.
*/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int left = 0;
        
        while(left < words.size()) {
            string line = words[left]; // to store justified line;
            int total = line.length(); // total length of words in `line`.
            int count = 1; // count of words in `line`.
            
            // attempt to put some words to line.
            for(int i = left+1; i < words.size(); i++) {
            	// at least one space between each word.
                if(total + count + words[i].length() > maxWidth) break;
                total += words[i].length();
                count++;
            }
            
            int spaces = maxWidth - total; // extra spaces.
            if(count > 1) { // mix in spaces.
                if(left + count < words.size()) { // not last line.
                    int dummys = spaces % (count-1); // dummys
                    int padding = spaces / (count-1);
                    for(int i = 1; i < count; i++) {
                        line += string(i <= dummys ? padding+1 : padding, ' ');
                        line += words[left+i];
                    }
                }
                else { // For the last line of text,
                    // it should be left justified and no extra space is inserted between words. 
                    for(int i = 1; i < count; i++) {
                        line += string(1, ' ');
                        line += words[left+i];
                        spaces--;
                    }
                    if(spaces > 0) line += string(spaces, ' ');
                }
            }
            else { // only one word, append spaces.
                line += string(spaces, ' ');
            }
            result.push_back(line);
            
            left += count;
        }
        return result;
    }
};

int main(int argc, char* argv[])
{
	// ["What","must","be","shall","be."], 12
	// ["Imagination","is","more","important","than","knowledge."], 14
	// ["This", "is", "an", "example", "of", "text", "justification."], 16
	vector<string> words{"Imagination","is","more","important","than","knowledge."};
	int len = 14;
	
	if(argc > 1) len = atoi(argv[1]);
	if(argc > 2) {
		words.clear();
		for(int i = 2; i < argc; i++) {
			words.push_back(argv[i]);
		}
	}
	
	auto just = Solution().fullJustify(words, len);
	for_each(just.begin(), just.end(),
		[](string& s) {
			cout << "\"" << s << "\"" << endl;
		});
    return 0;
}
