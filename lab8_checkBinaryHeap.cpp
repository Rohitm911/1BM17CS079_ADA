#include <bits/stdc++.h>
using namespace std;

bool checkMaxHeap(int* arr, int n){

    for (int i = 0; i < (n/2)-1; i++){

        if (arr[i] < arr[2*i+1])
            return false;

        if (2*i+2 < n && arr[i] < arr[2*i + 2])
            return false;
    }
    return true;
}

int main(){

    int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    checkMaxHeap(arr, n) ? cout << "Yes" : cout << "No";
    cout << endl;
}