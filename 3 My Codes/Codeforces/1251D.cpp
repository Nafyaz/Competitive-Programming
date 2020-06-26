#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

ll n, s;
ll isleft[200010];
vector <pair <ll, ll> > v;

bool isok(ll x)
{
    for(int i = 1;i <= n;i++)
        isleft[i] = 0;

    ll i, leftc = 0;
    for(i = 0; i < n; i++)
    {
        if(v[i].ss < x)
        {
            isleft[i] = 1;
            leftc++;
        }

        if(leftc > n/2)
            return 0;
    }

    ll total = 0;
    for(i = 0; i < n; i++)
    {
        if(isleft[i])
            total += v[i].ff;

        else if(leftc < n/2)
        {
            if(v[i].ff > x)
                return 0;

            total += v[i].ff;
            leftc++;
        }

        else
            total += max(x, v[i].ff);

        if(total > s)
            return 0;
    }

    return 1;
}

int main()
{
    int t;

    ll i, a, b, l, h, mid, ans;

    cin >> t;
    while(t--)
    {
        v.clear();
        cin >> n >> s;

        for(i = 0; i < n; i++)
        {
            cin >> a >> b;
            v.push_back({a, b});
        }

        sort(v.begin(), v.end());

        l = 0, h = s;

//        while(l <= h)
//        {
//            mid = (l+h)/2;
//
//            if(isok(mid))
//            {
//                ans = mid;
//                l = mid + 1;
//            }
//
//            else
//                h = mid - 1;
//        }

        cout << isok(72) << " ";

        cout << ans << endl;
    }
}

/*
1
19 1175
44 87
68 100
93 98
76 79
10 58
74 99
87 97
23 75
62 73
100 100
71 76
73 87
76 82
44 84
54 90
2 82
67 99
85 97
66 88
*/
