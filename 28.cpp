#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int ans = haystack.find(needle);
        return ans == string::npos ? -1 : ans;
    }
};

int main() {
    Solution s;
    string haystack, needle;

    haystack = "sadbutsad", needle = "sad";
    cout << s.strStr(haystack, needle) << endl;

    haystack = "leetcode", needle = "leeto";
    cout << s.strStr(haystack, needle) << endl;
}