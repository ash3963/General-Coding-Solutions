#include <iostream>
#include <vector>
using namespace std;

vector<string> result;

void helper(string s, int l, int m){
    if(l == 0 && m == 0) {
        result.push_back(s);
        return;
    }
    if(l>0) helper(s + "(", l-1, m+1);
    if(m>0) helper(s + ")", l, m-1);
}

vector<string> generateParenthesis(int n) {
    helper("", n, 0);
    return result;
}