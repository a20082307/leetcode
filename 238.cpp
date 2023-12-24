#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int productForAll = 1, zeros = 0;
        for (int i = 0; i < nums.size(); i ++) {
            if (!nums[i])
                zeros ++;
            else
                productForAll *= nums[i];
        }

        vector<int> ans;
        for (int i = 0; i < nums.size(); i ++) {
            if (!nums[i]) {
                if (zeros == 1) 
                    ans.push_back(productForAll);
                else
                    ans.push_back(0);
            
            }
            else {
                if (zeros)
                    ans.push_back(0);
                else
                    ans.push_back(productForAll / nums[i]);
            }
        }

        return ans;
    }
};

int main() {
    int n;  cin >> n;
    
    vector<int> nums;
    while (n --) {
        int num;    cin >> num;
        nums.push_back(num);
    }

    Solution sol;
    vector<int> ans = sol.productExceptSelf(nums);
    for (int i = 0; i < ans.size(); i ++)
        cout << ans[i] << " ";
    cout << endl;
}