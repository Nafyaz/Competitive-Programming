#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct point
{
    ll x, y;

    point(ll _x=0, ll _y=0) {x=_x, y=_y;}

    point operator+(const point &p) {return {x+p.x, y+p.y};}
    point operator-(const point &p) {return {x-p.x, y-p.y};}
    ll operator^(const point &p) {return x*p.y - y*p.x;}
    bool operator<(const point &p) {return x<p.x || (x==p.x && y < p.y);}
    ll distSqr(const point &p) {return (x-p.x)*(x-p.x) + (y-p.y)*(y-p.y);}
};

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    ll n, q, T = 0, i, a, b, total, area;

    point p[50009];
    ll cross[50009], presum[50009];

    while(1)
    {
        cin >> n >> q;

        if(!n && !q)
            break;

        if(T)
            cout << "\n";
        T++;

        memset(cross, 0, sizeof cross);
        memset(presum, 0, sizeof presum);

        for(i = 0; i < n; i++)
            cin >> p[i].x >> p[i].y;

        for(i = 1; i <= n; i++)
        {
            cross[i] = p[i-1]^p[i%n];

            presum[i] = presum[i-1] + cross[i];
        }

        total = abs(presum[n]);

        while(q--)
        {
            cin >> a >> b;

            area = abs(presum[b] - presum[a] + (p[b]^p[a]));

            cout << fixed << setprecision(1) << min(area, total-area)/2.0 << "\n";
        }
    }
}
