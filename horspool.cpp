#include <iostream>
using namespace std;

int shiftTable[256];

int length(char str[])
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

void createShiftTable(char pattern[])
{
    int m = length(pattern);

    for (int i = 0; i < 256; i++)
        shiftTable[i] = m;

    for (int j = 0; j < m - 1; j++)
        shiftTable[(unsigned char)pattern[j]] = m - 1 - j;
}

int horspool(char text[], char pattern[])
{
    int n = length(text);
    int m = length(pattern);

    createShiftTable(pattern);

    cout << text << endl;  // print text once

    int i = m - 1;

    while (i < n)
    {
        int k = 0;

        while (k < m && pattern[m - 1 - k] == text[i - k])
            k++;

        int pos = i - m + 1;  // alignment position

        // Print spaces to align pattern exactly under substring in text
        for (int sp = 0; sp < pos; sp++)
            cout << " ";

        cout << pattern;

        if (k == m)
        {
            cout << " (success)" << endl;
            return pos;
        }
        else
        {
            cout << endl;
            i = i + shiftTable[(unsigned char)text[i]];
        }
    }

    return -1;
}

int main()
{
    char text[200];
    char pattern[100];

    cout << "Enter the text: ";
    cin.getline(text, 200);

    cout << "Enter the pattern: ";
    cin.getline(pattern,200);

    int pos = horspool(text, pattern);

    if (pos == -1)
        cout << "Pattern not found\n";

    return 0;
}
