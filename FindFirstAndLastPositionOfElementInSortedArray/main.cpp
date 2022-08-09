#include <iostream>
#include <vector>
using namespace std;


int low_index(vector<int>& arr, int target){
    int l = 0, r = arr.size()-1;
    while(l<=r) {
        int mid = (l + r) / 2;
        if(arr[mid]>=target) r = mid - 1;
        else l = mid + 1;
    }
    if(l < arr.size() && arr[l] == target) return l;
    return -1;
}
int high_index(vector<int>& arr, int target){
    int l = 0, r = arr.size()-1;
    while(l<=r) {
        int mid = (l + r) / 2;
        if(arr[mid] <= target) l = mid + 1;
        else r = mid - 1; 
    }
    if(r < arr.size() && arr[r] == target) return r;
    return -1;
}
vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> result;
    result.push_back(low_index(nums, target));
    result.push_back(high_index(nums, target));
    return result;
}