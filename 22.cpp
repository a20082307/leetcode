#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    void f(int l,int r,int n,string s,vector<string> &ans){
        if(s.length() == 2 * n){
            ans.push_back(s);
            return;
        }

        if(l < n)
            f(l + 1,r,n,s + '(',ans);
        if(r < l)
            f(l,r + 1,n,s + ')',ans);

    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        f(0,0,n,"",ans);
        return ans;
    }
};

void print(vector<string> aim) {
    for (auto i : aim)
        cout << i << endl;
    cout << endl;
}

int main() {
    Solution s;
    
    print(s.generateParenthesis(3));
}