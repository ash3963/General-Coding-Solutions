#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> result;

void helper(int begin, vector<int>& nums){
    if(begin >= nums.size()) {
        result.push_back(nums);
        return;
    }
    for(int i = begin; i < nums.size(); i++) {
        swap(nums[begin], nums[i]);
        helper(begin+1, nums);
        swap(nums[begin], nums[i]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    if(nums.size() == 0) return result;
    helper(0, nums);
    return result;
}

