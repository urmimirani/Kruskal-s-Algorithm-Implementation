#include <iostream>
using namespace std;

const int MAX_V = 100;

class Graph {
private:
    int vertices;
    int matrix[MAX_V][MAX_V];

public:
    Graph(int V) {
        vertices = V;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                matrix[i][j] = 0;
            }
        }
    }

    void addEdge(int u, int v) {
        if (u >= vertices || v >= vertices) {
            cout << "Vertex out of range." << endl;
            return;
        }
        matrix[u][v] = 1;
        matrix[v][u] = 1;
    }

    void removeEdge(int u, int v) {
        if (u >= vertices || v >= vertices) {
            cout << "Vertex out of range." << endl;
            return;
        }
        matrix[u][v] = 0;
        matrix[v][u] = 0;
    }

    bool hasEdge(int u, int v) {
        if (u >= vertices || v >= vertices) {
            cout << "Vertex out of range." << endl;
            return false;
        }
        return (matrix[u][v] == 1);
    }

    void addVertex() {
        if (vertices >= MAX_V) {
            cout << "Maximum vertices limit reached." << endl;
            return;
        }
        vertices++;
        for (int i = 0; i < vertices; i++) {
            matrix[i][vertices - 1] = 0;
            matrix[vertices - 1][i] = 0;
        }
    }

    void removeVertex(int v) {
        if (v >= vertices) {
            cout << "Vertex out of range." << endl;
            return;
        }
        for (int i = 0; i < vertices; i++) {
            matrix[i][v] = 0;
            matrix[v][i] = 0;
        }
        vertices--;
    }

    int getDegree(int v) {
        if (v >= vertices) {
            cout << "Vertex out of range." << endl;
            return -1;
        }
        int degree = 0;
        for (int i = 0; i < vertices; i++) {
            if (matrix[v][i] == 1) {
                degree++;
            }
        }
        return degree;
    }

    void printGraph() {
        cout << "Adjacency Matrix:" << endl;
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int choice;
    int nVertices;
    bool exitProgram = false;

    cout << "Enter the number of vertices for the graph: ";
    cin >> nVertices;

    Graph graph(nVertices);

    while (!exitProgram) {
        cout << "Graph Operations:" << endl;
        cout << "1. Add Edge" << endl;
        cout << "2. Remove Edge" << endl;
        cout << "3. Check Edge Existence" << endl;
        cout << "4. Add Vertex" << endl;
        cout << "5. Remove Vertex" << endl;
        cout << "6. Get Vertex Degree" << endl;
        cout << "7. Print Graph" << endl;
        cout << "8. Quit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int u, v;
            cout << "Enter vertices to add an edge (u v): ";
            cin >> u >> v;
            graph.addEdge(u, v);
        } else if (choice == 2) {
            int u, v;
            cout << "Enter vertices to remove an edge (u v): ";
            cin >> u >> v;
            graph.removeEdge(u, v);
        } else if (choice == 3) {
            int u, v;
            cout << "Enter vertices to check edge existence (u v): ";
            cin >> u >> v;
            if (graph.hasEdge(u, v)) {
                cout << "Edge exists." << endl;
            } else {
                cout << "Edge does not exist." << endl;
            }
        } else if (choice == 4) {
            graph.addVertex();
        } else if (choice == 5) {
            int vertexToRemove;
            cout << "Enter the vertex to remove: ";
            cin >> vertexToRemove;
            graph.removeVertex(vertexToRemove);
        } else if (choice == 6) {
            int vertexToCheck;
            cout << "Enter the vertex to get degree: ";
            cin >> vertexToCheck;
            int degree = graph.getDegree(vertexToCheck);
            if (degree != -1) {
                cout << "Degree of vertex " << vertexToCheck << ": " << degree << endl;
            }
        } else if (choice == 7) {
            graph.printGraph();
        } else if (choice == 8) {
            exitProgram = true;
        } else {
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}
