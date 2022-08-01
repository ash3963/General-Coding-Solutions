#include <iostream>
#include <unordered_map>
using namespace std;

int firstUniqChar(string s) {

    ios_base::sync_with_stdio(0);
    int n= s.size();
    int f[26]{};
    for(int i : s){
        f[i-'a']++;
    }
    for(int i=0;i<n;i++){
        if(f[s[i]-'a']==1)
            return i;
    }
    return -1;
}