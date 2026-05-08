#include <iostream>
using namespace std;

int x[50];
int N;

bool Place(int k, int i) {
    for(int j = 0; j < k; j++) {
        int col_diff = (x[j] > i) ? (x[j] - i) : (i - x[j]);
        int row_diff = (k - j);

        if(x[j] == i || col_diff == row_diff)
            return false;
    }
    return true;
}

void printBoard() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << (x[i] == j ? "Q " : ". ");
        }
        cout << endl;
    }
}

bool NQueens(int k) {
    for(int i = 0; i < N; i++) {
        if(Place(k, i)) {
            x[k] = i;

            if(k == N - 1) {
                printBoard();
                return true;
            } else {
                if(NQueens(k + 1)) return true;
            }
        }
    }
    return false;
}

int main() {
    cout << "Enter value of N: ";
    cin >> N;

    if (N < 1 || N > 50) return 1;

    if (!NQueens(0)) {
        cout << "No solution exists." << endl;
    }

    return 0;
}
