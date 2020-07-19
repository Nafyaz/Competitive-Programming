#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000009

ll phi[N], ans[N];

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

void calc()
{
    ll i, j;
    for(i = 1; i < N; i++)
        ans[i]++;

    for(i = 2; i < N; i++)
    {
        for(j = i; j < N; j += i)
            ans[j] += phi[i] * i / 2;
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    sievephi();
    calc();
    ll t, n;

    cin >> t;
    while(t--)
    {
        cin >> n;
//        ans = 0;
//        for(i = 1; i * i <= n; i++)
//        {
//            if(n%i == 0)
//            {
//                if(i == 1)
//                    ans++;
//                else
//                    ans = ans + phi[i]*i/2;
//
//                if(i*i != n)
//                    ans = ans + phi[n/i]*n/i/2;
//            }
//        }

        cout << ans[n]*n << "\n";
    }
}
