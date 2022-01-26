#include<bits/stdc++.h>
using namespace std;

int Log[200005];
int val[200005];
int sparseMin[200005][20];
int sparseMax[200005][20];

int FindMin(int l, int r)
{
    int h = Log[r-l+1];

    return min(sparseMin[l][h], sparseMin[r-(1<<h)+1][h]);
}

int FindMax(int l, int r)
{
    int h = Log[r-l+1];

    return max(sparseMax[l][h], sparseMax[r-(1<<h)+1][h]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T, n, m, l, r, i, j, mn, mx;
    string s;

    for(i = 2; i < 200005; i++)
        Log[i] = Log[i/2] + 1;

    cin >> T;

    while(T--)
    {
        cin >> n >> m >> s;

        for(i = 1; i <= n; i++)
        {
            if(s[i-1] == '+')
            {
                val[i] = val[i-1] + 1;
                sparseMin[i][0] = sparseMin[i-1][0] + 1;
                sparseMax[i][0] = sparseMax[i-1][0] + 1;
            }
            else
            {
                val[i] = val[i-1] - 1;
                sparseMin[i][0] = sparseMin[i-1][0] - 1;
                sparseMax[i][0] = sparseMax[i-1][0] - 1;
            }
        }

        for(j = 1; j < 20; j++)
        {
            for(i = 0; i+(1<<j)-1 <= n; i++)
            {
                sparseMin[i][j] = min(sparseMin[i][j-1], sparseMin[i+(1<<(j-1))][j-1]);
                sparseMax[i][j] = max(sparseMax[i][j-1], sparseMax[i+(1<<(j-1))][j-1]);
            }
        }

//        for(i = 0; i <= n; i++)
//        {
//            for(j = 0; j < 5; j++)
//                cout << setw(4) << sparseMin[i][j];
//            cout << "\n";
//        }
//
//        cout << FindMin(0, 0) << " " << FindMax(0, 0) << "\n";
//        cout << FindMin(2, 8) << " " << FindMax(2, 8) << "\n";

        while(m--)
        {
            cin >> l >> r;

            mn = FindMin(0, l-1);
            if(r < n)
                mn = min(mn, FindMin(r+1, n) - val[r] + val[l-1]);

            mx = FindMax(0, l-1);
            if(r < n)
                mx = max(mx, FindMax(r+1, n) - val[r] + val[l-1]);

            cout << mx - mn + 1 << "\n";
        }
    }
}
