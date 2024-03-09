#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> bfsOfGraph(int start_node, vector<vector<int>> adj) {
        int n = adj.size(); // Get the size from the vector
        int vis[n] = {0};
        vector<int> bfsOutput;
        queue<int> q;
        q.push(start_node);
        vis[start_node] = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            bfsOutput.push_back(node);

            for (auto it : adj[node]) {
                if (!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return bfsOutput;
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
    vector<int> bfs = sol.bfsOfGraph(start_node, adj);

    cout << "BFS Traversal: ";
    for (int node : bfs) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}