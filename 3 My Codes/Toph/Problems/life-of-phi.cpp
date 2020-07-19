#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000009

ll phi[N];

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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    sievephi();

    ll t, n, phisum;
    cin >> t;
    while(t--)
    {
        cin >> n;
        phisum = n*phi[n]/2;
        cout << n*(n-1)/2 - phisum << "\n";
    }
}
