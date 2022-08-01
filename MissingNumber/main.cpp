#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int missingNumber(vector<int>& nums) {
        int result = nums.size();
        int i=0;
        
        for(int num:nums){
            result ^= num;
            result ^= i;
            i++;
        }
        return result;
}