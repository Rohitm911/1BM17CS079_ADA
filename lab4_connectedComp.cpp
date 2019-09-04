#include <bits/stdc++.h>
using namespace std;

void DFS(vector<int>* edges, int start, bool* visited){
    visited[start] = true;
    cout << start + 1 <<" ";
    for (int i = 0; i < edges[start].size(); ++i){
        int neighour = edges[start][i];
        if (!visited[neighour]){
            DFS(edges, neighour, visited);
        }
    }
}

void printConntComp(vector<int>* edges, int n){
    bool* visited = new bool[n];
    for (int i = 0; i < n; ++i)
        visited[i] = false;
    for (int i = 0; i < n; ++i){
        if (!visited[i]){
            DFS(edges,i,visited);
            cout << endl;
        }
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<int>* edges = new vector<int>[n];
    for (int i = 0; i < m; ++i){
        int j, k;
        cin >> j >> k;
        edges[j-1].push_back(k-1);
        edges[k-1].push_back(j-1);
    }
    printConntComp(edges, n);
    return 0;
}
