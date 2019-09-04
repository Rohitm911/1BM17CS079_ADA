#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<int>* edges, int start, unordered_set<int>& back, bool* visited){
    back.insert(start);
    visited[start] = true;
    for (int i = 0; i < edges[start].size(); ++i){
        int neighbour = edges[start][i];       
        if (back.find(neighbour) != back.end())
            return true;
        else{
            if (!visited[neighbour]){
                return dfs(edges, neighbour, back, visited);
            }
        }            
    }
    return false;
}

bool isCyclePresent(vector<int>* edges, int n){
    bool* visited = new bool[n];
    for (int i = 0; i < n; ++i){
        visited[i] = false;
    }
    unordered_set<int> back;
    return  dfs(edges, 0, back, visited);
        
    
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int>* edges = new vector<int>[n];
    for (int i = 0; i < m; ++i){
        int j, k;
        cin >> j >> k;
        edges[j - 1].push_back(k - 1);
    }
    
    if (isCyclePresent(edges, n)){
    cout << "cycle present " << endl;
    }else{
    cout <<"cycle not present " << endl;
    }
    return 0;
}
