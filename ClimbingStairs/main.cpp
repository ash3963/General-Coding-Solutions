#include <iostream>
using namespace std;

int climbStairs(int n){

    if(n<=2)
        return n;
        
    int t1=0,t2=1,nt=0;
    for(int i=0;i<n;i++){

        nt=t1+t2;
        t1=t2;
        t2=nt;
    }
    return nt;
}




int main(){


    int n;
    cout<<"Enter n: ";
    cin>>n;
    cout<<endl;
    cout<<"Number of steps: "<<climbStairs(n)<<endl;
    return 0;
}