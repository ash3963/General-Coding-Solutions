#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int rob(vector<int>& nums) {
    int n = nums.size();
    if(n == 1) return nums[0];
    int secondPrev = nums[0], prev = max(nums[0], nums[1]), curr = prev;
    for(int i = 2; i < n; i++) {
        curr = max(prev, nums[i]+secondPrev);
        secondPrev = prev;
        prev = curr;
    }
    return curr;
}