#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define sz 1009

ll A[sz][sz], B[sz][sz], C[sz][sz];
ll r[sz], Br[sz], Cr[sz], ABr[sz];
ll n;

bool solve()
{
    ll i, j;

    for(i = 0; i < n; i++)
    {
        Br[i] = Cr[i] = 0;
        for(j = 0; j < n; j++)
        {
            Br[i] = (Br[i] + B[i][j] * r[j]) % mod;
//            Br[i] = Br[i] % mod;

            Cr[i] = (Cr[i] + C[i][j] * r[j]) % mod;
//            Cr[i] = Cr[i] % mod;
        }
    }

    bool flag = 1;
    for(i = 0; i < n; i++)
    {
        ABr[i] = 0;
        for(j = 0; j < n; j++)
            ABr[i] = (ABr[i] + A[i][j] *Br[j])%mod;

        if(ABr[i] != Cr[i])
        {
            flag = 0;
            break;
        }
    }

    return flag;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    ll i, j;
    cin >> n;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            cin >> A[i][j];
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            cin >> B[i][j];
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            cin >> C[i][j];
    }

    srand(time(0));

    bool flag = 1;
    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < n; j++)
            r[j] = rand() % 2;

        if(!solve())
        {
            flag = 0;
            break;
        }
    }

    cout << (flag? "YES" : "NO");
}

