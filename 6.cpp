#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        if (numRows == 1)
            return s;

        int len = s.length();
        if (len <= 2)
            return s;

        int unit = 2 * numRows - 2; // The length of each unit、the index of the head of the first unit
        int unit_num = len / unit;  // The number of complete units
        string ans = "";
        for (int i = 0; i < unit_num; i ++) 
            ans += string(1, s[i * unit]);
        if (len > unit * unit_num)
            ans += string(1, s[unit * unit_num]);

        for (int i = 1; i < numRows - 1; i ++) {
            for (int j = 0; j < unit_num; j ++) {
                ans += string(1, s[j * unit + i]);
                ans += string(1, s[j * unit + unit - i]);
            }

            if (len <= unit * unit_num + i)
                continue;
            ans += string(1, s[unit_num * unit + i]);

            if (len <= unit * unit_num + unit - i)
                continue;
            ans += string(1, s[unit_num * unit + unit - i]);
        }

        for (int i = 0; i < unit_num; i ++)
            ans += string(1, s[i * unit + numRows - 1]);
        if (len > unit * unit_num + numRows - 1)
            ans += string(1, s[unit * unit_num + numRows - 1]);

        return ans;
    }
};

int main() {
    Solution s;
    string str;

    str = "PAYPALISHIRING";
    cout << s.convert(str, 3) << endl << (s.convert(str, 3) == string("PAHNAPLSIIGYIR")) << endl;

    cout << s.convert(str, 4) << endl << (s.convert(str, 4) == string("PINALSIGYAHRPI")) << endl;

    str = 'A';
    cout << s.convert(str, 1) << endl << (s.convert(str, 1) == string("A")) << endl;
}