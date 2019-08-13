#include <iostream>
using namespace std;

int binarySearchSqrt(int x){
	int start = 0;
	int end = x/2;
	int ans;
	while(start <= end){
		int mid = (start + end) / 2;
		if (mid*mid == x){
			return mid;
		}else if(mid*mid < x){
			ans = mid;
			start = mid + 1;
		}else{
			end = mid - 1;
		}
	}
	return ans;
}

int main() {
	int x;
	cin >> x;
	cout << binarySearchSqrt(x) <<endl;
	return 0;
}
