#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int>& prices){

    int profit=0;
    int buy=0;
    int n=prices.size();
    for(int i=0;i<n;i++){
        if(prices[buy]>prices[i])
            buy=i;
        profit=max(profit,prices[i]-prices[buy]);
    }
    return profit;
}




int main(){

    vector<int> prices{7,6,4,3,1};
    cout<<maxProfit(prices);
    return 0;
}