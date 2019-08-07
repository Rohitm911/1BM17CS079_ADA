#include <iostream>
#include <algorithm>
using namespace std;

class maxVal{
    int n;
    int * arr;
    
    public:
        maxVal(int m, int* a){
            n = m;
            arr = new int[m];
            for (int i = 0; i < m; i++)
                arr[i] = a[i];
        }
        ~maxVal(){
            delete[] arr;
        }
        int getMaxVal(){
            int maxVal = arr[0];
            for (int i = 1; i < n; i++){
                maxVal = max(maxVal, arr[i]);
            }
            return maxVal;
        }
};

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    maxVal input(n,a);
    cout << input.getMaxVal() << endl;
    return 0;
}

