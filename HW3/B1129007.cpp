#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <queue>

class Graph {
public:
    std::vector<std::vector<int>> adjList;
    std::vector<std::vector<bool>> adjMatrix;
    int V; // Number of vertices

    Graph(int n) : V(n) {
        adjList.resize(V);
        adjMatrix.resize(V, std::vector<bool>(V, false));
    }

    void addEdge(int v1, int v2) {
        adjList[v1].push_back(v2);
        adjList[v2].push_back(v1);
        adjMatrix[v1][v2] = adjMatrix[v2][v1] = true;
    }

    void generateRandomGraph(int e) {
        if (e > V * (V - 1) / 2) {
            std::cout << "Invalid number of edges. Maximum number of edges for " << V << " vertices is " << V * (V - 1) / 2 << std::endl;
            return;
        }
        for (int i = 0; i < e; ++i) {
            int u = rand() % V;
            int v = rand() % V;
            while (u == v || adjMatrix[u][v]) {
                u = rand() % V;
                v = rand() % V;
            }
            addEdge(u, v);
        }
    }

    void printAdjList() {
        std::cout << "Adjacency List:" << std::endl;
        for (int i = 0; i < V; ++i) {
            std::cout << i << " --> ";
            for (int num : adjList[i]) {
                std::cout << num << " ";
            }
            std::cout << std::endl;
        }
    }

    void printAdjMatrix() {
        std::cout << "Adjacency Matrix:" << std::endl;
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                std::cout << adjMatrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

class DFS {
private:
    std::vector<bool> visited;
    Graph& graph;

public:
    DFS(Graph& g) : graph(g) {
        visited.resize(graph.V, false);
    }

    void dfs(int start) {
        visited[start] = true;
        std::cout << "DFS visits: " << start << std::endl;

        for (int adj : graph.adjList[start]) {
            if (!visited[adj]) {
                dfs(adj);
            }
        }
    }
};

class BFS {
private:
    std::vector<bool> visited;
    Graph& graph;

public:
    BFS(Graph& g) : graph(g) {
        visited.resize(graph.V, false);
    }

    void bfs(int start) {
        std::queue<int> queue;
        visited[start] = true;
        queue.push(start);

        while (!queue.empty()) {
            int current = queue.front();
            queue.pop();
            std::cout << "BFS visits: " << current << std::endl;

            for (int adj : graph.adjList[current]) {
                if (!visited[adj]) {
                    visited[adj] = true;
                    queue.push(adj);
                }
            }
        }
    }
};

int main() {
    srand(time(0));

    int n, e;
    std::cout << "Enter the number of nodes (n): ";
    std::cin >> n;
    std::cout << "Enter the number of edges (e): ";
    std::cin >> e;

    Graph graph(n);
    graph.generateRandomGraph(e);

    graph.printAdjMatrix();
    graph.printAdjList();

    DFS dfs(graph);
    std::cout << "DFS Execution Order:" << std::endl;
    dfs.dfs(0);

    BFS bfs(graph);
    std::cout << "BFS Execution Order:" << std::endl;
    bfs.bfs(0);

    return 0;
}

