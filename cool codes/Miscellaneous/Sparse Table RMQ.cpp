#include<bits/stdc++.h>
using namespace std;

int n, a[100009], sparse[100009][20];

int main()
{
    int i, j, k;
    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    k = log2(n) + 1;
    for(i = 0; i < n; i++)
        sparse[i][[0] = a[i];
    for(j = 1; (1 << j) <= n; j++)
    {
        for(i = 0; i + (1 << j) - 1 < n; i++)
        {
            sparse[i][j] = min(sparse[i][j-1], sparse[i + (1 << (j-1))][j-1]);
        }
    }

    for()
}
