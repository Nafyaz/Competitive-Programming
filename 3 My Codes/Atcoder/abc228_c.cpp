#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

pair<int, int> a[100005];
int ans[100005];

int main()
{
    int n, k, i, p[3], pos;

    cin >> n >> k;

    for(i = 0; i < n; i++)
    {
        cin >> p[0] >> p[1] >> p[2];

        a[i] = {p[0] + p[1] + p[2], i};
    }

    sort(a, a+n);

//    for(i = 0; i < n; i++)
//        cout << a[i].ff << " " << a[i].ss << "\n";

    for(i = 0; i < n; i++)
    {
        pos = lower_bound(a, a+n, make_pair(a[i].ff+300, n)) - a;

        if(n - pos < k)
            ans[a[i].ss] = 1;
    }

    for(i = 0; i < n; i++)
    {
        cout << (ans[i] == 1? "Yes\n" : "No\n");
    }
}
