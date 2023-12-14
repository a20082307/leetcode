#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> ans = {nums[0]};

        int len = nums.size();
        int ans_len = len;
        for (int i = 1; i < len; i ++) {
            if (nums[i] == nums[i - 1]) {
                ans_len --;
                continue;
            }
            ans.emplace_back(nums[i]);
        }

        nums = ans;
        return ans_len;
    }
};

void print(vector<int>& nums) {
    cout << "[";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << ", ";
    }
    cout << ']' << endl;
}

int main() {
    Solution s;
    vector<int> nums;

    nums = {1, 1, 2};
    cout << s.removeDuplicates(nums) << " ";
    print(nums);

    nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    cout << s.removeDuplicates(nums) << " ";
    print(nums);

    nums = {0, 0, 0, 3};
    cout << s.removeDuplicates(nums) << " ";
    print(nums);
}