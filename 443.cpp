#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
    }

    int compress(vector<char>& chars) {
        vector<char> ans;

        int times = 0;
        char cur = chars[0];
        for (auto c = chars.begin() + 1; c != chars.end(); c ++) {
            if (*c != cur) {
                ans.push_back(cur);

                string timesStr = to_string(times);
                for (auto &c : timesStr)
                    ans.push_back(c);

                cur = *c;
                times = 1;
            }
            else
                times ++;
        }
        ans.push_back(cur);
        string timesStr = to_string(times);
        for (auto &c : timesStr)
            ans.push_back(c);

        chars = ans;

        return chars.size();
    }
};

int main() {
    vector<char> chars;
    string s;  cin >> s;
    for (auto &c : s)
        chars.push_back(c);

    Solution sol;
    cout << sol.compress(chars) << endl;
    for (auto c : chars)
        cout << c << " ";
    cout << endl;
}