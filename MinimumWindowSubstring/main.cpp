#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

string minWindow(string s, string t) {
    unordered_map<char,int> map1;
    unordered_map<char,int> map2;
    int minDist = INT_MAX, start = 0, counter = 0;
    string result;
    for(char &a : t) map1[a]++;
    for(int i = 0; i < s.length(); i++) {
        char ch = s[i];
        if(map1.find(ch) != map1.end()) {
            map2[ch]++;
            if(map2[ch] <= map1[ch]) counter++;
        } 
        if(counter >= t.length()) {
            while(map1.find(s[start]) == map1.end() || map2[s[start]] > map1[s[start]]) {
                map2[s[start]]--;
                start++;
            }
            if(i - start + 1 < minDist) {
                minDist = i - start + 1;
                result = s.substr(start, minDist);
            }
        }
    }
    return result;
}