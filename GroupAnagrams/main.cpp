#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> ump;
    for(auto& s : strs) {
        string t = s;
        sort(t.begin(), t.end());
        ump[t].push_back(s);
    }
    vector<vector<string>> result;
    result.reserve(ump.size());
    for(auto& p : ump) {
        result.push_back(move(p.second));
    }
    return result;
}