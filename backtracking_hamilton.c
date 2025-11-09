ASS – 6 A)
#include <stdio.h>
#include <stdbool.h>

#define MAX 10   // maximum number of vertices (you can increase if needed)

// Function to check if vertex v can be added at index 'pos' in the Hamiltonian Cycle
bool isSafe(int v, int graph[MAX][MAX], int path[], int pos, int V) {
    // 1. Check if current vertex is adjacent to the previous vertex
    if (graph[path[pos - 1]][v] == 0)
        return false;

    // 2. Check if vertex has already been included
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

// Recursive utility function to solve the Hamiltonian Cycle problem
bool hamCycleUtil(int graph[MAX][MAX], int path[], int pos, int V) {
    // Base case: all vertices are included
    if (pos == V) {
        // Check if the last vertex connects back to the first vertex
        return (graph[path[pos - 1]][path[0]] == 1);
    }

    // Try different vertices as the next candidate
    for (int v = 1; v < V; v++) {
        if (isSafe(v, graph, path, pos, V)) {
            path[pos] = v;

            // Recur to construct the rest of the path
            if (hamCycleUtil(graph, path, pos + 1, V))
                return true;

            // Backtrack if adding v doesn't lead to a solution
            path[pos] = -1;
        }
    }

    return false;
}

// Function to solve the Hamiltonian Cycle problem using Backtracking
bool hamCycle(int graph[MAX][MAX], int V) {
    int path[MAX];

    // Initialize path[] as -1
    for (int i = 0; i < V; i++)
        path[i] = -1;

    // Start from vertex 0
    path[0] = 0;

    if (!hamCycleUtil(graph, path, 1, V)) {
        printf("\nNo Hamiltonian Cycle exists for the given graph.\n");
        return false;
    }

    // Print the Hamiltonian Cycle
    printf("\nHamiltonian Cycle found:\n");
    for (int i = 0; i < V; i++)
        printf("%d ", path[i]);
    printf("%d\n", path[0]); // to complete the cycle

    return true;
}

// Driver code
int main() {
    int V;
    int graph[MAX][MAX];

    printf("Enter number of vertices (max %d): ", MAX);
    scanf("%d", &V);

    printf("\nEnter the adjacency matrix (%d x %d):\n", V, V);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++)
            printf("%d ", graph[i][j]);
        printf("\n");
    }

    hamCycle(graph, V);

    return 0;
}