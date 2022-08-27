#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool reorderedPowerOf2(int n) {
    string num = to_string(n);
    sort(num.begin(), num.end());
    for(int i = 0; i < 30; i++) {
        int p = pow(2, i);
        string power = to_string(p);
        sort(power.begin(), power.end());
        if(power == num) return true;
    }
    return false;
}