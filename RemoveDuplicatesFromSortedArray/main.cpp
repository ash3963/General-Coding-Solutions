#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    int n = nums.size();
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        if (nums[i] == nums[i - 1])
            count++;
        else
            nums[i - count] == nums[i];
    }
    return n - count;
}

int main()
{

    vector<int> arr{1, 2, 2, 3, 4, 4};
    cout << removeDuplicates(arr);

    return 0;
}