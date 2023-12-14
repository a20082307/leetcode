#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1 || strs[0] == "") 
            return strs[0];

        int common_prefix_len = 0, min_len = min(strs[0].size(), strs[1].size());
        while (common_prefix_len < min_len) {
            if (strs[0][common_prefix_len] == strs[1][common_prefix_len])
                common_prefix_len ++;
            else   
                break;
        }

        if (common_prefix_len == 0)
            return "";

        int len = strs.size();
        for (int i = 2; i < len; i ++) {
            for (int j = 0; j < common_prefix_len; j ++) {
                if (strs[i][j] != strs[0][j]) {
                    common_prefix_len = j;
                    break;
                }
            }
        }

        return strs[0].substr(0, common_prefix_len);
    }
};
// class TrieNode {
// public:
//     bool isWord;
//     TrieNode* children[26];

//     TrieNode(): isWord(false) {
//         memset(children, NULL, sizeof(children));
//     }
// };
// class Trie {
// public: 
//     TrieNode* root;
//     Trie(): root(new TrieNode()) {}
// };

int main() {
    Solution solution;

    vector<string> strs = {"flower", "flow", "flight"};
    cout << solution.longestCommonPrefix(strs) << endl;

    strs = {"dog", "racecar", "car"};
    cout << solution.longestCommonPrefix(strs) << endl;
}