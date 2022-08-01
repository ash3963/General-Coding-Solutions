#include <iostream>
#include  <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
        
    int n=nums.size();
    int count=0;
    for(int i=0;i<n;i++){
        if(nums[i]==0)
            count++;
        else
            nums[i-count]=nums[i];
    }
    for(int i=n-count;i<n;i++){
        nums[i]=0;
    }
}