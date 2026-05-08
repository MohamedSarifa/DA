#include <iostream>
using namespace std;

int main() {
    int v;
    cout << "Enter number of vertices: ";
    cin >> v;

    int graph[10][10], dist[10][10];

    int INF=9999;

    // Input
    cout << "Enter adjacency matrix (use 9999 for INF):\n";
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            cin >> graph[i][j];
            dist[i][j] = graph[i][j];
        }
    }

    // Initial Matrix
    cout << "\nStep 0 (Initial Matrix):\n";
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    // Floyd Algorithm with steps
    for (int k = 0; k < v; k++) {

        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {

                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][j] > dist[i][k] + dist[k][j]) {

                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }

        // Print matrix after each k
        cout << "\nStep " << k + 1 << " (k = " << k << "):\n";
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if (dist[i][j] == INF)
                    cout << "INF ";
                else
                    cout << dist[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Final Output
    cout << "\nFinal Shortest Distance Matrix:\n";
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
