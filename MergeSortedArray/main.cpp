#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
        
    int i=m-1;
    int j=n-1;
    int k=m+n-1;

    while(j>=0){
        if(i>=0&&nums1[i]>nums2[j]){
            nums1[k]=nums1[i];
            k--;
            i--;
        }
        else{
            nums1[k]=nums2[j];
            k--;
            j--;
        }
    }
}



int main(){

    vector<int> nums1{1,2,4,7,0,0,0};
    vector<int> nums2{1,3,5};
    int n=nums2.size();
    int m=nums1.size()-n;
    merge(nums1, m, nums2,n);
    for(auto val:nums1){
        cout<<val<<" ";
    }

    return 0;
}