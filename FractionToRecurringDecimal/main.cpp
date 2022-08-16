#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

string fractionToDecimal(int numerator, int denominator) {
    if(!numerator) return "0";
    string ans = "";
    if(numerator > 0 ^ denominator > 0) ans += '-';
    long n = labs(numerator), d = labs(denominator);
    long q = n / d;
    long r = n % d;
    ans += to_string(q);
    if(r == 0) return ans;
    ans += '.';
    unordered_map<long, int> mp;
    while(r) {
        if(mp.find(r) != mp.end()) {
            int pos = mp[r];
            ans.insert(pos,"(");
            ans += ')';
            break;
        }
        else {
            mp[r] = ans.size();
            r *= 10;
            q = r / d;
            r = r % d;
            ans += to_string(q);
        }
    }
    return ans;
}