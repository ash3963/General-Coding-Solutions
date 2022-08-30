#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    vector<pair<int, pair<int, int>>> v;
    int dist;
    for(auto &p : points) {
        dist = p[0] * p[0] + p[1] * p[1];
        v.push_back({dist, {p[0], p[1]}}); 
    }
    sort(v.begin(), v.end());
    vector<vector<int>> ans(k);
    for(int i = 0; i < k; i++) {
        ans[i].push_back(v[i].second.first);
        ans[i].push_back(v[i].second.second);
    }
    return ans;
}