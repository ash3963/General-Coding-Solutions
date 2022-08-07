#include <iostream>
using namespace std;

string longestPalindrome(string s) {
    if(s.size() <= 1) return s;
    int min_left = 0;
    int max_right = s.size()-1;
    int maxLen = 1;
    for(int mid = 0; mid < s.size();){
        int l = mid;
        int r = mid;
        while(r < max_right && s[r+1] == s[r]) r++;
        mid = r + 1;
        while(r < max_right && l > 0 && s[r+1] == s[l-1]) {
            r++;l--;
        }
        int newLen = r - l + 1;
        if(newLen > maxLen){
            min_left = l;
            maxLen = newLen;
        }
    }
    return s.substr(min_left, maxLen);
}