#include <iostream>
#include <vector>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    bool isZeroCol = false, isZeroRow = false;
    for(int i = 0; i < m; i++) {
        if(matrix[i][0] == 0) {
            isZeroCol = true;
            break;
        }
    }
    for(int i = 0; i < n; i++) {
        if(matrix[0][i] == 0) {
            isZeroRow = true;
            break;
        }
    }
    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            if(matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            if(matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
    }
    if(isZeroCol) {
        for(int i = 0; i < m; i++) {
            matrix[i][0] = 0;
        }
    }
    if(isZeroRow) {
        for(int i = 0; i < n; i++) {
            matrix[0][i] = 0;
        }
    }
}