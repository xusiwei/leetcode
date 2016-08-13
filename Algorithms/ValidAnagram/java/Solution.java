/*
copyright xu(xusiwei1236@163.com), all right reserved.

Valid Anagram
==============

Given two strings s and t, write a function to determine if t is an anagram of s. 

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.


Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
*/
import java.util.Arrays;

public class Solution {
    int[] countChars(String s) {
        int[] result = new int[256];
        for (int i = 0; i < s.length(); i++) {
            result[s.charAt(i)]++;
        }

        return result;
    }

    public boolean isAnagram(String s, String t) {
        return Arrays.equals(countChars(s), countChars(t));
    }
}


