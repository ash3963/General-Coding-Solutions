#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int countPrimes(int n) {
    vector<bool> seen(n, false);
    int ans = 0;
    for(long i = 2; i < n; i++) {
        if(seen[i]) continue;
        ans++;
        for(long j = i * i; j < n; j += i) {
            seen[j] = true;
        }
    }
    return ans;
}