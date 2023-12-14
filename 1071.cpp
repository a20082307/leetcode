#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int len1 = str1.length(), len2 = str2.length();
        int min_len = min(len1, len2);
        int len = gcd(len1, len2);
        if (len == 1) {
            for (int i = 0; i < min_len; i ++) {
                if (str1[i] != str1[0] || str2[i] != str1[0])
                    return "";
            }
            
            if (min_len == len1) {
                for (int i = min_len; i < len1; i ++) {
                    if (str1[i] != str1[0])
                        return "";
                }
            }
            
            for (int i = min_len; i < len2; i ++) {
                if (str2[i] != str1[0])
                    return "";
            }
            return str1.substr(0, 1);
        }

        string ans = "";
        for (int i = 1; i <= len; i ++) {
            if (i % len != 0)
                continue;
            
            string candidate = str1.substr(0, i);
            for (int j = 0; j < min_len; j += i) {
                if (str1.substr(j, i) != candidate || str2.substr(j, i) != candidate) {
                    candidate = "";
                    break;
                }
            }
            if (candidate == "")
                continue;

            if (min_len == len1) {
                for (int j = min_len; j < len2; j += i) {
                    if (str2.substr(j, i) != candidate) {
                        candidate = "";
                        break;
                    }
                }
            }
            else {
                for (int j = min_len; j < len1; j += i) {
                    if (str1.substr(j, i) != candidate) {
                        candidate = "";
                        break;
                    }
                }   
            }
            if (candidate == "")
                continue;
            
            ans = candidate;
        }

        return ans;
    }

    int gcd (int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
};

int main() {
    Solution s;

    string str1, str2;
    cin >> str1 >> str2;
    cout << s.gcdOfStrings(str1, str2) << endl;
}