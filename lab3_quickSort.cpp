#include <iostream>
using namespace std;

void swapElement(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

int getPartIdx(int* arr, int start, int end){
    int count  = 0;
    for (int i = start; i <= end; i++){
        if (arr[i] < arr[start]){
            count++;
        }
    }
    int partIdx = start + count;
    swapElement(arr[partIdx], arr[start]);
    int i = start, j = end;
    while(i < partIdx && j > partIdx){
        if (arr[i] < arr[partIdx])
            i++;
        else if (arr[j] >= arr[partIdx])
            j--;
        else{
            swapElement(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    return partIdx;
}

void quickSortHelper(int* arr, int start, int end){
    if (start <= end){
        int partIdx = getPartIdx(arr, start, end);
        quickSortHelper(arr, start, partIdx - 1);
        quickSortHelper(arr, partIdx + 1, end);
    }
}

void quickSort(int* arr, int n){
    quickSortHelper(arr, 0, n - 1);
}

int main(){
    int n;
    cout <<"Enter the no. of element : "<<endl;
    cin >> n;
    int arr[n];
    cout << "Enter the Elements : " << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    quickSort(arr, n);
    //cout << endl;
    for(int i = 0; i < n; i++)
        cout << arr[i] <<" ";
        cout << endl;
    return 0;
}
