#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> computeLPSArray(string s)
{

    int len = 0;
    int n = s.size();
    vector<int> lps(n);
    lps[0] = 0;
    int i = 1;
    while (i < n)
    {
        if (s[i] == s[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}


int strStr(string haystack, string needle)
{
    int m=needle.size();
    int n=haystack.size();

    vector<int> lps= computeLPSArray(needle);

    int i=0;
    int j=0;
    while((n-i)>=(m-j)){
        if(needle[j]==haystack[i]){
            i++;
            j++;
        }
        if(j==m){
            return (i-j);
            j=lps[j-1];
        }
        else if(i<n && needle[j]!=haystack[i]){
            
            if(j!=0){
                j=lps[j-1];
            }
            else{
                i++;
            }    
        }
    }
    return -1;
}



int main()
{

    string haystack{"Ashish"};
    string needle{"is"};
    int n=strStr(haystack,needle);
    if(n!=-1){
        cout<<"Found at index: "<<n;
    }
    else{
        cout<<"Not Found.";
    }

    return 0;
}