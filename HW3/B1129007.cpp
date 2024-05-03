#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <algorithm>

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

    std::vector<std::vector<bool>> reorderMatrix(const std::vector<int>& order) {
        std::vector<std::vector<bool>> newMatrix(V, std::vector<bool>(V, false));
        for (int i = 0; i < V; i++) {
            for (int j : adjList[order[i]]) {
                auto pos = std::find(order.begin(), order.end(), j);
                if (pos != order.end()) {
                    int newJ = std::distance(order.begin(), pos);
                    newMatrix[i][newJ] = true;
                }
            }
        }
        return newMatrix;
    }

    void printMatrix(const std::vector<std::vector<bool>>& matrix) {
        for (const auto& row : matrix) {
            for (bool val : row) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
    }

    void printList() {
        for (int i = 0; i < V; ++i) {
            std::cout << i << " --> ";
            for (int num : adjList[i]) {
                std::cout << num << " ";
            }
            std::cout << std::endl;
        }
    }
};

class DFS {
private:
    std::vector<bool> visited;
    Graph& graph;
    std::vector<int> order;

public:
    DFS(Graph& g) : graph(g) {
        visited.resize(graph.V, false);
    }

    void dfs(int start) {
        visited[start] = true;
        order.push_back(start);
        std::cout << "DFS visits: " << start << std::endl;

        for (int adj : graph.adjList[start]) {
            if (!visited[adj]) {
                dfs(adj);
            }
        }
    }

    std::vector<int> getOrder() {
        return order;
    }
};

class BFS {
private:
    std::vector<bool> visited;
    Graph& graph;
    std::vector<int> order;

public:
    BFS(Graph& g) : graph(g) {
        visited.resize(graph.V, false);
    }

    void bfs(int start) {
        std::queue<int> queue;
        visited[start] = true;
        queue.push(start);
        order.push_back(start);

        while (!queue.empty()) {
            int current = queue.front();
            queue.pop();
            std::cout << "BFS visits: " << current << std::endl;

            for (int adj : graph.adjList[current]) {
                if (!visited[adj]) {
                    visited[adj] = true;
                    queue.push(adj);
                    order.push_back(adj);
                }
            }
        }
    }

    std::vector<int> getOrder() {
        return order;
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

    std::cout << "Adjacency Matrix:" << std::endl;
    graph.printMatrix(graph.adjMatrix);

    std::cout << "Adjacency List:" << std::endl;
    graph.printList();

    DFS dfs(graph);
    std::cout << "DFS Execution Order:" << std::endl;
    dfs.dfs(0);
    auto dfsOrder = dfs.getOrder();
    auto dfsMatrix = graph.reorderMatrix(dfsOrder);
    std::cout << "DFS reordered Adjacency Matrix:" << std::endl;
    graph.printMatrix(dfsMatrix);

    BFS bfs(graph);
    std::cout << "BFS Execution Order:" << std::endl;
    bfs.bfs(0);
    auto bfsOrder = bfs.getOrder();
    auto bfsMatrix = graph.reorderMatrix(bfsOrder);
    std::cout << "BFS reordered Adjacency Matrix:" << std::endl;
    graph.printMatrix(bfsMatrix);

    return 0;
}
