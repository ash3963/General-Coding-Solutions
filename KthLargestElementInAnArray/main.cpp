#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int partition(vector<int>& nums,int left ,int right) {
    int pivot = nums[left], l = left + 1, r = right;
    while(l <= r) {
        if(nums[l] < pivot && nums[r] > pivot) swap(nums[l++], nums[r--]);
        if(nums[l] >= pivot) l++;
        if(nums[r] <= pivot) r--;
    }
    swap(nums[left], nums[r]);
    return r;
}


int findKthLargest(vector<int>& nums, int k) {
    int left = 0, right = nums.size() - 1, index = 0;
    while(1) {
        index = partition(nums, left, right);
        if(index == k - 1) break;
        else if(index < k - 1) left = index + 1;
        else right = index - 1;
    }
    return nums[index];
}