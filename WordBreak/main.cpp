#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<int> dp;
    unordered_set<string> uos;
    for(auto w : wordDict) uos.insert(w);
    dp.insert(0);
    int n = s.size();
    for(int i = 1; i<=n; i++) {
        for(auto& j: dp) {
            if(uos.find(s.substr(j, i-j)) != uos.end()) {
                dp.insert(i);
                break;
            }
        }
    }
    return (dp.find(n) != dp.end());
}

