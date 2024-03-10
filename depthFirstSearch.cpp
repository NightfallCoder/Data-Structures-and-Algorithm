#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    void dfs(int node,vector<vector<int>> adj,int vis[],vector<int>&lis){
        vis[node]=1;
        lis.push_back(node);
        //traverse node's neighbours
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis,lis);
            }
        }
    }
public:
    vector<int> dfsOfGraph(int start_node, vector<vector<int>> adj) {
        int n = adj.size(); // Get the size from the vector
        int vis[n] = {0};
        int start=start_node;
        vector<int>lis;
    dfs(start,adj,vis,lis);
    return lis;
    }
};

int main() {
    int n, m;
    cout << "Enter nodes (n): ";
    cin >> n;
    cout << "Enter edges (m): ";
    cin >> m;
    // Use vector<vector<int>> for dynamic allocation
    vector<vector<int>> adj(n + 1);

    cout << "Enter edges:" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // for undirected graph
    }
    cout << "Adjacency List:" << endl;
    for (int u = 1; u <= n; u++) {
        cout << "Node " << u << ": ";
        for (int v : adj[u]) {
            cout << v << " ";
        }
        cout << endl;
    }

    int start_node;
    cout << "Enter the node to start BFS traversal from: ";
    cin >> start_node;

    Solution sol;
    vector<int> dfs = sol.dfsOfGraph(start_node, adj);

    cout << "BFS Traversal: ";
    for (int node : dfs) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}