#include <iostream>

using namespace std;

struct Item { int id, v; double w; };

class KnapsackSolver {
    Item it[100];
    int n, cap, maxP = 0;
    bool best[100], curr[100];

    void dfs(int lvl, int p, double w) {
        if (lvl == n) {
            if (p > maxP) {
                maxP = p;
                for (int i = 0; i < n; i++) best[i] = curr[i];
            }
            return;
        }
        // Try including item if it fits
        if (w + it[lvl].w <= cap) {
            curr[lvl] = 1;
            dfs(lvl + 1, p + it[lvl].v, w + it[lvl].w);
        }
        // Bound: simple check if remaining potential exceeds maxP (Greedy bound)
        double remP = 0, remW = cap - w;
        for (int i = lvl + 1; i < n; i++) {
            if (it[i].w <= remW) { remW -= it[i].w; remP += it[i].v; }
            else { remP += it[i].v * (remW / it[i].w); break; }
        }

        if (p + remP > maxP) {
            curr[lvl] = 0;
            dfs(lvl + 1, p, w);
        }
    }

public:
    void run() {
        cin >> n >> cap;
        for (int i = 0; i < n; i++) {
            it[i].id = i + 1;
            cin >> it[i].v >> it[i].w;
        }
        // Simple Bubble Sort by density
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if ((double)it[i].v / it[i].w < (double)it[j].v / it[j].w) {
                    Item t = it[i]; it[i] = it[j]; it[j] = t;
                }

        dfs(0, 0, 0);
        cout << "\nMax Profit: " << maxP << "\nItems:";
        for (int i = 0; i < n; i++)
            if (best[i]) cout << " " << it[i].id;
    }
};

int main() {
    KnapsackSolver().run();
    return 0;
}
