#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int maxProduct(vector<int>& nums) {
    int r = nums[0], n = nums.size();
    for(int i = 1, imax = r, imin = r; i < n; i++) {
        if(nums[i] < 0) swap(imax, imin);
        imax = max(nums[i], nums[i] * imax);
        imin = min(nums[i], nums[i] * imin);
        r = max(r, imax);
    }
    return r;
}