#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


bool containsDuplicate(vector<int> &nums){

        unordered_map<int,int> m;
        for (int num : nums){
            m[num]++;
            if (m[num]>1)
                return true;    
        }
        return false;
}

int main(){

    vector<int> nums{1,2,3,4};
    containsDuplicate(nums);
    return 0;
}