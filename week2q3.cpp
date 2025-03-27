#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void DFS(vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<bool> visited(n, false);
    stack<int> s;
    
    vector<int> pushOrder, popOrder;

    s.push(start);
    while (!s.empty()) {
        int node = s.top();
        s.pop();
        
        if (!visited[node]) {
            visited[node] = true;
            pushOrder.push_back(node);
            
            for (auto it = graph[node].rbegin(); it != graph[node].rend(); ++it) {
                if (!visited[*it])
                    s.push(*it);
            }
        }
        popOrder.push_back(node);
    }

    cout << "Push Order: ";
    for (int node : pushOrder) cout << node << " ";
    cout << "\nPop Order: ";
    for (int node : popOrder) cout << node << " ";
}

int main() {
    vector<vector<int>> graph = {{1, 2}, {0, 3, 4}, {0, 4}, {1, 5}, {1, 2, 5}, {3, 4}};
    cout << "DFS Traversal:\n";
    DFS(graph, 0);
    return 0;
}

