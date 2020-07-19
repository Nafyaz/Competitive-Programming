#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000009
ll phi[N], dep[N], presum[N][20];

void sievephi()
{
    ll i, j;
    for(i = 1; i < N; i++)
        phi[i] = i;

    for(i = 2; i < N; i++)
    {
        if(phi[i] == i)
        {
            for(j = i; j < N; j += i)
                phi[j] = phi[j] / i * (i - 1);
        }
    }
}

void depth()
{
    ll i, j;
    for(i = 2; i < N; i++)
        dep[i] = dep[phi[i]] + 1;

    for(i = 1; i < N; i++)
    {
        for(j = 0; j < 20; j++)
            presum[i][j] = presum[i-1][j] + (dep[i] == j);
    }
}

int main()
{
    sievephi();
    depth();

    ll t, m, n, k, i, j;
    cin >> t;
    while(t--)
    {
        cin >> m >> n >> k;
        cout << presum[n][k] - presum[m-1][k] << endl;
    }
}
