#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> findAnagrams(string s, string p) {
    int s_len = s.size();
    int p_len = p.size();
    if(s_len < p_len) return {};
    vector<int> freq_p(26,0);
    vector<int> window(26,0);
    for(int i = 0; i < p_len; i++) {
        freq_p[p[i] - 'a']++;
        window[s[i] - 'a']++;
    }
    vector<int> ans;
    if(freq_p == window) ans.push_back(0);
    for(int i = p_len; i < s_len; i++) {
        window[s[i - p_len] - 'a']--;
        window[s[i] - 'a']++;
        if(window == freq_p) ans.push_back(i - p_len + 1);
    }
    return ans;
}