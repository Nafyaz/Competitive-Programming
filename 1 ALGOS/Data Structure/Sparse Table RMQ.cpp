#include<bits/stdc++.h>
using namespace std;

int a[100009], sparse[100009][20], Log[100009];

int main()
{
    int n, i, j, len;
    cin >> n;

    Log[1] = 0;
    for(i = 2; i <= n; i++)
        Log[i] = Log[i>>1] + 1;

    for(i = 0; i < n; i++)
        cin >> a[i];

    for(i = 0; i < n; i++)
        sparse[i][0] = a[i];

    for(j = 1; j < n; j++)
    {
        len = (1LL << j);
        for(i = 0; i + len - 1 < n; i++)
            sparse[i][j] = min(sparse[i][j-1], sparse[i + len/2][j-1]);
    }

    int q, k;
    cin >> q;

    while(q--)
    {
        cin >> i >> j;
        k = Log[j-i+1];
        cout << min(sparse[i][k], sparse[j - (1 << k) + 1][k]) << endl;
    }
}
