#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }

    bool increasingTriplet(vector<int>& nums) {
        int size = nums.size();
        if (size < 3)
            return false;

        int first, second, third;
        first = INT_MAX;
        second = INT_MAX;
        third = INT_MIN;
        for (int i = 0; i < size; i ++) {
            first = min(first, nums[i]);
            if (nums[i] > first)
                second = min(second, nums[i]);
            if (nums[i] > second)
                third = max(third, nums[i]);
            if (first < second && second < third)
                return true;
        }

        return false;
    }
};

int main() {
    int n;  cin >> n;

    vector<int> nums;
    while (n --) {
        int num;  cin >> num;
        nums.push_back(num);
    }

    Solution sol;
    cout << sol.increasingTriplet(nums) << endl;
}