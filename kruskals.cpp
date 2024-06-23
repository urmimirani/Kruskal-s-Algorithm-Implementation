#include <iostream>
#include <algorithm> // For sorting and manipulating elements
#include <fstream>   // For file handling - input and output
#include <vector>    // For using vector data structure

bool compare(const std::vector<int> &a, const std::vector<int> &b) {
    return a[2] < b[2];
}

void makeSet(std::vector<int> &parent, std::vector<int> &ranks, int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        ranks[i] = 0;
    }
}

int findParent(std::vector<int> &parent, int node) {
    if (parent[node] == node) {
        return node;
    }
    return parent[node] = findParent(parent, parent[node]);
}

void unionSet(int u, int v, std::vector<int> &parent, std::vector<int> &ranks) {
    u = findParent(parent, u);
    v = findParent(parent, v);
    if (ranks[u] < ranks[v]) {
        parent[u] = v;
    } else if (ranks[v] < ranks[u]) {
        parent[v] = u;
    } else {
        parent[v] = u;
        ranks[u]++;
    }
}

int main() {
    std::ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Failed to open the input file." << std::endl;
        return 1;
    }

    int n, m;
    inputFile >> n >> m;
    std::vector<std::vector<int>> edges(m, std::vector<int>(3));
    for (int i = 0; i < m; i++) {
        inputFile >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }
    inputFile.close();

    std::sort(edges.begin(), edges.end(), compare);

    std::vector<int> parent(n);
    std::vector<int> ranks(n);
    makeSet(parent, ranks, n);

    int minWeight = 0;
    for (const auto &edge : edges) {
        int u = findParent(parent, edge[0]);
        int v = findParent(parent, edge[1]);
        int weight = edge[2];
        if (u != v) {
            minWeight += weight;
            unionSet(u, v, parent, ranks);
        }
    }

    std::cout << "Minimum Weight: " << minWeight << std::endl;
    return 0;
}
