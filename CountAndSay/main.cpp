#include <iostream>
#include <string>
using namespace std;

string countAndSay(int n) {
    if(n == 0) return 0;
    string result = "1";
    while(--n) {
        string cur = "";
        for(int i = 0; i < result.size(); i++) {
            int count = 1;
            while((i + 1) < result.size() && result[i + 1] == result[i]) {
                count++; i++;
            }
            cur += to_string(count) + result[i];
        }
        result = cur;
    }
    return result;
}