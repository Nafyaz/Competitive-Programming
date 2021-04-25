#include<bits/stdc++.h>
using namespace std;

char to_char(int i)
{
    if(i >= 26)
        return char('a' + i - 26);
    else
        return char('A' + i);
}

int main()
{
    int n, i, j;

    while(cin >> n)
    {
        cout << 2 << " " << n << " " << n << "\n";

        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
                cout << to_char(i);
            cout << "\n";
        }

        cout << "\n";

        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
                cout << to_char(j);
            cout << "\n";
        }
    }
}
