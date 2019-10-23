#include <bits/stdc++.h>
using namespace std;

int bitonicResult(int* arr, int n){
    int* res = new int[n];
    for (int i = 0; i < n; i++){
        res[i] = 1;
        for (int j = i - 1; j >=0; j--){
            if (arr[i] > arr[j]){
                int possibleAns = res[j] + 1;
                res[i] = max(possibleAns, res[i]);
            }
        }
    }
    
    int* res1 = new int[n];
    for (int i = n - 1; i >= 0; i--){
        res1[i] = 1;
        for (int j = i + 1; j < n; j++){
            if (arr[i] > arr[j]){
                int possibleAns = res1[j] + 1;
                res1[i] = max(possibleAns, res1[i]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++){
        ans = max(ans, res[i] + res1[i] - 1);
    }
    return ans;
}

int main(){

    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << bitonicResult(arr, n) << endl;
    return 0;
}