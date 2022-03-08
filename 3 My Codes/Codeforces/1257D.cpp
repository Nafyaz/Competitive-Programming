#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

ll n, m;
ll monster[200005];
ll Log[200005];
ll sparseMonster[200005][20], sparseHero[200005][20];
pair<ll, ll> hero[200005];

ll findMaxMonster(ll i, ll j)
{
    ll k = Log[j-i+1];

    return max(sparseMonster[i][k], sparseMonster[j-(1LL<<k)+1][k]);
}

ll findMaxHero(ll i, ll j)
{
    ll k = Log[j-i+1];

    return max(sparseHero[i][k], sparseHero[j-(1LL<<k)+1][k]);
}


bool isPossible(ll i, ll j)
{
    ll monsterCnt = j-i+1;

    if(hero[0].ff < monsterCnt)
        return 0;

    ll pos = lower_bound(hero, hero + m, make_pair(monsterCnt, -1), greater<pair<ll, ll>>()) - hero;

    return findMaxHero(0, pos-1) >= findMaxMonster(i, j);
}

ll call(ll i)
{
    if(i >= n)
        return 0;

    ll low = i, high = n-1, mid, nxt;

    while(low <= high)
    {
        mid = (low + high)/2;

        if(isPossible(i, mid))
        {
            nxt = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    return 1 + call(nxt+1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, i, j, mxPower;

    for(i = 2; i < 200005; i++)
        Log[i] = Log[i/2] + 1;

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(i = 0; i < n; i++)
        {
            cin >> monster[i];

            sparseMonster[i][0] = monster[i];
        }

        for(j = 1; j < 20; j++)
        {
            for(i = 0; i + (1LL << j) - 1 < n; i++)
                sparseMonster[i][j] = max(sparseMonster[i][j-1], sparseMonster[i + (1LL << (j-1))][j-1]);
        }

        mxPower = -1;
        cin >> m;
        for(i = 0; i < m; i++)
        {
            cin >> hero[i].ss >> hero[i].ff;
            mxPower = max(mxPower, hero[i].ss);
        }

        sort(hero, hero+m, greater<pair<ll, ll>>());

        for(i = 0; i < m; i++)
            sparseHero[i][0] = hero[i].ss;
        for(j = 1; j < 20; j++)
        {
            for(i = 0; i + (1LL << j) - 1 < m; i++)
                sparseHero[i][j] = max(sparseHero[i][j-1], sparseHero[i + (1LL << (j-1))][j-1]);
        }

        if(findMaxMonster(0, n-1) > mxPower)
            cout << "-1\n";
        else
            cout << call(0) << "\n";
    }
}
