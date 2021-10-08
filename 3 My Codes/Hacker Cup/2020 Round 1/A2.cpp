#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll L[1000006];
ll W[1000006];
ll H[1000006];

void solve(ll caseno)
{
    ll i, j, n, k, w;
    ll Al, Bl, Cl, Dl;
    ll Aw, Bw, Cw, Dw;
    ll Ah, Bh, Ch, Dh;
    ll hor, ver, p, maxH, ans;

    cin >> n >> k;

    for(i = 1; i <= k; i++)
        cin >> L[i];
    cin >> Al >> Bl >> Cl >> Dl;

    for(i = 1; i <= k; i++)
        cin >> W[i];
    cin >> Aw >> Bw >> Cw >> Dw;

    for(i = 1; i <= k; i++)
        cin >> H[i];
    cin >> Ah >> Bh >> Ch >> Dh;

    for(i = k+1; i <= n; i++)
    {
        L[i] = (Al*L[i-2] + Bl*L[i-1] + Cl) % Dl + 1;
        W[i] = (Aw*W[i-2] + Bw*W[i-1] + Cw) % Dw + 1;
        H[i] = (Ah*H[i-2] + Bh*H[i-1] + Ch) % Dh + 1;
    }

    hor = 2*W[1] % mod;
    ver = 2*H[1] % mod;
    p = (hor + ver) % mod;

    ans = p;

    for(i = 2; i <= n; i++)
    {
        if(L[i-1] + w < L[i])
        {
            hor = (hor + 2*w) % mod;
            ver = (ver + 2*H[i]) % mod;
        }
        else
        {
            hor = (hor + 2*(L[i] - L[i-1])) % mod;

            maxH = 0;
            for(j = i-1; j >= 1 && L[i] >= L[j] && L[i] <= L[j]+w; j--)
                maxH = max(maxH, H[j]);

            ver = (ver + 2*max(0LL, H[i] - maxH)) % mod;
        }

        p = (hor + ver) % mod;

        ans = (ans * p) % mod;
    }

    cout << "Case #" << caseno << ": " << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    ll T, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}

