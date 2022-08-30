#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> result;
    int idx = 0;
    while(idx < intervals.size() && intervals[idx][1] < newInterval[0])
       result.push_back(intervals[idx++]); 
    while(idx < intervals.size() && intervals[idx][0] <= newInterval[1]) {
        newInterval[0] = min(newInterval[0], intervals[idx][0]);
        newInterval[1] = max(newInterval[1], intervals[idx][1]);
        idx++;
    }
    result.push_back(newInterval);
    while(idx < intervals.size())
        result.push_back(intervals[idx++]);
    return result;
}