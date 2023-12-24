#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int len = candies.size();
        vector<bool> ans(len, false);
        
        int max = 0;
        for (auto i : candies) {
            if (i > max)    
                max = i;
        }

        for (int i = 0; i < len; i++) {
            if (candies[i] + extraCandies >= max)
                ans[i] = true;
        }

        return ans;
    }
};  

int main() {
    int n;  cin >> n;
    vector<int> candies;
    for (int i = 0; i < n; i++) {
        int tmp;  cin >> tmp;
        candies.push_back(tmp);
    }
    int extraCandies;   cin >> extraCandies;

    Solution sol;
    vector<bool> ans = sol.kidsWithCandies(candies, extraCandies);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}