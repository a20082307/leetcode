#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        ios::sync_with_stdio(false);

        int left = 0, right = height.size() - 1;
        int max_area = findArea(height[left], height[right], right - left);
        while (left < right) {
            max_area = max(max_area, findArea(height[left], height[right], right - left));
            if (height[left] == height[right])
                left++, right--;
            else if (height[left] < height[right]) 
                left++;
            else
                right--;
        }

        return max_area;
    }

    inline int findArea(int left, int right, int dis) {
        return min(left, right) * dis;
    }
};

int main() {
    Solution solution;
    vector<int> height = {2,3,4,5,18,17,6};
    cout << solution.maxArea(height) << endl;
    vector<int> height2 = {1,8,6,2,5,4,8,3,7};
    cout << solution.maxArea(height2) << endl;
    vector<int> height3 = {1,2,3,4,5,25,24,3,4};
    cout << solution.maxArea(height3) << endl;
    vector<int> height4 = {1,3,2,5,25,24,5};
    cout << solution.maxArea(height4) << endl;
    vector<int> height5 = {1,1000,1000,6,2,5,4,8,3,7};
    cout << solution.maxArea(height5) << endl;
    return 0;
}