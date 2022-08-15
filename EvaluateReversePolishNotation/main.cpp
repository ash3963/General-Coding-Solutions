#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int> st;
    for(auto t : tokens){
        if(t.size() > 1 || isdigit(t[0])) st.push(stoi(t));
        else {
            auto x2 = st.top(); st.pop();
            auto x1= st.top(); st.pop();
            switch(t[0]) {
                case '+': x1 += x2; break;
                case '-': x1 -= x2; break;
                case '*': x1 *= x2; break;
                case '/': x1 /= x2; break;
            }
            st.push(x1);
        }
    }
    return st.top();
}