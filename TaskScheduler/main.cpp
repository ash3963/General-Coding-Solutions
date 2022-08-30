#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char,int> ump;
    int count = 0;
    for(auto &t : tasks) {
        ump[t]++;
        count = max(count, ump[t]);
    }
    int ans = (count - 1) * (n + 1);
    for(auto &u : ump) {
        if(u.second == count) ans++;
    }
    return max(ans, (int)tasks.size());
}