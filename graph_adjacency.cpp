#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m; //n=nodes m=edge
    cout<<"Enter nodes (n): ";
    cin>>n;
    cout<<"Enter edges (m): ";
    cin>>m;
    //1 based indexing if 0 based indexing then nxm
    //graph here
    int adj[n+1][n+1]={0};
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }
    cout << "Adjacency Matrix:" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}