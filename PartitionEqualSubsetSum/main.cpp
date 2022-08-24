#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool helper(vector<int> &nums, vector<vector<int>>& dp, int idx, int target) {
    if(target == 0) return true;
    if(idx == nums.size()) return false;
    if(dp[idx][target] != -1) return dp[idx][target];
    if(target >= nums[idx]) {
        bool check = helper(nums, dp, idx + 1, target - nums[idx]);
        if(check) {
            dp[idx][target] = check;
            return true;
        }
    }
    bool check = helper(nums, dp, idx + 1, target);
    dp[idx][target] = check;
    return check;
}

bool canPartition(vector<int> &nums) {
    int sum = 0;
    for(auto a : nums) sum += a;
    vector<vector<int>> dp(nums.size(), vector<int>(sum / 2 + 1, -1));
    return (sum % 2 != 0) ? false : helper(nums, dp, 0, sum / 2); 
}