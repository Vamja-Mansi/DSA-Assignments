#include <iostream>
#include <vector>
#include <algorithm>  // For sort()
using namespace std;

// Disjoint-set (Union-Find) with path compression and union by rank
class UnionFind {
public:
    vector<int> parent, rank;

    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);  // Path compression
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY])
                parent[rootY] = rootX;
            else if (rank[rootX] < rank[rootY])
                parent[rootX] = rootY;
            else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

int main() {
    int graph[4][4] = {
        {0, 2, 8, 3},  // A
        {2, 0, 5, 1},  // B
        {8, 5, 0, 6},  // C
        {3, 1, 6, 0}   // D
    };

    // Create a list of all edges in the form (weight, u, v)
    vector<pair<int, pair<int, int> > > edges;  // Fixed the '>>' issue here

    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (graph[i][j] > 0) {
                edges.push_back({graph[i][j], {i, j}});
            }
        }
    }

    // Sort edges by weight
    sort(edges.begin(), edges.end());

    UnionFind uf(4);
    int totalWeight = 0;

    cout << "Kruskal's Algorithm\n";
    for (auto& edge : edges) {
        int weight = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        // If u and v are in different sets, add the edge to the MST
        if (uf.find(u) != uf.find(v)) {
            uf.unionSets(u, v);
            cout << "Element " << (u + 1) << " is connected to element " << (v + 1)
                 << " with weight " << weight << endl;
            totalWeight += weight;
        }
    }

    cout << "Total weight of Kruskal's algorithm = " << totalWeight << endl;

    return 0;
}

