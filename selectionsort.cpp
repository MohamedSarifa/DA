#include <iostream>
using namespace std;

int main() {
    int n, temp;
    cout << "Enter No Of Elements:\n";
    cin >> n;

    int arr[n];
    cout << "Enter Elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int j = 0; j < n - 1; j++) {
        int min_idx = j;
        for (int k = j + 1; k < n; k++) {
            if (arr[k] < arr[min_idx]) {
                min_idx = k;
            }
        }
        temp = arr[j];
        arr[j] = arr[min_idx];
        arr[min_idx] = temp;
    }

    cout << "Displaying after Selection Sort:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;

    return 0;
}
