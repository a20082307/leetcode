#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));

        int len = nums.size();
        vector<vector<int>> ans = {};
        if (len < 4)
            return ans;

        for (int i = 0; i < len - 3; i ++) {
            if (i > 0)
                if (nums[i] == nums[i - 1])
                    continue;

            if (nums[i] + nums[i] > target && nums[i] > 0)
                break;

            for (int j = i + 1; j < len - 2; j ++) {
                if (j > i + 1)
                    if (nums[j] == nums[j - 1])
                        continue;

                if (nums[j] > target && nums[j] > 0)
                    break;

                int l = j + 1, r = len - 1;
                long long int tem_sum = (long long int)nums[i] + (long long int)nums[j] + (long long int)nums[l] + (long long int)nums[r];
                while (l < r) {
                    if (l > j + 1) {
                        if (nums[l] == nums[l - 1]) {
                            tem_sum -= nums[l ++];
                            tem_sum += nums[l];
                            continue;
                        }
                    }
                    if (r < len - 1) {
                        if (nums[r] == nums[r + 1]) {
                            tem_sum -= nums[r --];
                            tem_sum += nums[r];
                            continue;
                        }
                    }

                    while (tem_sum > target && l < r - 1) {
                        tem_sum -= nums[r --];
                        tem_sum += nums[r];
                    }
                    while (tem_sum < target && l < r - 1) {
                        tem_sum -= nums[l ++];
                        tem_sum += nums[l];
                    }

                    if (tem_sum == target) {
                        ans.emplace_back(vector<int>{nums[i], nums[j], nums[l], nums[r]});
                        tem_sum = nums[i] + nums[j] + nums[++ l] + nums[-- r];
                    }

                    if (l + 1 == r && tem_sum != target)
                        break;
                }


            }
        }    

        return ans;
    }
};

void print(vector<vector<int>> ans) {
    cout << "==========    Answer    ==========" << endl;
    for (auto i : ans) {
        for (auto j : i) 
            cout << j << " ";

        cout << endl;
    }
    cout << "==================================" << endl << endl;
}

int main() {
    Solution s;

    vector<int> nums = {-2, -1, 0, 0, 1, 2};
    // print(s.fourSum(nums, 0));

    // nums = {-3, -1, 0, 2, 4, 5};
    // print(s.fourSum(nums, 2));
    // print(s.fourSum(nums, 1));

    // nums = {-1, 0, 1, 2};
    // print(s.fourSum(nums, 2));

    // nums = {-3, -2, -1, 0, 0, 1, 2, 3};
    // print(s.fourSum(nums, 0));

    // nums = {-2, -1, -1, 1, 1, 2, 2};
    // print(s.fourSum(nums, 0));

    nums = {0, 0, 0, 0};
    print(s.fourSum(nums, 0));
}