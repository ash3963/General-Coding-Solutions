#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool paraCheck(char y, char x)
{
    return ((x == '(' && y == ')') || (x == '[' && y == ']') || (x == '{' && y == '}'));
}

bool isValid(string s)
{
    int n = s.size();
    if(n&1)
        return false;
    stack<char> st;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            st.push(s[i]);
        else{
            if (st.empty())
                return false;
            if (paraCheck(s[i], st.top()))
                st.pop();
            else
                return false;
        }     
    }
    return st.empty();
}

int main()
{

    string s = "()";
    cout << isValid(s);
    return 0;
}