#include <bits/stdc++.h>
using namespace std;

bool isPartition(int* arr, int n, int sum){

   bool** dp = new bool*[sum/2 + 1];
   for (int i = 0; i <= sum/2; i++){
   
      dp[i] = new bool[n+1];
   }
   
   for (int i = 0; i <= n ;i++)
      dp[0][i] = true;
   
   for (int i = 0; i <= sum/2; i++)
      dp[i][0] = false;
      
   for (int i = 1; i <= sum/2; i++){
      
      for (int j = 1; j <= n; j++){
      
         dp[i][j] = dp[i][j-1];
         
         if (arr[j-1] <= i){
            dp[i][j] = dp[i][j] || dp[i - arr[j-1]][j-1];
         }
      }
   }
   
   return dp[sum/2][n];
}

int main(){

   int n;
   cin >> n;
   int arr[n];
   int sum = 0;
   for (int i = 0; i < n; i++){
      cin >> arr[i];
      sum += arr[i];
   }
   
   if (sum&1)
      cout << "No" << endl;
   else{
      
     isPartition(arr, n, sum) ? cout << "Yes" << endl : cout << "No" << endl;
   }
   return 0;
}
