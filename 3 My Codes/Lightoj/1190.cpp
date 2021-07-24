#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ppll pair<pll, pll>

struct point
{
    ll x, y;
};

point interp;
ll det;

bool on_edge(point p1, point p2, point p3)
{
    if(p3.x < min(p1.x, p2.x) || p3.x > max(p1.x, p2.x) || p3.y < min(p1.y, p2.y) || p3.y > max(p1.y, p2.y))
        return 0;

    ll area = p1.x*p2.y + p2.x*p3.y + p3.x*p1.y - p1.y*p2.x - p2.y*p3.x - p3.y*p1.x;

    if(area)
        return 0;
    else
        return 1;
}

bool intersect(point p1, point p2, point p3, point p4)
{
    ll a1, b1, c1;
    a1 = p1.y - p2.y;
    b1 = p2.x - p1.x;
    c1 = p2.x*p1.y - p1.x*p2.y;

//    cout << a1 << " " << b1 << " " << c1 << "\n";

    ll a2, b2, c2;
    a2 = p3.y - p4.y;
    b2 = p4.x - p3.x;
    c2 = p4.x*p3.y - p3.x*p4.y;

//    cout << a2 << " " << b2 << " " << c2 << "\n";

    det = a1*b2 - b1*a2;

//    cout << det << "\n";

    if(!det)
        return 0;

    interp.x = (b2*c1 - b1*c2);
    interp.y = (a1*c2 - a2*c1);

    if(interp.x < min(p1.x*det, p2.x*det) || interp.x > max(p1.x*det, p2.x*det) || interp.y < min(p1.y*det, p2.y*det) || interp.y > max(p1.y*det, p2.y*det))
        return 0;
    if(interp.x < min(p3.x*det, p4.x*det) || interp.x > max(p3.x*det, p4.x*det) || interp.y < min(p3.y*det, p4.y*det) || interp.y > max(p3.y*det, p4.y*det))
        return 0;

    return 1;
}


int main()
{
//    freopen("out.txt", "w", stdout);
    ll t, caseno = 0, i, j, n, q, flag;
    point p[109], a;
    point b = {10009, 10009};

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(i = 0; i < n; i++)
        {
            cin >> p[i].x >> p[i].y;
        }

        cout << "Case " << ++caseno << ":\n";

        cin >> q;

        while(q--)
        {
            cin >> a.x >> a.y;

            set<ppll> s;

            flag = 0;
            for(i = 0; i < n; i++)
            {
                j = (i+1)%n;

//                cout << i << ": ";
                if(on_edge(p[i], p[j], a))
                {
                    flag = 1;
                    break;
                }
                if(intersect(p[i], p[j], a, b))
                {
                    ll gx = __gcd(interp.x, det);
                    ll gy = __gcd(interp.y, det);

//                    cout << interp.x/gx << "/" << det/gx << ", " << interp.y/gy << "/" << det/gy;
                    s.insert({{interp.x/gx, det/gx}, {interp.y/gy, det/gy}});


                }
//                cout << "\n";
            }

            if(flag)
            {
                cout << "Yes\n";
                continue;
            }

            cout << (s.size()%2 == 1? "Yes\n" : "No\n");
        }
    }
}
/*
1
6
0 0
15 0
20 5
15 10
10 5
5 5
1
5 0
*/
