#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


int majorityElement(vector<int>& nums){
      
    unordered_map<int,int> m;
    for(int num : nums){
        if(++m[num]>nums.size()/2){
            return num;
        }
    }
    return 0;
}