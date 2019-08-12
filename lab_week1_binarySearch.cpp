#include <iostream>
using namespace std;

int lowerBoundResult(int arr[], int n, int k){
	int start = 0;
	int end = n - 1;
	int lowerBoundIndex = -1;
	while(start <= end){
		int mid = (start + end) / 2;
		if (arr[mid] == k){
			lowerBoundIndex = mid;
			end = mid - 1;
		}else if(arr[mid] > k){
			end = mid - 1;
		}else{
			start = mid + 1;
		}
	}
	return lowerBoundIndex;
}

int upperBoundResult(int arr[], int n, int k){
	int start = 0;
	int end = n - 1;
	int upperBoundIndex = -1;
	while(start <= end){
		int mid = (start + end) / 2;
		if (arr[mid] == k){
			upperBoundIndex = mid;
			start = mid + 1;
		}else if(arr[mid] > k){
			end = mid - 1;
		}else{
			start = mid + 1;
		}
	}
	return upperBoundIndex;
}

int main() {
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int k;
	cin >> k;
	int lowerBound = lowerBoundResult(arr, n, k);
	int upperBound = upperBoundResult(arr, n, k);
	int count = upperBound - lowerBound + 1;
	if (lowerBound == -1)
		count = 0;
	cout << lowerBound << " " << upperBound <<" " << count << endl;
	return 0;
}
