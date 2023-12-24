#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string word = "";
        vector<string> words;
        
        int len = s.length();
        for (int i = 0; i < len; i ++) {
            if (s[i] == ' ') {
                if (word != "") {
                    words.emplace_back(word);
                    word = "";
                }
            }
            else
                word += s[i];
        }

        if (word != "")
            words.emplace_back(word);

        int size = words.size();
        for (int i = size - 1; i >= 0; i --) {
            ans += words[i];
            if (!i)
                return ans;
            
            ans += " ";
        }

        return NULL;
    }
};

int main() {
    Solution sol;
    string s = "";  
    getline(cin, s);
    cout << sol.reverseWords(s) << endl;
}