#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool willWin(ll hC, ll dC, ll hM, ll dM)
{
    ll cHit = (hM + dC - 1) / dC;
    ll mHit = (hC + dM - 1) / dM;

    return (cHit <= mHit);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, hC, dC, hM, dM, k, w, a, i, flag;

    cin >> T;

    while(T--)
    {
        cin >> hC >> dC >> hM >> dM;
        cin >> k >> w >> a;

        flag = 0;
        for(i = 0; i <= k; i++)
        {
            if(willWin(hC + a*i, dC + w*(k-i), hM, dM))
            {
                flag = 1;
                break;
            }
        }

        cout << (flag == 1? "YES\n" : "NO\n");
    }
}
