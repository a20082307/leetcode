#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    set<vector<int>> unique_solutions;

    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(begin(nums), end(nums));

        unordered_map<int, int> first_appear;
        unordered_map<int, int> table;
        int len = nums.size();
        for (int i = 0; i < len; i ++) {
            if (table.find(nums[i]) == table.end()) {
                table[nums[i]] = 1;
                first_appear[nums[i]] = i;
            } 
            else
                table[nums[i]] ++;
        }   

        vector<vector<int>> solutions;
        for (int i = 0; i < len; i ++) {
            if (i != first_appear[nums[i]])
                continue;
            
            table[nums[i]] --;

            for (int j = i + 1; j < len; j ++) {
                table[nums[j]] --;
                if (table[-nums[i] - nums[j]] <= 0) {
                    table[nums[j]] ++;
                    continue;
                }

                vector<int> solution = {nums[i], nums[j], -nums[i] - nums[j]};
                sort(begin(solution), end(solution));
                if (unique_solutions.find(solution) != unique_solutions.end()) {
                    table[nums[j]] ++;
                    continue;
                }

                solutions.emplace_back(solution);
                unique_solutions.emplace(solution);
                table[nums[j]] ++;
            }

            table[nums[i]] ++;
        }

        return solutions;
    }
};

void print(vector<vector<int>> solutions) {
    for (auto solution : solutions) {
        for (auto element : solution)
            cout << element << " ";
        cout << endl;
    }
}

int main() {
    Solution solution;

    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    print(solution.threeSum(nums));
    // cout << solution.doHash(-4, 0, 4) << endl;
    // cout << solution.doHash(-4, 1, 3) << endl;
    // cout << solution.doHash(-3, -1, 4) << endl;
    // cout << solution.doHash(-3, 0, 3) << endl;
    // cout << solution.doHash(-3, 1, 2) << endl;
    // cout << solution.doHash(-2, -1, 3) << endl;
    // cout << solution.doHash(-2, 0, 2) << endl;
    // cout << solution.doHash(-1, -1, 2) << endl;
    // cout << solution.doHash(-1, 0, 1) << endl;
}

// cout << "tem: " << nums[i] << "," << nums[j] << "," << -nums[i] - nums[j] << 
//                             ", count: " << table[nums[i]] << "," <<  table[nums[j]] << "," << table[-nums[i] - nums[j]] << endl;