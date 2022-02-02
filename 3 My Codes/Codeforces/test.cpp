#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
    int n;
    scanf("%d", &n);
    int p[n];
    int d[n];
    //depth;
    int sz[n];
    for(int i = 1; i < n; i++)
    {
        scanf("%d", &p[i]);
        p[i]--;
        sz[i] = 1;
    }
    sz[0] = 1;
    d[0] = 0;
    for(int i = 1; i < n; i++)
    {
        d[i] = d[p[i]] + 1;
    }

    for(int i = 0; i < n; i++)
        cout << d[i] << " ";
    cout << "\n";

    for(int i = n-1; i > 0; i--)
    {
        sz[p[i]] += sz[i];
    }
    for(int i = 0; i < n; i++)
    {
        int k = n-sz[i] + d[i] + 2;
        double p = (double) k / 2.0;
        cout << p << " ";
    }
    cout << endl;
}
