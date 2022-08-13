#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    if(!nums.size()) return 0;
    unordered_set<int> uos(nums.begin(), nums.end());
    int result = 1;
    for(auto num : nums) {
        if(uos.find(num) == uos.end()) continue;
        uos.erase(num);
        int prev = num - 1, next = num + 1;
        while(uos.find(prev) != uos.end()) uos.erase(prev--);
        while(uos.find(next) != uos.end()) uos.erase(next++);
        result = max(result, next - prev -1);
    }
    return result;
}
