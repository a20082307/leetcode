#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<char, string> table = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"}, 
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    vector<string> letterCombinations(string digits) {
        vector<string> ans = {};

        string tem1, tem2, tem3, tem4;
        int len1, len2, len3, len4;

        int len = digits.size();
        switch (len) {
            case 0:
                return ans;

            case 1:
                tem1 = table[digits[0]];
                len1 = tem1.size();
                for (int i = 0; i < len1; i ++) 
                    ans.emplace_back(string(1, tem1[i]));

                return ans;

            case 2: 
                tem1 = table[digits[0]], tem2 = table[digits[1]];
                len1 = tem1.size(), len2 = tem2.size();
                for (int i = 0; i < len1; i ++)
                    for (int j = 0; j < len2; j ++) 
                        ans.emplace_back(string(1, tem1[i]) + string(1, tem2[j]));

                return ans;

            case 3:
                tem1 = table[digits[0]], tem2 = table[digits[1]], tem3 = table[digits[2]];
                len1 = tem1.size(), len2 = tem2.size(), len3 = tem3.size();
                for (int i = 0; i < len1; i ++)
                    for (int j = 0; j < len2; j ++)
                        for (int k = 0; k < len3; k ++)
                            ans.emplace_back(string(1, tem1[i]) + string(1, tem2[j]) + string(1, tem3[k]));

                return ans;

            case 4:
                tem1 = table[digits[0]], tem2 = table[digits[1]], tem3 = table[digits[2]], tem4 = table[digits[3]];
                len1 = tem1.size(), len2 = tem2.size(), len3 = tem3.size(), len4 = tem4.size();
                for (int i = 0; i < len1; i ++)
                    for (int j = 0; j < len2; j ++)
                        for (int k = 0; k < len3; k ++)
                            for (int l = 0; l < len4; l ++)
                                ans.emplace_back(string(1, tem1[i]) + string(1, tem2[j]) + string(1, tem3[k]) + string(1, tem4[l]));

                return ans;
        }

        return ans;
    }
};

void print(vector<string> aim) {
    int len = aim.size();
    for (int i = 0; i < len; i ++) {
        cout << aim[i] << " ";
    }
    cout << endl;
}

int main() {
    Solution s;
    string digits = "23";
    print(s.letterCombinations(digits));

    digits = "";
    print(s.letterCombinations(digits));

    digits = "2";
    print(s.letterCombinations(digits));

    digits = "234";
    print(s.letterCombinations(digits));

    digits = "2345";
    print(s.letterCombinations(digits));
}