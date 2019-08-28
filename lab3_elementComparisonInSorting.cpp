#include <iostream>
using namespace std;

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

int SelectionSortCompCount(int* arr, int n){
    int min;
    int count = 0;
    for (int i = 0; i < n - 1; i++){
        min = i;
        for (int j = i + 1; j < n; j++){
            if (arr[j] < arr[min]){
                min = j;
                count++;
            }else{
                count++;
            }
                
        }
        swap(arr[i], arr[min]);
    }
    
    return count;
}

int bubbleSortCompCount(int* arr, int n){
    int count = 0;
    for (int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                swap(arr[j], arr[j+1]);
                count++;
            }else{
                count++;
            }
        }
    }
    
    return count;
}


int mergeSortedArray(int* arr, int start, int mid, int end){
    int* temp = new int[end - start + 1];
    int count = 0;
    int i = start, j = mid + 1;
    int k = 0;
    while(i <= mid && j <= end){
        if (arr[i] <= arr[j]){
            temp[k++] = arr[i++];
            count++;
        }
        else{
            temp[k++] = arr[j++];
            count++;
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
    return count;
}

int mergeSort(int* arr, int start, int end){
  
    if (start < end){
        int mid = (start + end) / 2;
        int leftAns = mergeSort(arr, start, mid);
        int rightAns = mergeSort(arr, mid + 1, end);
        int mergingAns = mergeSortedArray(arr, start, mid, end);
        return leftAns + rightAns + mergingAns;
    }
    return 0;
}

int main(){
    
    int n;
    cin >> n;
    int arr1[n],arr2[n],arr3[n];
    for (int i = 0; i < n; i++){
        cin >> arr1[i];
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }
    
    cout << "comparison count for selection sort is : " << SelectionSortCompCount(arr1, n) << endl;
    cout << "comparison count for bubble sort is : " << bubbleSortCompCount(arr2, n) << endl;
    cout << "comparison count for merge sort is : "<< mergeSort(arr3, 0, n - 1) << endl;
    return 0;
}
