#include <iostream>
using namespace std;

int findPivot(int* arr, int start, int end){
    if (start < end){
        int mid = (start + end) / 2;
        if (arr[mid] > arr[mid + 1])
            return mid;
        int findPivotLeft = findPivot(arr, start, mid);
        int findPivotRight = findPivot(arr, mid + 1, end);
        if (findPivotLeft == -1 && findPivotRight == -1){
            return -1;
        }
        if (findPivotLeft == -1)
            return findPivotRight;
        if (findPivotRight == -1)
            return findPivotLeft;
    }
    return -1;
}

int find(int* arr, int start, int end, int k){
    if (start <= end){
        int mid = (start + end) / 2;
        if (arr[mid] == k)
            return mid;
        if (arr[mid] < k ){
            return find(arr, mid + 1, end, k);
        }
        if (arr[mid] > k){
            return find(arr, start, mid - 1, k);
        }
    }
    return -1;
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
    int pivot = findPivot(arr, 0, n - 1);
    //cout << pivot << endl;
    int found1 = find(arr, 0, pivot, k);
    int found2 = find(arr, pivot + 1, n - 1,k);
    if (found1 == -1 && found2 == -1)
        cout << "Not Found" << endl;
    else if (found1 == -1)
        cout << "Found at index " << found2 << endl;
    else
        cout << "Found at index " << found1 << endl;
    return 0;
}
