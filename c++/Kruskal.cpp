#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Edge {
public:
    int source;
    int destination;
    int weight;
};

// Comparison function for sorting edges based on weight
bool compare(const Edge& e1, const Edge& e2) {
    return (e1.weight < e2.weight);
}

// Find function with path compression
int find(int v, int* parents) {
    if (parents[v] == v) {
        return v;
    }
    // Path compression
    return parents[v] = find(parents[v], parents);
}

// Union function to join two subsets
bool Union(Edge* output, Edge* input, int v, int* parents) {
    int count = 0, i = 0;
    while (count < v - 1 && i < v) {
        int parentS = find(input[i].source, parents);
        int parentD = find(input[i].destination, parents);
        if (parentS != parentD) {
            output[count] = input[i];
            count++;
            parents[parentS] = parentD; // Union operation
        }
        i++;
    }
    return count == v - 1; // Return true if we have v-1 edges
}

int main() {
    int v, e;
    cout << "Enter number of vertices and edges: ";
    cin >> v >> e;

    if (e < v - 1) {
        cout << "A minimum spanning tree is not possible with less than v-1 edges." << endl;
        return 0;
    }

    Edge* input = new Edge[e];
    cout << "Enter edges (source destination weight):" << endl;
    for (int i = 0; i < e; i++) {
        cin >> input[i].source >> input[i].destination >> input[i].weight;
    }

    // Sort edges based on weight
    sort(input, input + e, compare);

    int* parents = new int[v];
    for (int i = 0; i < v; i++) {
        parents[i] = i; // Initialize parent for each vertex
    }

    Edge* output = new Edge[v - 1];
    if (!Union(output, input, v, parents)) {
        cout << "Could not form a Minimum Spanning Tree." << endl;
    } else {
        cout << "Edges in the Minimum Spanning Tree:" << endl;
        for (int i = 0; i < v - 1; i++) {
            cout << min(output[i].source, output[i].destination) << " "
                 << max(output[i].source, output[i].destination) << " "
                 << output[i].weight << endl;
        }
    }

    // Cleanup
    delete[] input;
    delete[] parents;
    delete[] output;

    return 0;
}
