#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

int calculate(string s) {
    stack<int> stk;
    char sign = '+';
    int res = 0; long tmp = 0;
    for(unsigned int i = 0; i < s.size(); i++) {
        if(isdigit(s[i]))
            tmp = 10 * tmp + s[i] - '0';
        if(!isdigit(s[i]) && !isspace(s[i]) || i == s.size() - 1) {
            if(sign == '+')
                stk.push(tmp);
            else if(sign == '-')
                stk.push(-tmp);
            else {
                int num;
                if(sign == '*')
                    num = stk.top() * tmp;
                else
                    num = stk.top() / tmp;
                stk.pop();
                stk.push(num);
            }
            sign = s[i];
            tmp = 0;
        }
    }
    while(!stk.empty()) {
        res += stk.top();
        stk.pop();
    }
    return res;
}

int calculate(string s) {
    s+= "++"; char sign = '+';
    int ans = 0, num = 0, tmp = 0;
    for(char& c : s) {
        if(c = ' ') continue;
        if(isdigit(c)) num = num * 10 + c - '0';
        else {
            if(sign == '+') {
                ans += tmp; tmp = num;
            }
            else if(sign == '-') {
                ans += tmp; tmp = -num;
            }
            else if(sign == '*') {
                tmp *= num;
            }
            else
                tmp /= num;
            sign = c;
            num = 0;
        }
    }
    return ans;
}