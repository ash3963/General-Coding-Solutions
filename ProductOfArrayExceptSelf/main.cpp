#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> ans(size(nums), 1);
    for(int i = 1; i < nums.size(); i++)
        ans[i] = ans[i-1] * nums[i-1];
    for(int i = nums.size() - 1, sp = 1; i >= 0; i--) {
        ans[i] *= sp;
        sp *= nums[i];
    }
    return ans;
}