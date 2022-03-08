#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll S[5003], C[5003];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, n, i, j, ans, baire;

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(i = 1; i <= n; i++)
        {
            cin >> S[i];
            C[i] = 0;
        }

        ans = 0;
        for(i = 1; i <= n; i++)
        {
//            if(S[i] > max(1LL, n-i))
//            {
//                ans += S[i] - max(1LL, n-i);
//                S[i] = max(1LL, n-i);
//            }

            ans += max(0LL, S[i]-1 - C[i]);
            C[i] = max(S[i]-1, C[i]);
//            S[i] = 1;

            for(j = 2; j <= S[i] && i+j <= n; j++)
                C[i+j] ++;

            C[i+1] += max(0LL, C[i]-S[i]+1);

//            cout << "i: " << i << "; ans: " << ans << "\n";
//            for(j = 1; j <= n; j++)
//                cout << S[j] << " ";
//            cout << "\n";
//            for(j = 1; j <= n; j++)
//                cout << C[j] << " ";
//            cout << "\n\n";
        }

        cout << ans << "\n";
    }
}
