#include<bits/stdc++.h>
using namespace std;


int minCoinChange(int* darr, int n, int k){

    int* coin = new int[k+1];
    
    for (int i = 0; i <= k; i++){
        if (i == 0)
            coin[i] = 0;
        else{
            coin[i] = INT_MAX;
             for (int j = 0; j < n && darr[j] <= i; j++){
                coin[i] = min(coin[i], 1 + coin[i-darr[j]]);
             }
        }
    }
    return coin[k];
}


int main(){
    
    int n;
    cin >> n;
    
    int* darr = new int[n];
    
    for (int i = 0; i < n; i++)
        cin >> darr[i];
        
    int k;
    cin >> k;
    cout << "min coin change for " << k << " is " << minCoinChange(darr, n, k) << endl;
}
