#include <iostream>

using namespace std;

int main()
{
    string text, pattern;
    int i, j, found = 0;

    cout << "Enter text: ";
    cin >> text;

    cout << "Enter pattern: ";
    cin >> pattern;

    int n = 0;
    int m =0;

    while(text[n]!= '\0')
    {
       n++;
    }

    while(pattern[m]!= '\0')
    {
       m++;
    }

    for (i = 0; i <= n - m; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (text[i + j] != pattern[j])
                break;
        }

        if (j == m)
        {
            cout << "Pattern found at position: " << i+1 << endl;
            found = 1;
            break;
        }
    }

    if (found == 0)
        cout << "Pattern not found";

    return 0;
}
