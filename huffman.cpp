#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Enter number of symbols: ";
    cin >> n;

    char data[100];
    double freq[200];
    int parent[200], left[200], right[200];

    for (int i = 0; i < 200; i++) {
        parent[i] = left[i] = right[i] = -1;
    }

    cout << "Enter symbols:\n";
    for (int i = 0; i < n; i++) cin >> data[i];

    cout << "Enter frequencies:\n";
    for (int i = 0; i < n; i++) cin >> freq[i];

    int size = n;
    while (true) {
        int min1 = -1, min2 = -1;
        for (int i = 0; i < size; i++) {
            if (parent[i] == -1) {
                if (min1 == -1 || freq[i] < freq[min1]) {
                    min2 = min1;
                    min1 = i;
                } else if (min2 == -1 || freq[i] < freq[min2]) {
                    min2 = i;
                }
            }
        }
        if (min2 == -1) break;

        freq[size] = freq[min1] + freq[min2];
        left[size] = min1;
        right[size] = min2;
        parent[min1] = size;
        parent[min2] = size;
        size++;
    }

    cout << "\nHuffman Codes Table:\n";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " : ";
        int code[50], k = 0;
        int curr = i;
        while (parent[curr] != -1) {
            int p = parent[curr];
            code[k++] = (left[p] == curr) ? 0 : 1;
            curr = p;
        }
        for (int j = k - 1; j >= 0; j--) cout << code[j];
        cout << endl;
    }

    char word[100];
    cout << "\nEnter string to encode: ";
    cin >> word;

    cout << "Binary Output: ";
    for (int i = 0; word[i] != '\0'; i++) {
        for (int j = 0; j < n; j++) {
            if (data[j] == word[i]) {
                int code[50], k = 0;
                int curr = j;
                while (parent[curr] != -1) {
                    int p = parent[curr];
                    code[k++] = (left[p] == curr) ? 0 : 1;
                    curr = p;
                }
                for (int l = k - 1; l >= 0; l--) cout << code[l];
                break;
            }
        }
    }
    cout << endl;

    return 0;
}
