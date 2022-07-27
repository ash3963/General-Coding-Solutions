#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

vector<int> plusOne(vector<int> &digits)
{
    int n = digits.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if (digits[i] == 9)
        {
             digits[i]=0;
        }
        else
        {
            digits[i]++;
            return digits;
        }
    }
    digits[0]=1;
    digits.push_back(0);
    return digits;
    
}

int main()
{
    vector<int> digits{1,1,9};
    digits=plusOne(digits);
    for (auto val : digits)
    {
        cout << val << " ";
    }
}