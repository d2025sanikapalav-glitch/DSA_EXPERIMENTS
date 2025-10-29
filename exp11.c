#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int adj[MAX][MAX];   // adjacency matrix
int visited[MAX];    // visited array
int n;               // number of vertices

// Function to create graph using adjacency matrix
void createGraph() {
    int edges, i, origin, destin;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize adjacency matrix to 0
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (origin destination):\n");
    for (i = 0; i < edges; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d%d", &origin, &destin);

        if (origin >= n || destin >= n || origin < 0 || destin < 0) {
            printf("Invalid edge! Please re-enter.\n");
            i--;
        } else {
            adj[origin][destin] = 1;  // directed edge
        }
    }

    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", adj[i][j]);
        printf("\n");
    }
}

// Breadth First Search (BFS)
void BFS(int start) {
    int queue[MAX], front = 0, rear = -1;
    int i, v;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    queue[++rear] = start;
    visited[start] = 1;

    printf("BFS Traversal starting from vertex %d: ", start);

    while (front <= rear) {
        v = queue[front++];
        printf("%d ", v);

        for (i = 0; i < n; i++) {
            if (adj[v][i] == 1 && visited[i] == 0) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

// Depth First Search (DFS)
void DFS_Recursive(int v) {
    int i;
    printf("%d ", v);
    visited[v] = 1;

    for (i = 0; i < n; i++) {
        if (adj[v][i] == 1 && visited[i] == 0)
            DFS_Recursive(i);
    }
}

void DFS(int start) {
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("DFS Traversal starting from vertex %d: ", start);
    DFS_Recursive(start);
    printf("\n");
}

// Main function
int main() {
    int choice, start;
    int graphCreated = 0;

    while (1) {
        printf("\n==== GRAPH TRAVERSAL MENU ====\n");
        printf("1. Create Graph (User Input)\n");
        printf("2. BFS Traversal\n");
        printf("3. DFS Traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createGraph();
                graphCreated = 1;
                break;

            case 2:
                if (!graphCreated) {
                    printf("Please create the graph first!\n");
                    break;
                }
                printf("Enter starting vertex for BFS (0 to %d): ", n - 1);
                scanf("%d", &start);
                if (start < 0 || start >= n)
                    printf("Invalid start vertex!\n");
                else
                    BFS(start);
                break;

            case 3:
                if (!graphCreated) {
                    printf("Please create the graph first!\n");
                    break;
                }
                printf("Enter starting vertex for DFS (0 to %d): ", n - 1);
                scanf("%d", &start);
                if (start < 0 || start >= n)
                    printf("Invalid start vertex!\n");
                else
                    DFS(start);
                break;

            case 4:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
