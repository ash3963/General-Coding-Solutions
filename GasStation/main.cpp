#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    int totalSurplus = 0, surplus = 0, start = 0;
    for(int i = 0; i < n; i++) {
        totalSurplus += gas[i] - cost[i];
        surplus += gas[i] - cost[i];
        if(surplus < 0){
            surplus = 0;
            start = i + 1;
        }
    }
    return (totalSurplus < 0) ? -1 : start; 
}