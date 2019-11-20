#include <bits/stdc++.h>
using namespace std;


int getMinV(bool* visi, int* dist, int n){

   int minV = -1;
   for (int i = 0; i < n; i++){
      if (!visi[i] && (minV == -1 || dist[i] < dist[minV]))
         minV = i;
   }
   return minV;
}

void dijkstra(int** edges, int n){

   bool visi[n];
   int dist[n];
   int parent[n];
   
   for (int i = 0; i < n; i++){
      visi[i] = false;
      dist[i] = INT_MAX;
   }
   
   dist[0] = 0;
   parent[0] = -1;
   
   for (int i = 0; i < n - 1; i++){
   
      int minV = getMinV(visi, dist, n);
      
      visi[minV] = true;
      
      for (int j = 0; j < n; j++){
      
         if (!visi[j] && edges[minV][j] && (dist[j] > dist[minV] + edges[minV][j])){
         
            dist[j] = dist[minV] + edges[minV][j];
            parent[j] = minV;
         }
      }
   }
   
   for (int i = 0; i < n; i++){
   
      cout << "Distance from Source (1) to "<< i+1 <<" : " << dist[i] << endl;
   }

}


int main(){

   int n;
   cin >> n;
   int** edges = new int*[n];
   for (int i = 0; i < n; i++){
   
      edges[i] = new int[n];
      
      for (int j = 0; j < n; j++)
         edges[i][j] = 0;
   }
   
   int m;
   cin >> m;
   for (int i = 0; i < m; i++){
   
      int v1, v2, w;
      cin >> v1 >> v2 >> w;
      edges[v1-1][v2-1] = w;
      edges[v2-1][v1-1] = w;
   }
   
   dijkstra(edges, n);
   return 0;
}
