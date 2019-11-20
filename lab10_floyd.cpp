#include<bits/stdc++.h>
using namespace std;

int main(){

   int n;
   cin >> n;
   int** mat = new int*[n];
   for (int i = 0; i < n; i++){
      mat[i] = new int [n];
      for (int j = 0; j < n; j++){
         cin >> mat[i][j];
      }
   }
   
   for (int k = 0; k < n; k++){
      for (int i = 0; i < n; i++){
      
         for (int j = 0; j < n; j++){
            
            mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
         }
      }
   }
   
   cout << "Short pair matrix" << endl;
   
   for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++){
         
         cout << mat[i][j] << " ";
      }
      cout << endl;
   }
   return 0;
}
