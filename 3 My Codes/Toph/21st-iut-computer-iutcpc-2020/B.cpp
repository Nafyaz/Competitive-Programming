#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int lr[12] = {4, 5, 6, 2, 3, 4, 3, 7, 1, 5, 7, 1};
int lc[12] = {2, 3, 4, 4, 5, 6, 1, 5, 3, 7, 1, 7};

vector<pair<int, int>> v[12];

int grid[8][8];

bool isok(int r, int c)
{
    return (r >= 1 && r <= 8 && c >= 1 && c <= 8 && grid[r][c] != 1);
}

int main()
{
    int t, i, j, r, c, r2, c2;

    for(i = 0; i < 12; i++)
        grid[lr[i]][lc[i]] = 1;

    pair<int, int> a[] = {{4, 1}, {7, 2}, {} };

    v[0].insert(v.begin(), a, a+6);

    char loc;

    cin >> t;
    while(t--)
    {
        for(i = 0; i < 12; i++)
        {
            cout << "? " << lr[i] << " " << lc[i];
            cin >> loc;

            if(loc == 'S')
                break;
        }

        r = lr[i], c = lc[i];

        for(i = 0; i < 4; i++)
        {
            r2 =
        }
    }
}
