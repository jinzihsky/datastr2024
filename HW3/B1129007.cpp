#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class AdjMatrixGraph {
private:
    int V;
    std::vector<std::vector<bool>> adjMatrix;

public:
    AdjMatrixGraph(int vertices) : V(vertices) {
        adjMatrix.resize(V, std::vector<bool>(V, false));
    }

    void addEdge(int u, int v) {
        adjMatrix[u][v] = adjMatrix[v][u] = true;
    }

    bool hasEdge(int u, int v) {
        return adjMatrix[u][v];
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

class AdjListGraph {
private:
    int V;
    std::vector<std::vector<int>> adjList;

public:
    AdjListGraph(int vertices) : V(vertices) {
        adjList.resize(V);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void printAdjList() {
        std::cout << "Adjacency List:" << std::endl;
        for (int i = 0; i < V; ++i) {
            std::cout << i << " --> ";
            for (int j = 0; j < adjList[i].size(); ++j) {
                std::cout << adjList[i][j] << " ";
            }
            std::cout << std::endl;
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

    if (e > n * (n - 1) / 2) {
        std::cout << "Invalid number of edges. Maximum number of edges for " << n << " nodes is " << n * (n - 1) / 2 << std::endl;
        return 1;
    }

    AdjMatrixGraph matrixGraph(n);
    AdjListGraph listGraph(n);

    for (int i = 0; i < e; ++i) {
        int u = rand() % n;
        int v = rand() % n;

        while (u == v || matrixGraph.hasEdge(u, v)) {
            u = rand() % n;
            v = rand() % n;
        }

        matrixGraph.addEdge(u, v);
        listGraph.addEdge(u, v);
    }

    matrixGraph.printAdjMatrix();
    listGraph.printAdjList();

    return 0;
}
