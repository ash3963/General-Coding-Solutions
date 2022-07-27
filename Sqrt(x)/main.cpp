#include <iostream>
using namespace std;

int mySqrt(int x)
{
    long long s=0,e=INT_MAX,ans=0;
    while(s<=e){
        long long m=(e+s)/2;
        if(m*m<=x){
            ans=m;
            s=m+1;
        }
        else{
            e=m-1;
        }
    }
    return ans;
}

int main()
{

    int x;
    cout<<"Enter: ";cin>>x;
    cout << mySqrt(x);
    return 0;
}