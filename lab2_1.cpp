#include <iostream>
using namespace std;

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

int main(){
    int n,k;
    cin >> n; 
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cin>> k;
    int min;
    for (int i = 0; i < k; i++){
        min = i;
        for (int j = i + 1; j < n; j++){
            if (arr[min] > arr[j]){
                min = j;
            }
        }
        swap(arr[min],arr[i]);
    }
    
    cout << arr[k-1] << endl;
    
    return 0;
}
