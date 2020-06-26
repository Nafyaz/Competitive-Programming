#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

ll a[100009], ans[1000009];

void print(priority_queue<pair<ll, pair<ll, ll>>> pq)
{
    while(!pq.empty())
    {
        cout << pq.top().ff << " " << pq.top().ss.ff << " " << pq.top().ss.ss << endl;
        pq.pop();
    }
}

int main()
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);

    ll caseno = 0, t, n, m, i, q, x, w;

//    cin >> t;
    scanf("%lld", &t);
    while(t--)
    {
//        cin >> n >> m;
        scanf("%lld %lld", &n, &m);
        for(i = 0; i < n; i++)
//            cin >> a[i];
            scanf("%lld", &a[i]);

        sort(a, a+n);

        pair<ll, pair<ll, ll>> temp;
        multiset<pair<ll, pair<ll, ll>>> p;

        p.insert({a[0], {a[0], 1}});
        for(i = 1; i < n; i++)
            p.insert({a[i] - a[i-1], {a[i] - a[i-1], 1}});
        p.insert({m - a[n-1], {m - a[n-1], 1}});

        for(i = 0; i <= m; i++)
        {
            auto it=p.end();
            it--;
            ans[i] = it->ff;

            temp = *it;
            p.erase(it);
            if(temp.ff == 1)
                break;

            temp.ss.ss ++;
            temp.ff = (temp.ss.ff + temp.ss.ss - 1) / temp.ss.ss;
            p.insert(temp);

//            cout << i << endl;
//            print(p);

        }

//        cout << "Case " << ++caseno << ":" << endl;
//        cin >> q;
        printf("Case %lld:\n", ++caseno);
        scanf("%lld", &q);
        while(q--)
        {
//            cin >> x;
//            cout << (x >= i? 1 : ans[x]) << endl;
            scanf("%lld", &x);
            printf("%lld\n", (x >= i? 1 : ans[x]));
        }

    }
}

/*
4
3 30
5 10 29
3
1 2 30
3 30
5 10 29
3
1 2 30
3 30
5 10 29
3
1 2 30
3 30
5 10 29
3
1 2 30
*/
