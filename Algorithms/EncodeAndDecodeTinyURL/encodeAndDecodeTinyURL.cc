/*
copyright xu(xusiwei1236@163.com), all right reserved.

Encode and Decode TinyURL
==========================

Note: This is a companion problem to the System Design problem: Design TinyURL.

TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk.

Design the encode and decode methods for the TinyURL service. There is no restriction on how your encode/decode algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.
*/

#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

static constexpr char CHARS[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
static constexpr int NCHARS = sizeof(CHARS) - 1;

class Solution
{
    unordered_map<string, string> tolong;
    unordered_map<string, string> toshort;

public:
    // The identifier (the highlighted part) can be any string with 6 alphanumeric characters containing 0-9, a-z, A-Z.
    string randid()
    {
        string id;
        for (int i = 0; i < 6; i++) {
            id += CHARS[rand() % NCHARS];
        }
        return id;
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl)
    {
        string shortUrl = randid();
        while (tolong.find(shortUrl) != tolong.end()) { // used
            shortUrl = randid();
        }
        tolong[shortUrl] = longUrl;
        toshort[longUrl] = shortUrl;
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl)
    {
        if (tolong.find(shortUrl) != tolong.end()) {
            return tolong[shortUrl];
        }
        return "";
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

int main(int argc, char* argv[])
{
    Solution solution;
    string longUrl = "https://leetcode.com/problems/design-tinyurl";

    string shortUrl = solution.encode(longUrl);
    cout << "encoded: " << shortUrl << endl;

    longUrl = solution.decode(shortUrl);
    cout << "decoded: " << longUrl << endl;

    return 0;
}
