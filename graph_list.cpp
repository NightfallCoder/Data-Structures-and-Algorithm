#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ,m ;
    cout<<"Enter nodes (n): ";
    cin>>n;
    cout<<"Enter edges (m): ";
    cin>>m;
    vector<int>adj[n+1];
    //for undirected graph
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u); //for directed graph we will remove this line
    }
     cout << "Adjacency List:" << endl;
    for (int u = 1; u <= n; u++) {
        cout << "Node " << u << ": ";
        for (int v : adj[u]) {
            cout << v << " ";
        }
        cout << endl;
    }
}