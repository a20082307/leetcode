#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ans = 0;
        int len = nums.size();
        for (int i = ans; i < len; i ++) {
            if (nums[i] != val)
                nums[ans ++] = nums[i];
        }

        return ans;
    }

    string print(vector<int>& nums) {
        string ans = " [";
        for (int i = 0; i < nums.size(); i ++)
            ans += to_string(nums[i]) + ", ";
        ans += "]\n";

        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums;

    nums = {3, 2, 2, 3};
    cout << s.removeElement(nums, 3) << s.print(nums);

    nums = {0, 1, 2, 2, 3, 0, 4, 2};
    cout << s.removeElement(nums, 2) << s.print(nums);
}