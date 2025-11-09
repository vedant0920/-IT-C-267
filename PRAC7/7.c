#include <stdio.h>
#define MAX 9

int graph[10][10] = {
    {0},
    {0,0,1,0,1,0,0,0,0,0},
    {0,1,0,1,0,1,0,0,0,0},
    {0,0,1,0,0,0,1,0,0,0},
    {0,1,0,0,0,1,0,1,0,0},
    {0,0,1,0,1,0,1,0,1,0},
    {0,0,0,1,0,1,0,0,0,1},
    {0,0,0,0,1,0,0,0,1,0},
    {0,0,0,0,0,1,0,1,0,1},
    {0,0,0,0,0,0,1,0,1,0}
};

void bfs(int start) {
    int q[20], visited[10] = {0};
    int front = 0, rear = 0;
    q[rear++] = start;
    visited[start] = 1;
    printf("BFS: ");
    while (front < rear) {
        int v = q[front++];
        printf("%d ", v);
        for (int i = 1; i <= MAX; i++)
            if (graph[v][i] && !visited[i]) {
                q[rear++] = i;
                visited[i] = 1;
            }
    }
    printf("\n");
}

void dfs(int start) {
    int stack[20], visited[10] = {0};
    int top = -1;
    stack[++top] = start;
    printf("DFS: ");
    while (top != -1) {
        int v = stack[top--];
        if (!visited[v]) {
            printf("%d ", v);
            visited[v] = 1;
            for (int i = MAX; i >= 1; i--)
                if (graph[v][i] && !visited[i])
                    stack[++top] = i;
        }
    }
    printf("\n");
}

int main() {
    bfs(1);
    dfs(1);
    return 0;
}
