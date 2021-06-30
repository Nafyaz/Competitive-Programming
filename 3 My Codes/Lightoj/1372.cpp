#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, caseno = 0, n, i, l[109];
    int a, b, c, d, e, pos, ans;
    int as, bs, cs, ds, es, rest;

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(i = 0; i < n; i++)
            cin >> l[i];

        sort(l, l+n);

        ans = 0;
        for(a = 0; a < n; a++)
        {
            as = l[a];
            for(b = a+1; b < n; b++)
            {
                bs = as + l[b];
                if(bs > l[n-1])
                {
                    rest = n-1 - b;
                    ans += rest*(rest-1)*(rest-2)*(rest-3)/24;
                    continue;
                }

                for(c = b+1; c < n; c++)
                {
                    cs = bs + l[c];
                    if(cs > l[n-1])
                    {
                        rest = n-1 - c;
                        ans += rest*(rest-1)*(rest-2)/6;
                        continue;
                    }

                    for(d = c+1; d < n; d++)
                    {
                        ds = cs + l[d];
                        if(ds > l[n-1])
                        {
                            rest = n-1 - d;
                            ans += rest*(rest-1)/2;
                            continue;
                        }

                        for(e = d+1; e < n; e++)
                        {
                            es = ds + l[e];
                            if(es > l[n-1])
                            {
                                rest = n-1 - e;
                                ans += rest;
                                continue;
                            }

                            pos = lower_bound(l, l+n, es) - l;

                            ans += pos - e - 1;
                        }
                    }
                }
            }
        }

        cout << "Case " << ++caseno << ": " << ans << "\n";
    }
}
