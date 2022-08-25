#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool isAlienSorted(vector<string>& words, string order) {
    unordered_map<char,int> mp;
    for(int i = 0; i < order.size(); i++) mp[order[i]] = i;
    for(int i = 0; i < words.size() - 1; i++) {
        string word1 = words[i], word2 = words[i + 1];
        int i1 = 0, i2 = 0;
        while(i2 < word2.size() && i1 < word1.size() && word1[i1] == word2[i2]) i1++, i2++;
        if(i2 == word2.size() && i1 < word1.size()) return false;
        if(i1 < word1.size() && i2 < word2.size())
            if(mp[word1[i1]] > mp[word2[i2]]) return false;
    }
    return true;
}