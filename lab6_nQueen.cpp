#include <bits/stdc++.h>
using namespace std;


bool validPos(int** board, int row, int col, int n){
    
    for (int i = row; i >= 0; i--){
        if (board[i][col] == 1)
            return false;
    }
    
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--){
        if (board[i][j] == 1)
            return false;
    }
    
    for (int i = row, j = col; i >= 0 && j < n; i--, j++){
        if (board[i][j] == 1)
            return false;
    }
    
    return true;
}

void nQueen(int** board, int n, int row){
    
    if (row == n){
        cout << "*********Queen Placement*********" << endl;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cout << board[i][j] <<" ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }
    
    for (int j = 0; j < n; j++){
        if (validPos(board, row, j, n)){
            board[row][j] = 1;
            nQueen(board, n, row + 1);
            board[row][j] = 0;
        }
    }
    return;
}


int main(){
    int n;
    cout << "Enter the number of queens : ";
    cin >> n;
    int** board = new int* [n];
    for (int i = 0; i < n; i++){
        board[i] = new int[n];
        for (int j = 0; j < n; j++)
            board[i][j] = 0;
    }
    
    nQueen(board, n, 0);
    return 0;
}
