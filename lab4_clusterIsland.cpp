#include <bits/stdc++.h>
using namespace std;

void dfs(int** mat, int row, int col, bool** visited, int n){
    visited[row][col] = true;
    int x[] = {-1,-1,-1,0,0,1,1,1};
    int y[] = {-1,0,1,-1,1,-1,0,1};
    for (int i = 0; i < 8; ++i){
        int X = row + x[i];
        int Y = col + y[i];
        if ((X>= 0 && X < n) && !visited[X][Y] && (Y>=0 && Y< n) && mat[X][Y]){
            dfs(mat, X, Y, visited, n);
        }  
    } 
}

int numberOfIslands(int** mat, int n){
    bool** visited = new bool*[n];
    for (int i = 0; i < n; ++i){
        visited[i] = new bool[n];
        for (int j = 0; j < n; ++j){
            visited[i][j] = false;
        }
    }
    int count = 0;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            if (mat[i][j] && !visited[i][j]){
                dfs(mat, i, j, visited, n);
                count += 1;
            }
        }
    }
    return count;
}

int main(){
    int n;
    cin >> n;
    int** mat = new int*[n];
    for (int i = 0; i < n; ++i){
        mat[i] = new int[n];
        for (int j = 0; j < n; ++j){
            cin >> mat[i][j];
        }
    }
    
    cout << numberOfIslands(mat,n)<< endl;
    return 0;
}
