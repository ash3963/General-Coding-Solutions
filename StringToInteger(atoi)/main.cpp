#include <iostream>
#include <string>
using namespace std;

int myAtoi(string str) {
    if(str.size()==0) return 0;
    long result = 0;
    int indicator = 1;
    int index = str.find_first_not_of(' ');
    if(index>=str.length()) return 0;

    if(str[index] == '+' || str[index] == '-') indicator = (str[index++] == '-')? -1 : 1;

    while(index < str.length() && isdigit(str[index])) {
        result = result * 10 + (str[index++] - '0');
        if(result * indicator > INT_MAX) return INT_MAX;
        if(result * indicator < INT_MIN) return INT_MIN;
    }
    return result * indicator;
}