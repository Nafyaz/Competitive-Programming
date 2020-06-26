#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
#define ll long long
#define ff first
#define ss second

ll req[4][4], ans[4], sum, k;

void func(ll t, ll m)
{
//    cout << t << endl;
    ll i;
    if(t == 4)
    {
//        for(i = 0; i < 4; i++)
//            cout << ans[i] << " ";
//        cout << endl;
        ll temp[4] = {ans[0], ans[1], ans[2], ans[3]};
        sort(temp, temp+4);
        k = 0;
        for(i = 0; i < 4; i++)
        {
            if(temp[i] == 0)
              k++;
        }
        if(sum < temp[0]*25 + temp[1]*50 + temp[2]*75 + temp[3]*100 - 100*k)
            sum = temp[0]*25 + temp[1]*50 + temp[2]*75 + temp[3]*100 - 100*k;
        return;
    }
    for(i = 0; i < 4; i++)
    {
        if(((1 << i) & m) == 0)
        {
            ans[t] = req[i][t];
            func(t+1, m|(1<<i));
        }
    }
}

int main()
{
    ll T, n, t, i, j;
    char m;
    ll time[4], movie[4], total = 0;
//    ll price[4] = {100, 75, 50, 25};
//    priority_queue<pair<ll, pair<ll, ll> > > pq;
    cin >> T;
    while(T--)
    {
        memset(req, 0, sizeof(req));
        memset(time, 0, sizeof(time));
        memset(movie, 0, sizeof(movie));

        cin >> n;
        for(i = 0; i < n; i++)
        {
            cin >> m >> t;
            req[m - 'A'][t/3-1] ++;
        }

        sum = INT_MIN;
        func(0, 0);
        cout << sum << endl;
        total += sum;
    }

    cout << total;
}
