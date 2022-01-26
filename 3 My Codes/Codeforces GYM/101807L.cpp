#include<bits/stdc++.h>
using namespace std;

string grid[3];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int w, a, b, mn, mx, mnIdx, mxIdx, i;

    cin >> w >> a >> b;
    a--;
    b--;

    grid[0] = string(w, '.');
    grid[1] = string(w, '.');
    grid[2] = string(w, '.');

    grid[0][a] = 'A';
    grid[1][0] = 'X';
    grid[2][b] = 'B';

    if(a == b)
    {
        cout << "Possible\n";
        cout << grid[0] << "\n" << grid[1] << "\n" << grid[2];

        return 0;
    }

    if(a > b)
    {
        mn = b;
        mnIdx = 2;

        mx = a;
        mxIdx = 0;
    }
    else
    {
        mn = a;
        mnIdx = 0;

        mx = b;
        mxIdx = 2;
    }

    if(a%2 != b%2 || mn == 0)
    {
        cout << "Impossible";
        return 0;
    }

    if(mn == 1 && mx == 3)
    {
        cout << "Impossible";
        return 0;
    }

    cout << "Possible\n";
    grid[mnIdx][mn-1] = '*';
    for(i = 1; i+1 < (a+b)/2; i++)
        grid[1][i] = '*';

    cout << grid[0] << "\n" << grid[1] << "\n" << grid[2];
}
