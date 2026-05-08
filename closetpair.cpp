#include <iostream>
#include <cmath>
#include <cfloat>
using namespace std;

int main()
{
    int n;
    float x[20], y[20];
    float p1x, p1y, p2x, p2y;
    float min_dist = FLT_MAX;

    cout << "Enter number of points (max 20):" << endl;
    cin >> n;
    cout << "Enter points (x,y)" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "Point " << i + 1 << ": ";
        cin >> x[i] >> y[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            float dist = sqrt(
                (x[j] - x[i]) * (x[j] - x[i]) +
                (y[j] - y[i]) * (y[j] - y[i])
            );

            if (dist < min_dist)
            {
                min_dist = dist;
                p1x = x[i]; p1y = y[i];
                p2x = x[j]; p2y = y[j];
            }
        }
    }

    if (n < 2) {
        cout << "At least two points are required." << endl;
    } else {
        cout << "\nClosest points: (" << p1x << ", " << p1y << ") and (" << p2x << ", " << p2y << ")" << endl;
        cout << "Minimum distance: " << min_dist << endl;
    }

    return 0;
}
