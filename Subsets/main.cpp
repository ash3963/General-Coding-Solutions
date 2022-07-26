#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result = {{}};
    for(auto num : nums) {
        int n = result.size();
        for(int i = 0; i < n; i++) {
            result.push_back(result[i]);
            result.back().push_back(num);
        }
    }
    return result;
}