#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

vector<pair<int, int>> p;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, i, a, b, ansA, ansB, maxD, l, r;

    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> a;
        p.push_back({a, 0});
    }

    cin >> m;
    for(i = 0; i < m; i++)
    {
        cin >> b;
        p.push_back({b, 1});
    }

    sort(p.begin(), p.end());

    l = 0, r = 0;

    a = 2*l + 3*(n-l);
    b = 2*r + 3*(m-r);

    maxD = a - b;
    ansA = a;
    ansB = b;

    for(i = 0; i < p.size(); i++)
    {
        l += (p[i].ss == 0);
        r += (p[i].ss == 1);

        while(i+1 < p.size() && p[i].ff == p[i+1].ff)
        {
            i++;
            l += (p[i].ss == 0);
            r += (p[i].ss == 1);
        }

        a = 2*l + 3*(n-l);
        b = 2*r + 3*(m-r);

        if(a - b > maxD || (a - b == maxD && a > ansA))
        {
            maxD = a - b;
            ansA = a;
            ansB = b;
        }
    }

    cout << ansA << ":" << ansB;
}
