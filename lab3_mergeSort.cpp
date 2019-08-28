#include <iostream>
using namespace std;

void mergeSortedArray(int* arr, int start, int mid, int end){
    int* temp = new int[end - start + 1];
    
    int i = start, j = mid + 1;
    int k = 0;
    while(i <= mid && j <= end){
        if (arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
        }
    }
    
    while(i <= mid){
        temp[k++] = arr[i++];
    }
    
    while(j <= end){
        temp[k++] = arr[j++];
    }
    
    k = 0;
    for (int i = start; i <= end; i++){
        arr[i] = temp[k++];
    }
    
    delete[] temp;
}

void mergeSort(int* arr, int start, int end){
    if (start < end){
        int mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        mergeSortedArray(arr, start, mid, end);
    }
}

int main(){

    int n;
    cout <<"Enter the number of Elements : "<<endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements : " << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++){
        cout << arr[i] <<" ";
    }
    cout << endl;
    return 0;
}
