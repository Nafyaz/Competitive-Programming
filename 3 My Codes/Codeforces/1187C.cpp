#include<bits/stdc++.h>
using namespace std;
int a[10000], n;
int main()
{
    int m, i, j, t, l, r, flag = 0;
    scanf("%d %d", &n, &m);
    vector <pair<int, int> > v, w, v2;

    for(i = 0; i < m; i++)
    {
        scanf("%d %d %d", &t, &l, &r);

        if(t)
            v.push_back({l-1, r-1});
        else
            w.push_back({l-1, r-1});
    }
    sort(v.begin(), v.end());

    v2.push_back(v[0]);
    for(j = 1; j < v.size(); j++)
    {
        if(v[j].first <= v2.back().second)
        {
            v2.back().first = min(v[j].first, v2.back().first);
            v2.back().second = max(v[j].second, v2.back().second);
        }
        else
            v2.push_back(v[j]);
    }

    sort(v2.begin(), v2.end());

//    for(i = 0; i < v2.size(); i++)
//        printf("%d %d\n", v2[i].first, v2[i].second);
    for(i = 0; i < v2.size(); i++)
    {
        for(j = v2[i].first; j <= v2[i].second; j++)
            a[j] = 20000-i;
    }
    for(i = 0; i < w.size(); i++)
    {
        for(j = w[i].first; j < w[i].second; j++)
        {
            if(!a[j])
                a[j] = 200000-j;
        }
        //printf("%d %d\n", w[i].first, w[i].second);
        if(is_sorted(a + w[i].first, a + w[i].second + 1))
        {
            printf("NO");
            return 0;
        }
    }
    printf("YES\n");
    for(i = 0; i < n; i++)
    {
        if(!a[i])
            a[i] = 20000;
        printf("%d ", a[i]);
    }
 }
