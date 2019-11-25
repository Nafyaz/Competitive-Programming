#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second

int main()
{
    int ans = 2;
    pair<int, char> a[3];
    scanf("%d%c %d%c %d%c", &a[0].ff, &a[0].ss, &a[1].ff, &a[1].ss, &a[2].ff, &a[2].ss);

    sort(a, a+3);

//    printf("%d%c %d%c %d%c", a[0].ff, a[0].ss, a[1].ff, a[1].ss, a[2].ff, a[2].ss);
    if(a[0].ff == a[1].ff || a[1].ff == a[2].ff || a[0].ff == a[2].ff)
        ans = 1;
    if((a[0].ff + 1 == a[1].ff && a[0].ss == a[1].ss) || (a[1].ff + 1 == a[2].ff && a[1].ss == a[2].ss) || (a[0].ff + 1 == a[2].ff && a[0].ss == a[2].ss))
        ans = 1;
    if((a[0].ff + 2 == a[1].ff && a[0].ss == a[1].ss) || (a[0].ff + 2 == a[2].ff && a[0].ss == a[2].ss)|| (a[1].ff + 2 == a[2].ff && a[1].ss == a[2].ss))
        ans = 1;

    if(a[0].ff == a[1].ff && a[1].ff == a[2].ff)
        ans = 0;
    if((a[0].ff + 1 == a[1].ff && a[0].ss == a[1].ss) && (a[1].ff + 1 == a[2].ff && a[1].ss == a[2].ss))
        ans = 0;

    printf("%d", ans);
}
