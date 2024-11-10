#include <iostream>
#include <climits>  // For INT_MAX
using namespace std;

int main() {
    int graph[4][4] = {
        {0, 2, 8, 3},  // A
        {2, 0, 5, 1},  // B
        {8, 5, 0, 6},  // C
        {3, 1, 6, 0}   // D
    };

    int totalWeight = 0;
    bool connected[4] = {false};  // Track which vertices are in the MST
    connected[0] = true;  // Start with node 0 (A)

    cout << "Prim's Algorithm\n";

    for (int n = 0; n < 3; n++) {
        int smallest = INT_MAX;
        int u = -1, v = -1;

        // Find the smallest edge that connects a node in the MST to a node outside the MST
        for (int i = 0; i < 4; i++) {
            if (connected[i]) {  // Vertex i is in MST
                for (int j = 0; j < 4; j++) {
                    if (!connected[j] && graph[i][j] > 0 && graph[i][j] < smallest) {
                        smallest = graph[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        // Add the edge to the MST
        connected[v] = true;
        cout << "Element " << (u + 1) << " is connected to element " << (v + 1) 
             << " with weight " << graph[u][v] << endl;
        totalWeight += graph[u][v];
    }

    cout << "Total weight of Prim's algorithm = " << totalWeight << endl;

    return 0;
}


