#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;


void generateRandomGraph(int n, int e) {
    srand(time(0));


    vector<vector<int>> adjacencyMatrix(n, vector<int>(n, 0));

    vector<vector<pair<int, int>>> adjacencyList(n);


    for (int i = 0; i < e; ++i) {
        int u = rand() % n;
        int v = rand() % n;
        int weight = rand() % 100 + 1;
        while (u == v || adjacencyMatrix[u][v] != 0) {
            u = rand() % n;
            v = rand() % n;
        }

        adjacencyMatrix[u][v] = weight;
        adjacencyMatrix[v][u] = weight;

        adjacencyList[u].push_back({v, weight});
        adjacencyList[v].push_back({u, weight});
    }


    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << endl;
    }


    cout << "Adjacency List:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << i << ": ";
        for (auto& edge : adjacencyList[i]) {
            cout << "(" << edge.first << ", " << edge.second << ") ";
        }
        cout << endl;
    }
}

int main() {
    int n, e;
    cout << "Enter the number of nodes (n): ";
    cin >> n;
    cout << "Enter the number of edges (e): ";
    cin >> e;

    generateRandomGraph(n, e);

    return 0;
}
