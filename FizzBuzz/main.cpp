#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> fizzBuzz(int n){
    
        ios_base::sync_with_stdio(0);
        vector<string> v(n);
        for(int i=1;i<=n;i++)
            v[i-1]=to_string(i);
        for(int i=2;i<n;i+=3)
            v[i]="Fizz";
        for(int i=4;i<n;i+=5)
            v[i]="Buzz";
        for(int i=14;i<n;i+=15)
            v[i]="FizzBuzz";
        return v;  
}