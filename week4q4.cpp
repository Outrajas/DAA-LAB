#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& s) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) dfs(neighbor, adj, visited, s);
    }
    s.push(node);
}

void topologicalSortDFS(int V, vector<vector<int>>& adj) {
    vector<bool> visited(V, false);
    stack<int> s;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) dfs(i, adj, visited, s);
    }

    cout << "Topological Sort (DFS): ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    int V = 6;
    vector<vector<int>> adj = {
        {}, {0}, {0}, {1, 2}, {3}, {3, 4}
    };

    topologicalSortDFS(V, adj);
    return 0;
}

