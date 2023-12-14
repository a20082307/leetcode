#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";

        int len1 = word1.length(), len2 = word2.length();
        int len = min(len1, len2);
        for (int i = 0; i < len; i ++) {
            ans += word1[i];
            ans += word2[i];
        }

        if (len1 > len2)
            for (int i = len; i < len1; i ++)
                ans += word1[i];
        else if (len1 < len2)
            for (int i = len; i < len2; i ++)
                ans += word2[i];

        return ans;
    }
};



int main() {
    Solution s;

    string word1, word2;
    cin >> word1 >> word2;
    cout << s.mergeAlternately(word1, word2) << endl;
}