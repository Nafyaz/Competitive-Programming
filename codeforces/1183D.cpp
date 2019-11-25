#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
bool cmp(pair<int, int> a, pair<int, int> b)
{
    if(a.ff >= b.ff)
        return 1;
    else if(a.ss > b.ss)
        return 1;
    else
        return 0;
}
int main()
{
    int q, n, i, ans, ans2, x;
    int a, f;
    map <int, int> mp, mp2;
    set <int> ms;
    multiset <int> ms2;
    vector <pair <int, int> > v;

    scanf("%d", &q);
    while(q--)
    {
        mp.clear();
        mp2.clear();
        ms.clear();
        ms2.clear();
        v.clear();
        ans = 0;
        ans2 = 0;

        scanf("%d", &n);

        for(i = 0; i < n; i++)
        {
            scanf("%d %d", &a, &f);
            mp[a]++;
            if(f)
                mp2[a]++;
        }

        for(auto u: mp)
            v.push_back({u.second, mp2[u.first]});

        sort(v.begin(), v.end(), cmp);

        for(auto u: v)
        {
            //printf("%d %d\n", u.ff, u.ss);
            x = u.ff;
            while(x && ms.count(x))
                x--;
            ms.insert(x);
            ms2.insert(min(x, u.ss));
        }

        for(auto u : ms)
        {
            ans += u;
            //printf("%d ", u);
        }
        for(auto u : ms2)
            ans2 += u;

        printf("%d %d\n", ans, ans2);
    }
}
