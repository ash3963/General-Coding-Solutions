#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int findPeakElement(vector<int>& nums) {
    int lo = 0, hi = nums.size() - 1;
    while(lo < hi){
        int mid = (lo + hi) / 2;
        if(nums[mid] < nums[mid + 1]) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}