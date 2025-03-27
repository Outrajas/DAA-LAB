#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Structure to represent a disjoint set
struct DisjointSet {
    int *parent, *rank;
    int n;
    
    // Constructor to initialize the disjoint set
    DisjointSet(int n) {
        this->n = n;
        parent = new int[n];
        rank = new int[n];
        
        // Initialize each node as a separate set with rank 0
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    
    // Destructor to free up memory
    ~DisjointSet() {
        delete[] parent;
        delete[] rank;
    }
    
    // Find the representative (root) of a set with path compression
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // Path compression
        }
        return parent[x];
    }
    
    // Union of two sets based on rank
    void Union(int x, int y) {
        // Find the representatives (roots) of x and y
        int rootX = find(x);
        int rootY = find(y);
        
        // If already in same set, do nothing
        if (rootX == rootY) return;
        
        // Attach smaller rank tree under root of higher rank tree
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            // If ranks are same, make one as root and increment its rank
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
};

// Comparison function to sort edges by weight
bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}

// Function to construct MST using Kruskal's algorithm
void kruskalMST(Edge* edges, int E, int V) {
    // Result array to store the MST
    Edge* result = new Edge[V-1];
    
    // Sort all edges in non-decreasing order of their weight
    sort(edges, edges + E, compareEdges);
    
    // Create a disjoint set
    DisjointSet ds(V);
    
    // Initialize index for result array
    int e = 0;  // Index for result[] array
    
    // Index for sorted edges array
    int i = 0;
    
    // Total weight of MST
    int totalWeight = 0;
    
    // Process all sorted edges one by one
    while (e < V - 1 && i < E) {
        // Get the smallest edge
        Edge next_edge = edges[i++];
        
        int x = ds.find(next_edge.src);
        int y = ds.find(next_edge.dest);
        
        // If including this edge doesn't cause a cycle, include it in result
        if (x != y) {
            result[e++] = next_edge;
            ds.Union(x, y);
            totalWeight += next_edge.weight;
        }
        // Else discard the edge
    }
    
    // Print the contents of result[] to display the MST
    cout << "Edges in the Minimum Spanning Tree:" << endl;
    for (i = 0; i < e; ++i) {
        cout << result[i].src << " -- " << result[i].dest << " : " << result[i].weight << endl;
    }
    cout << "Total weight of MST: " << totalWeight << endl;
    
    delete[] result;
}

// Main function to demonstrate Kruskal's algorithm
int main() {
    // Example graph
    int V = 4;  // Number of vertices
    int E = 5;  // Number of edges
    Edge* edges = new Edge[E];
    
    // Add edges: (u, v, w) where u and v are vertices and w is the weight
    // Edge 0-1
    edges[0].src = 0;
    edges[0].dest = 1;
    edges[0].weight = 2;
    
    // Edge 0-3
    edges[1].src = 0;
    edges[1].dest = 3;
    edges[1].weight = 1;
    
    // Edge 1-2
    edges[2].src = 1;
    edges[2].dest = 2;
    edges[2].weight = 3;
    
    // Edge 1-3
    edges[3].src = 1;
    edges[3].dest = 3;
    edges[3].weight = 3;
    
    // Edge 2-3
    edges[4].src = 2;
    edges[4].dest = 3;
    edges[4].weight = 4;
    
    cout << "Example 1:" << endl;
    kruskalMST(edges, E, V);
    
    delete[] edges;
    
    // Example 2: Larger graph
    V = 9;
    E = 14;
    edges = new Edge[E];
    
    // Add edges for example 2
    edges[0].src = 0; edges[0].dest = 1; edges[0].weight = 4;
    edges[1].src = 0; edges[1].dest = 7; edges[1].weight = 8;
    edges[2].src = 1; edges[2].dest = 2; edges[2].weight = 8;
    edges[3].src = 1; edges[3].dest = 7; edges[3].weight = 11;
    edges[4].src = 2; edges[4].dest = 3; edges[4].weight = 7;
    edges[5].src = 2; edges[5].dest = 5; edges[5].weight = 4;
    edges[6].src = 2; edges[6].dest = 8; edges[6].weight = 2;
    edges[7].src = 3; edges[7].dest = 4; edges[7].weight = 9;
    edges[8].src = 3; edges[8].dest = 5; edges[8].weight = 14;
    edges[9].src = 4; edges[9].dest = 5; edges[9].weight = 10;
    edges[10].src = 5; edges[10].dest = 6; edges[10].weight = 2;
    edges[11].src = 6; edges[11].dest = 7; edges[11].weight = 1;
    edges[12].src = 6; edges[12].dest = 8; edges[12].weight = 6;
    edges[13].src = 7; edges[13].dest = 8; edges[13].weight = 7;
    
    cout << "\nExample 2:" << endl;
    kruskalMST(edges, E, V);
    
    delete[] edges;
    
    return 0;
}
