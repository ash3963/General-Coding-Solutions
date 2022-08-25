#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

bool checkSubarraySum(vector<int>& nums, int k) {
    int prefixSum = 0; 
    unordered_map<int,int> mp;
    for(int i = 0; i < nums.size(); i++) {
        prefixSum += nums[i];
        prefixSum %= k;
        if(prefixSum == 0 && i) return true;
        if(mp.find(prefixSum) != mp.end()) {
            if(i - mp[prefixSum] > 1) return true;
        }
        else
            mp[prefixSum] = i;
    }
    return false;
}