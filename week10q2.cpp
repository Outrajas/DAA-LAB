#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Edge { // 'Edge' structure is defined
    int src, dest, weight;
};

class DisjointSet {
public:
    vector<int> parent, rank;
    
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int i) {
        if (i != parent[i])
            parent[i] = find(parent[i]);
        return parent[i];
    }

    void unionSets(int x, int y) {
        int rootX = find(x), rootY = find(y);
        
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

bool compare(Edge a, Edge b) { // Comparison function for sorting edges by weight
    return a.weight < b.weight;
}

void kruskalMST(vector<Edge>& edges, int V) { // Function to implement Kruskal's algorithm
    DisjointSet ds(V);
    sort(edges.begin(), edges.end(), compare);
    
    int mstWeight = 0;
    vector<Edge> mst;

    for (auto edge : edges) {
        int u = edge.src;
        int v = edge.dest;
        int weight = edge.weight;

        // If including this edge doesn't form a cycle
        if (ds.find(u) != ds.find(v)) {
            mst.push_back(edge);
            mstWeight += weight;
            ds.unionSets(u, v);
        }
    }

    // Print the MST
    cout << "Edges in the MST:\n";
    for (auto edge : mst) {
        cout << edge.src << " - " << edge.dest << " \tWeight: " << edge.weight << endl;
    }
    cout << "Minimum Cost of Spanning Tree: " << mstWeight << endl;
}

int main() {
    int V = 4; // Number of vertices (Ensure this matches your graph)
    vector<Edge> edges = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5},
        {1, 3, 15}, {2, 3, 4}
    };

    kruskalMST(edges, V);
    return 0;
}

