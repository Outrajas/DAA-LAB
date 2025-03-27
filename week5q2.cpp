#include <iostream>
#include <climits>

using namespace std;

// Number of vertices in the graph
#define V 9

// Function to find the vertex with minimum key value
// from the set of vertices not yet included in MST
int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, min_index;
  
    for (int v = 0; v < V; v++) {
        if (mstSet[v] == false && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
  
    return min_index;
}

// Function to print the constructed MST
void printMST(int parent[], int graph[V][V]) {
    cout << "Edge \tWeight\n";
    int totalCost = 0;
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << endl;
        totalCost += graph[i][parent[i]];
    }
    cout << "Total cost of MST: " << totalCost << endl;
}

// Function to implement Prim's MST algorithm
void primMST(int graph[V][V]) {
    int parent[V];  // Array to store constructed MST
    int key[V];     // Key values used to pick minimum weight edge
    bool mstSet[V]; // To represent set of vertices included in MST
  
    // Initialize all keys as INFINITE
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }
  
    // Always include first vertex in MST
    // Make key 0 so that this vertex is picked as first vertex
    key[0] = 0;
    parent[0] = -1; // First node is always root of MST
  
    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(key, mstSet);
  
        // Add the picked vertex to the MST Set
        mstSet[u] = true;
  
        // Update key value and parent index of the adjacent vertices of the picked vertex
        // Consider only those vertices which are not yet included in MST
        for (int v = 0; v < V; v++) {
            // graph[u][v] is non zero only for adjacent vertices of m
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
  
    // Print the constructed MST
    printMST(parent, graph);
}

// Function to create a graph with a fixed number of vertices
void createGraph(int graph[V][V], int vertices) {
    // Initialize all edges to 0 (no edge)
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph[i][j] = 0;
        }
    }
}

// Function to run the algorithm for a sample graph
void runExample1() {
    int graph[V][V] = {0};
    
    // We'll use only 4 vertices for this example
    // Add edges to graph
    // Edge between 0-1 with weight 2
    graph[0][1] = 2;
    graph[1][0] = 2;
    
    // Edge between 0-3 with weight 1
    graph[0][3] = 1;
    graph[3][0] = 1;
    
    // Edge between 1-2 with weight 3
    graph[1][2] = 3;
    graph[2][1] = 3;
    
    // Edge between 1-3 with weight 3
    graph[1][3] = 3;
    graph[3][1] = 3;
    
    // Edge between 2-3 with weight 4
    graph[2][3] = 4;
    graph[3][2] = 4;
    
    cout << "Example 1 (4 vertices):" << endl;
    primMST(graph);
}

// Function to run the algorithm for a larger graph
void runExample2() {
    int graph[V][V] = {0};
    
    // Add edges to graph
    graph[0][1] = 4;
    graph[1][0] = 4;
    
    graph[0][7] = 8;
    graph[7][0] = 8;
    
    graph[1][2] = 8;
    graph[2][1] = 8;
    
    graph[1][7] = 11;
    graph[7][1] = 11;
    
    graph[2][3] = 7;
    graph[3][2] = 7;
    
    graph[2][5] = 4;
    graph[5][2] = 4;
    
    graph[2][8] = 2;
    graph[8][2] = 2;
    
    graph[3][4] = 9;
    graph[4][3] = 9;
    
    graph[3][5] = 14;
    graph[5][3] = 14;
    
    graph[4][5] = 10;
    graph[5][4] = 10;
    
    graph[5][6] = 2;
    graph[6][5] = 2;
    
    graph[6][7] = 1;
    graph[7][6] = 1;
    
    graph[6][8] = 6;
    graph[8][6] = 6;
    
    graph[7][8] = 7;
    graph[8][7] = 7;
    
    cout << "\nExample 2 (9 vertices):" << endl;
    primMST(graph);
}

// Main function to demonstrate the algorithm
int main() {
    // Run example with 4 vertices
    runExample1();
    
    // Run example with 9 vertices
    runExample2();
    
    return 0;
}
