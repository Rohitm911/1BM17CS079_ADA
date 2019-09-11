#include <bits/stdc++.h>
using namespace std;

void BFS(vector<int>* edges, int n){
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;
    queue<int> q;
    q.push(0);
    visited[0] = true;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        cout << front + 1 <<" ";
        for (int i = 0; i < edges[front].size(); i++){
            int neighbour = edges[front][i];
            if (!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour] = true;
            }
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int>* edges = new vector<int>[n];
    for (int i =0 ; i < m; i++){
        int j, k;
        cin >> j >> k;
        edges[j - 1].push_back(k - 1);
        edges[k - 1].push_back(j - 1);
    }
    BFS(edges, n);
    cout << endl;
    
    return 0;
}
