#include <iostream>
#include <string>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    int min =1000;
    string minStr;
    for(int i=0;i<strs.size();i++){
        if(strs[i].length()<min){
            min=strs[i].length();
            minStr=strs[i];
        }
    }
    for(int i=0;i<min;i++){
        for(int j=0;j<strs.size();j++){
            if(strs[j][i]!=minStr[i]){
                return minStr.substr(0,i);
            }
        }
    }
    return minStr;

}

int main()
{

    vector<string> strs = {"Robert", "Robby", "Robber"};
    cout << longestCommonPrefix(strs);

    return 0;
}