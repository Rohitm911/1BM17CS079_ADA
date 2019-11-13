#include<bits/stdc++.h>
using namespace std;

int getMinWeight(int* weight, int n, bool* visited){
    
    int minV = -1;
    for (int i = 0; i < n; i++){
        if (!visited[i] && (minV == -1 || weight[minV] > weight[i])){
            minV = i;
        }
    }
    return minV;
}

void prims(int** edges, int n){

    bool* visited = new bool[n];
    int* weight = new int[n];
    int* parent = new int[n];
    for (int i = 0 ; i < n; i++){
        visited[i] = false;
        weight[i] = INT_MAX;
    }
    
    parent[0] = -1;
    weight[0] = 0;
    
    for (int i = 0; i < n-1; i++){
        
        int minv = getMinWeight(weight, n, visited);
        visited[minv] = true;
        for (int j = 0; j < n; j++){
            
            if (edges[minv][j] && !visited[j]){
            
                if (weight[j] > edges[minv][j]){
                
                    weight[j] = edges[minv][j];
                    parent[j] = minv;
                 }
            }
        }
    }
    
    for (int i = 1; i < n; i++){
    
        if (parent[i] < i)
            cout << parent[i] + 1 << " -- " << i + 1 << " : " << weight[i] << endl;
        else
            cout << i + 1<< " -- " << parent[i] + 1<< " : " << weight[i] << endl;
    }
}

int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    
    int** edges = new int*[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j< n; j++)
            edges[i][j] = 0;
    }
    for (int i = 0; i < m; i++){
        int f,s,w;
        cin >> f >> s >> w;
        edges[f - 1][s - 1] = w;
        edges[s - 1][f - 1] = w;
    }
    prims(edges, n);
    return 0;
}
