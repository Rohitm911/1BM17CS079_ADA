#include <bits/stdc++.h>
using namespace std;
#define N 9

bool isSafe(int grid[N][N], int row, int col, int num){
    for (int i = 0; i < N; i++){
        if (grid[row][i] == num)
            return false;
    }
    
    for (int i = 0; i< N; i++){
        if (grid[i][col] == num)
            return false;
    }
    
    int rowFactor = row - (row % 3);
    int colFactor = col - (col % 3);
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (grid[i + rowFactor][j + colFactor] == num)
                return false;
        }
    }
    return true;
}

bool findEmptySpace(int grid[N][N],int& row, int& col){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (grid[i][j] == 0){
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}

bool solveSudoku(int grid[N][N]){
    int row, col;
    if (!findEmptySpace(grid,row, col)){
        return true;
    }
    
    for (int i = 1; i <= 9; i++){
        if (isSafe(grid, row, col , i)){
            grid[row][col] = i;
            if (solveSudoku(grid))
                return true;
            grid[row][col] = 0;
        }
    }
    return false;
}

int main(){
    int grid[N][N];
    for (int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> grid[i][j];
        }
    }
    solveSudoku(grid);
    cout << endl;
    for (int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << grid[i][j]<<" ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}

/*
0 3 0 2 8 7 0 5 0
5 8 0 6 4 1 9 0 0
1 0 6 9 0 0 0 2 4
2 0 0 0 6 0 3 0 8
0 9 5 0 0 0 2 6 0
8 0 4 0 3 0 0 0 9 
6 2 0 0 0 5 4 0 3
0 0 3 8 2 6 0 1 5
0 5 0 3 1 4 0 9 0

*/

