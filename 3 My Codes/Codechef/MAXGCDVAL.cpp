#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000006

ll phi[N];
ll ans[N];

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

void precal()
{
    ll i, j;
    for(i = 1; i < N; i++)
    {
        for(j = i; j < N; j += i)
            ans[j] += phi[i+1];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    sievephi();
    precal();

    ll T, k;

    cin >> T;

    while(T--)
    {
        cin >> k;

        cout << ans[k]*2 << "\n";
    }
}
