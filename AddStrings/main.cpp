#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

string addStrings(string num1, string num2) {
    string res = "";
    int sum = 0, carry = 0;
    int i = num1.size() - 1, j = num2.size() - 1;
    while(i >= 0 || j >= 0) {
        sum = carry;
        if(i >= 0) sum += num1[i--] + '0';
        if(j >= 0) sum += num2[j--] + '0';
        carry = sum > 9 ? sum/10 : 0;
        res += sum % 10 + '0';
    }
    if(carry) res += carry + '0';
    reverse(res.begin(), res.end());
    return res;    
}