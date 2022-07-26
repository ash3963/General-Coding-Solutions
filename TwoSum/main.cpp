#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
        unordered_map<int,int> hash;
        vector<int> result;
        for(size_t i=0;i<nums.size();i++){
            int numToFind=target-nums[i];
            if(hash.find(numToFind)!=hash.end()){
                result.push_back(hash[numToFind]);
                result.push_back(i);
            }
            hash[nums[i]]=i;
        } 
        return result;
}

int main()
{

    vector<int> num = {2, 9, 11, 7};
    int target = 20;
    vector<int> result= twoSum(num,target);
    for(auto val: result){
        cout<<val<<" ";
    }
    return 0;
}