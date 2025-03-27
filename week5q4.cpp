#include <iostream>
#include <climits>
#include <cstring>

using namespace std;

// Number of vertices in the graph
#define V 9

// Function to find the vertex with minimum distance value
// from the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[]) {
    // Initialize min value
    int min = INT_MAX, min_index;
    
    for (int v = 0; v < V; v++) {
        if (sptSet[v] == false && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    
    return min_index;
}

// Function to print the constructed distance array
void printSolution(int dist[], int parent[], int src) {
    cout << "Vertex \t Distance from Source \t Path" << endl;
    for (int i = 0; i < V; i++) {
        cout << i << " \t\t " << dist[i] << "\t\t ";
        
        // Print the path
        int j = i;
        if (j != src && dist[j] != INT_MAX) {
            int path[V];
            int path_index = 0;
            
            while (j != src) {
                path[path_index++] = j;
                j = parent[j];
            }
            path[path_index] = src;
            
            // Print the path in reverse order
            for (int k = path_index; k >= 0; k--) {
                cout << path[k];
                if (k > 0) cout << " -> ";
            }
        } else if (j == src) {
            cout << src;
        } else {
            cout << "No path";
        }
        cout << endl;
    }
}

// Function to implement Dijkstra's algorithm
void dijkstra(int graph[V][V], int src) {
    // The output array. dist[i] will hold the shortest
    // distance from src to i
    int dist[V];
    
    // Array to store shortest path tree
    int parent[V];
    
    // sptSet[i] will be true if vertex i is included in the
    // shortest path tree or shortest distance from src to i is finalized
    bool sptSet[V];
    
    // Initialize all distances as INFINITE and sptSet[] as false
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
        parent[i] = -1;
    }
    
    // Distance of source vertex from itself is always 0
    dist[src] = 0;
    
    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices
        // not yet processed. u is always equal to src in the first iteration.
        int u = minDistance(dist, sptSet);
        
        // Mark the picked vertex as processed
        sptSet[u] = true;
        
        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++) {
            // Update dist[v] only if:
            // 1. There is an edge from u to v, 
            // 2. Vertex v is not in sptSet,
            // 3. Distance through u is smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && 
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }
    
    // Print the constructed distance array
    printSolution(dist, parent, src);
}

int main() {
    // Example graph in adjacency matrix representation
    int graph[V][V] = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };
    
    // Source vertex
    int src = 0;
    
    cout << "Dijkstra's Algorithm implementation" << endl;
    cout << "Finding shortest paths from vertex " << src << " to all other vertices:" << endl;
    
    // Call Dijkstra's algorithm
    dijkstra(graph, src);
    
    return 0;
}
