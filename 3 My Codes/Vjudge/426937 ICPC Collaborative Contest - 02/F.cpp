#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

class cloud
{
public:
    double x1, x2, y;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, n;
    double t, caseno = 0, w, h, q, x, ans;

    cloud c[1009];
    pair<double, double> shadow[1009];

    cin >> t;

    while(t--)
    {
        cin >> n >> w >> h >> q;

        for(i = 0; i < n; i++)
            cin >> c[i].x1 >> c[i].x2 >> c[i].y;

        cout << "Case " << ++caseno << ":\n";

        while(q--)
        {
            cin >> x;
            for(i = 0; i < n; i++)
            {
                double tmp = (c[i].x1 - x)*h/c[i].y + x;
                shadow[i].ff = max(min(tmp, w), 0.0);

                tmp = (c[i].x2 - x)*h/c[i].y + x;
                shadow[i].ss = max(min(tmp, w), 0.0);
//                cout << shadow[i].ff << " " << shadow[i].ss << "\n";
            }

            shadow[n] = {0, 0};
            shadow[n+1] = {w, w};

            sort(shadow, shadow+n+2);

            ans = 0;
            for(i = 1; i < n+2; i++)
            {
                if(shadow[i].ff > shadow[i-1].ss)
                    ans += shadow[i].ff - shadow[i-1].ss;
            }

            ans = ans / w;

            cout << ans << "\n";
        }
    }
}
