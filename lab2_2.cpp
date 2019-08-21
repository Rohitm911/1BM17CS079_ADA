#include <iostream>
using namespace std;

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    int k;
    cin >> k;
    
    for (int i = 0; i < k; i++){
        for(int j = 0; j < n - 1 - i; j++){
            if (arr[j] > arr[j + 1])
                swap(arr[j],arr[j+1]);
        }
        cout << arr[n - 1 - i] <<" ";
    }
   
    return 0;
}
