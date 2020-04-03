#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll mod = 1e9+7, curr, dp[100009][13];
vector<ll> qpos;

int main()
{
    ll i, j, k, p = 1, q;
    string s;
    cin >> s;

    for(i = s.size()-1; i >= 0; i--)
    {
        if(s[i] == '?')
            qpos.push_back(p);
        else
            curr = (curr + (s[i] - '0')*p)%13;
        p = (p*10)%13;
    }

//    for(auto u : qpos)
//        cout << u << endl;

    curr = (5 - curr + 13)%13;

//    cout << "curr " << curr << endl;

    ll x, rem;
    for(i = 0; i < qpos.size(); i++)
    {
        for(j = 0; j < 13; j++)
        {
            for(k = 0; k < 10; k++)
            {
                p = (qpos[i]*k)%13;
                rem = (j - p + 13)%13;
                if(i == 0 && rem == 0)
                {
                    dp[i][j] = (dp[i][j] + 1)%mod;
                }
                else if(i > 0)
                {
                    dp[i][j] = (dp[i][j] + dp[i-1][rem])%mod;
                }

            }
        }
    }

//    for(i = 0; i < 13; i++)
//    {
//        for(j = 0; j < qpos.size(); j++)
//            cout << dp[j][i] << " ";
//        cout << endl;
//    }
    cout << dp[qpos.size()-1][curr];
}
