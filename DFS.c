#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Maximum number of vertices

// Adjacency matrix to store the graph
int adj[MAX][MAX];
int visited[MAX];

// Function to initialize the graph
void initGraph(int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            adj[i][j] = 0;
        }
        visited[i] = 0;
    }
}

// Function to add an edge to the graph
void addEdge(int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1; // For undirected graph
}
// Function to perform DFS traversal
void DFS(int vertex, int vertices) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < vertices; i++) {
        if (adj[vertex][i] == 1 && !visited[i]) {
            DFS(i, vertices);
        }
    }
}
int main() {
    int vertices = 6; // Number of vertices

    // Initialize the graph
    initGraph(vertices);

    // Add edges to the graph
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 4);
    addEdge(3, 4);
    addEdge(3, 5);

    printf("DFS traversal starting from vertex 0:\n");
    DFS(0, vertices);

    return 0;
}
