#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));

        int diff = INT_MAX;
        int left, right, len = nums.size();
        for (int i = 0; i < len; i ++) {
            left = i + 1, right = len - 1;

            while (left < right) {
                if (nums[i] + nums[left] + nums[right] == target)
                    return target;

                if (abs(nums[i] + nums[left] + nums[right] - target) < abs(diff))
                    diff = nums[i] + nums[left] + nums[right] - target;

                if (nums[i] + nums[left] + nums[right] < target)
                    left ++;
                else
                    right --;

                if (left >= right) 
                    break;
            }   
        }

        return target + diff;
    }
};

int main() {
    Solution s;

    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    cout << s.threeSumClosest(nums, target) << endl;

    nums = {0, 0, 0};
    target = 1;
    cout << s.threeSumClosest(nums, target) << endl;
}