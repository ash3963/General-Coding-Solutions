#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

string addBinary(string a, string b) {
    string res = "";
    int i = a.size() - 1, j = b.size() - 1, carry = 0, sum = 0;
    while(i >= 0 || j >= 0) {
        sum = carry;
        if(i >= 0) sum += a[i--] -'0';
        if(j >= 0) sum += b[j--] -'0';
        carry = sum > 1 ? 1 : 0;
        res += (sum % 2) + '0';
    }
    if(carry) res += carry + '0';
    reverse(res.begin(), res.end());
    return res;
}