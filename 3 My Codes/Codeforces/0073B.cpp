#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

ll b[100009];
pair<string, ll> mx[100009], mn[100009];

bool cmp(pair<string, ll> x, pair<string, ll> y)
{
    if(x.ss != y.ss)
        return x.ss > y.ss;
    return x.ff < y.ff;
}

int main()
{
    ll i, j, k, n, m, a, myidx;
    string s;

    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> s >> a;
        mx[i].ff = mn[i].ff = s;
        mx[i].ss = mn[i].ss = a;
    }

    sort(mx, mx+n, cmp);
    sort(mn, mn+n, cmp);

    cin >> m;
    for(i = 0; i < m; i++)
        cin >> b[i];
    for(; i < n; i++)
        b[i] = 0;

    sort(b, b+n);

    cin >> s;
    for(i = 0; i < n; i++)
    {
        if(mx[i].ff == s)
        {
            myidx = i;
            break;
        }
    }

    mx[myidx].ss += b[n-1];
    j = 0, k = n-2;
    for(i = 0; i < n; i++)
    {
        if(i != myidx)
        {
            if(mx[i].ss + b[j] < mx[myidx].ss || (mx[i].ss + b[j] == mx[myidx].ss && mx[i].ff > mx[myidx].ff))
            {
                mx[i].ss += b[j];
                j++;
            }
            else
            {
                mx[i].ss += b[k];
                k--;
            }
        }
    }

    mn[myidx].ss += b[0];
    j = 1, k = n-1;
    for(i = n-1; i >= 0; i--)
    {
        if(i != myidx)
        {
            if(mn[i].ss + b[k] > mn[myidx].ss || (mn[i].ss + b[k] == mx[myidx].ss && mn[i].ff < mn[myidx].ff))
            {
                mn[i].ss += b[k];
                k--;
            }
            else
            {
                mn[i].ss += b[j];
                j++;
            }
        }
    }

    sort(mx, mx+n, cmp);
    sort(mn, mn+n, cmp);

    ll mxpos, mnpos;
    for(i = 0; i < n; i++)
    {
        if(mx[i].ff == s)
            mxpos = i+1;
        if(mn[i].ff == s)
            mnpos = i+1;

//        cout << mn[i].ff << " " << mn[i].ss << "\n";
    }

    cout << mxpos << " " << mnpos;
}
