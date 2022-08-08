#include <iostream>
#include <vector>
using namespace std;

const vector<string> pad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

vector<string> letterCombinations(string digits) {
    if(digits.empty()) return {};
    vector<string> result;
    result.push_back("");
    for(auto digit : digits) {
        vector<string> tmp;
        for(auto p : pad[digit-'0']) {
            for(auto r : result) tmp.push_back(r + p);
        }
        result.swap(tmp);
    }
    return result;
}