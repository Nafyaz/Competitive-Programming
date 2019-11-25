#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second

bool comp(pair <int, int> a, pair <int, int> b)
{
    return a.f < b.f;
}

int main()
{
    pair <int, int> a[3];
    set <pair<int, int> > s;

    scanf("%d %d", &a[0].f, &a[0].s);
    scanf("%d %d", &a[1].f, &a[1].s);
    scanf("%d %d", &a[2].f, &a[2].s);

    sort(a, a+3, comp);

    int i;
    for(i = a[0].f; i != a[1].f; i++)
        s.insert({i, a[0].s});

    for(i = a[0].s; i != a[1].s; a[1].s > a[0].s ? i++ : i--)
        s.insert({a[1].f, i});

    for(i = a[1].s; i != a[2].s; a[2].s > a[1].s ? i++ : i--)
        s.insert({a[1].f, i});

    for(i = a[1].f; i != a[2].f; i++)
        s.insert({i, a[2].s});
    s.insert({a[2].f, a[2].s});

    printf("%d\n", s.size());
    for(auto x : s)
        printf("%d %d\n", x.f, x.s);
}
