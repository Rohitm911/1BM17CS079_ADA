#include <iostream>
#include <fstream>
using namespace std;

class lab0Additional{
    int n;
    int *arr;
    public:
        lab0Additional(int m, int *a){
            n = m;
            arr = new int[m];
            for (int i = 0;  i < m; i++)
                arr[i] = a[i];
        }

        ~lab0Additional(){
            delete[] arr;
        }

        int isValuePresent(int k){
            int left = 0;
            int right = n - 1;
            int ans = -1;
            while(left <= right){
                int mid = left + (right - left) / 2;
                if (arr[mid] == k){
                    ans = 1;
                    return ans;
                }else if(arr[mid] > k){
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }
            return ans;
        }
};

int main(){
    freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i= 0; i < n; i++)
            cin >> arr[i];

        lab0Additional input(n, arr);
        cout << input.isValuePresent(k) << endl;
    }
    return 0;
}