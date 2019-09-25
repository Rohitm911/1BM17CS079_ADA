#include <bits/stdc++.h>
using namespace std;


void topologicalSort(int** edges,int n, int* inDegree){
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (edges[i][j]){
                inDegree[j]++;
            }
        }
    }
    int count = 0;  
    bool printed[n];
    memset(printed, false, sizeof(printed));
  
    while(count != n){
        for (int i = 0; i < n; i++){
            if (inDegree[i] == 0 && printed[i] == false){
                cout << i + 1 << " ";
                printed[i] = true;
                count++;
                for (int j = 0; j < n; j++){
                    if (edges[i][j]){
                        inDegree[j]--;
                        edges[i][j] = 0;
                    }
                }
            }
        }
    }  
    
    cout<< endl;
} 

int main(){
    int n, m;
    cout << "Enter the number of vertex : ";
    cin >> n;
    cout << "Enter the number of edges : ";
    cin >> m;
    int **edges = new int*[n];
    for (int i = 0; i < n; i++){
        edges[i] = new int[n];
        for (int j = 0; j < n; j++){
            edges[i][j] = 0;
        }
    }
    cout << "Enter the vertices who has edges between them :" << endl;
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        edges[a-1][b-1] = 1;
    }
    
    int inDegree[n];
    memset(inDegree, 0, sizeof(inDegree));    
   // for (int i  = 0; i < n; i++)
   
    topologicalSort(edges, n, inDegree);
    return 0;
}
