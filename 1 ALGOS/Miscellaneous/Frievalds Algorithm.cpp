#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define sz 1009

ll A[sz][sz], B[sz][sz], C[sz][sz];
ll r[sz], Br[sz], Cr[sz], ABr[sz];

int main()
{
    int n, i, j;
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

    for(i = 0; i < n; i++)
        r[i] = rand() % 2;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            Br[i] = (Br[i] + B[i][j] * r[j])%mod;
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            Cr[i] = (Cr[i] + C[i][j] * r[j])%mod;
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            ABr[i] = (ABr[i] + A[i][j] *Br[j])%mod;
    }

    bool flag = true;
    for(i = 0; i < n; i++)
    {
        if (ABr[i] != Cr[i])
        {
            flag = false;
            break;
        }
    }

    if (flag == true)
        cout << "YES";
    else
        cout << "NO";
}
