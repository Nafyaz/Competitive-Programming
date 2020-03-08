#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int a[100009], ans[1000009];

void print(priority_queue<pair<int, pair<int, int>>> pq)
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

    int caseno = 0, t, n, m, i, q, x;

//    cin >> t;
    scanf("%d", &t);
    while(t--)
    {
//        cin >> n >> m;
        scanf("%d %d", &n, &m);
        for(i = 0; i < n; i++)
//            cin >> a[i];
            scanf("%d", &a[i]);

        sort(a, a+n);

        pair<int, pair<int, int>> temp;
        priority_queue<pair<int, pair<int, int>>> p;

        p.push({a[0], {a[0], 1}});
        for(i = 1; i < n; i++)
            p.push({a[i] - a[i-1], {a[i] - a[i-1], 1}});

        for(i = 1; i <= m; i++)
        {
            temp = p.top();
            p.pop();
            if(temp.ff == 1)
                break;

            temp.ss.ss ++;
            temp.ff = (temp.ss.ff + temp.ss.ss - 1) / temp.ss.ss;
            p.push(temp);

//            cout << i << endl;
//            print(p);

            ans[i] = p.top().ff;
        }

//        cout << "Case " << ++caseno << ":" << endl;
//        cin >> q;
        printf("Case %d:\n", ++caseno);
        scanf("%d", &q);
        while(q--)
        {
//            cin >> x;
//            cout << (x >= i? 1 : ans[x]) << endl;
            scanf("%d", &x);
            printf("%d\n", (x >= i? 1 : ans[x]));
        }

    }
}
