#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int dir[5] = {0, 1, 0, -1, 0};

void floodFill(vector<vector<int>>& grid, int i, int j, vector<pair<int,int>>& is, vector<vector<int>>& vis) {
    if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0) return;
    grid[i][j] = 0;
    vis[i][j] = 1;
    is.push_back({i,j});
    for(int k = 0; k < 4; k++) {
        floodFill(grid, i + dir[k], j + dir[k+1], is, vis);
    }
}

int dist(vector<pair<int,int>>& is1, vector<pair<int,int>>& is2, int i, int j) {
    return abs(is1[i].first - is2[j].first) + abs(is1[i].second - is2[j].second) - 1;
}

int shortestBridge(vector<vector<int>>& grid) {
    vector<pair<int,int>> is1;
    vector<pair<int,int>> is2;
    int count = 0;
    vector<vector<int>>vis(grid.size(), vector<int>(grid[0].size(), 0));
    for(int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid[0].size(); j++) {
            if(grid[i][j] == 1 && vis[i][j] == 0) {
                if(count == 0) {
                    floodFill(grid, i, j, is1, vis);
                    count++;
                }
                else
                    floodFill(grid, i, j, is2, vis);
            }
        }
    }
    //finding the minimum distance
    int minDist = INT_MAX;
    for(int i = 0; i < is1.size(); i++) {
        for(int j = 0; j < is2.size(); j++) {
            minDist = min(minDist, dist(is1,is2, i, j)); 
        }
    }
    return minDist;
}