#include<bits/stdc++.h>
using namespace std;

int bfsCount(char** mat, int n, int startRow, int startCol, bool** visited, int** level){
    queue<pair<int,int>> q;
    q.push(make_pair(startRow,startCol));
    visited[startRow][startCol] = true;
    int x[] = {0 , -1, 1, 0};
    int y[] = {-1, 0, 0, 1};
    while(!q.empty()){
        pair<int,int> front = q.front();
        q.pop();
        for (int i = 0; i < 4; i++){
            int row = front.first + x[i];
            int col = front.second + y[i];
            if ((row >= 0 && row < n) && (col >= 0 && col < n) && !visited[row][col]){
                q.push(make_pair(row,col));
                visited[row][col] = true;
                level[row][col] = level[front.first][front.second] + 1;
                if (mat[row][col] == 'd')
                    return level[row][col];
            }
        }
    }
    return -1;
}

int pathDist(char** mat, int n){
    bool** visited = new bool*[n];
    for (int i = 0; i < n; i++){
        visited[i] = new bool[n];
        for (int j = 0; j < n; j++){
            visited[i][j] = false;
        }
    }
    int startRow, startCol;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (mat[i][j] == '0')
                visited[i][j] = true;
            if (mat[i][j] == 's'){
                startRow = i;
                startCol = j;
            }
        }
    }
    int** level = new int* [n];
    for (int i = 0; i < n; i++){
        level[i] = new int[n];
        for (int j = 0; j < n; j++){
            level[i][j] = 0;
        }
    }
    level[startRow][startCol] = 0;
    
    return bfsCount(mat, n, startRow, startCol, visited, level);
}

int main(){
    int n;
    cin >> n;
    char** mat = new char*[n];
    for (int i = 0; i < n; i++){
        mat[i] = new char[n];
        for (int j = 0; j < n; j++){
            cin >> mat[i][j];
        }
    }
    
    cout << pathDist(mat, n) << endl;    
    return 0;
}
