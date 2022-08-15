#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<vector<string>> result;
vector<string> path;

bool isPalindrome(string& s, int start, int end) {
    while(start <= end) {
        if(s[start++] != s[end--])
            return false;
    }
    return true;
}

void dfs(int index, string& s) {
    if(index == s.size()) {
        result.push_back(path);
        return;
    }
    for(int i = index; i < s.size(); i++) {
        if(isPalindrome(s, index, i)) {
            path.push_back(s.substr(index, i - index + 1));
            dfs(i+1, s);
            path.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    if(s.empty()) return result;
    dfs(0, s);
    return result;
}