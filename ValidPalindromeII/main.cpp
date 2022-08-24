#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool validPalindrome(string s) {
    int l = 0, r = s.size() - 1;
    while( l < r) {
        if(s[l] != s[r]) {
            int x1 = l, y1 = r - 1, x2 = l + 1, y2 = r;
            while(x1 < y1 && s[x1] == s[y1]) x1++, y1--;
            while(x2 < y2 && s[x2] == s[y2]) x2++, y2--;
            return x1 >= y1 || x2 >= y2;
        }
        l++; r--;
    }
    return true;     
}