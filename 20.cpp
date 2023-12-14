#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int len = s.length();
        if (len % 2)
            return false;

        stack<string> opens;
        string match1 = "()", match2 = "[]", match3 = "{}";

        int cur = 0;
        while(cur != len) {
            if (s[cur] == '(' || s[cur] == '[' || s[cur] == '{') {
                opens.emplace(string(1, s[cur ++]));
                continue;
            }

            if (opens.empty())
                return false;

            string top = opens.top(), cur_str = string(1, s[cur]);
            string tem = top + cur_str;
            if (tem == match1 || tem == match2 || tem == match3) {
                opens.pop();
                cur ++;
            }
            else 
                return false;
        }

        return opens.empty();
    }
};

int main() {
    Solution s;

    string str = "()";
    // cout << s.isValid(str) << endl;

    str = "()[]{}";
    cout << s.isValid(str) << endl;

    str = "(]";
    cout << s.isValid(str) << endl;

    str = "{[]}";
    cout << s.isValid(str) << endl;

    str = "([]){}";
    cout << s.isValid(str) << endl;

    str = "([()]{}){[]}";
    cout << s.isValid(str) << endl;
}