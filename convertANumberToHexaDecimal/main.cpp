#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

string toHex(int num) {
    if(num == 0) return "0";
    unsigned int num1 = num;
    string hex = "";
    int rem;
    while(num1 > 0) {
        rem = num1 % 16;
        hex += (rem < 10) ?  ('0' + rem) : ('a' + (rem % 10));
        num1 /= 16;
    }
    reverse(hex.begin(), hex.end());
    return hex;

}