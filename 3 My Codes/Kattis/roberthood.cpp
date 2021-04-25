#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ff first
#define ss second

vector<pii> v;

int distSqr(pii a, pii b)
{
    return (a.ff-b.ff)*(a.ff-b.ff) + (a.ss-b.ss)*(a.ss-b.ss);
}

int area(pii a, pii b, pii c)
{
    return a.ff*(b.ss-c.ss)+b.ff*(c.ss-a.ss)+c.ff*(a.ss-b.ss);
}

bool clockWise(pii a, pii b, pii c)
{
    return a.ff*(b.ss-c.ss)+b.ff*(c.ss-a.ss)+c.ff*(a.ss-b.ss) <= 0;
}

bool anticlockWise(pii a, pii b, pii c)
{
    return a.ff*(b.ss-c.ss)+b.ff*(c.ss-a.ss)+c.ff*(a.ss-b.ss) >= 0;
}

void convex_hull()
{
    if(v.size() == 1)
        return;

    sort(v.begin(), v.end());

    pii p1 = v[0], p2 = v.back();

    vector<pii> up, down;
    up.push_back(p1);
    down.push_back(p1);

    for(int i = 1; i < v.size(); i++)
    {
        if(i == v.size()-1 || clockWise(p1, v[i], p2))
        {
            while(up.size() >= 2 && !clockWise(up[up.size()-2], up[up.size()-1], v[i]))
                up.pop_back();
            up.push_back(v[i]);
        }

        if(i == v.size()-1 || anticlockWise(p1, v[i], p2))
        {
            while(down.size() >= 2 && !anticlockWise(down[down.size()-2], down[down.size()-1], v[i]))
                down.pop_back();
            down.push_back(v[i]);
        }
    }

    v.clear();

    for(int i = 0; i < down.size(); i++)
        v.push_back(down[i]);
    for(int i = up.size()-2; i > 0; i--)
        v.push_back(up[i]);
}

int RotatingCallipers()
{
    int ret = -1, i, j = 1, n = v.size();

    for(i = 0; i < n; i++)
    {
        while(abs(area(v[i], v[(i+1)%n], v[(j+1)%n])) > abs(area(v[i], v[(i+1)%n], v[j])))
            j = (j+1)%n;

        ret = max(ret, distSqr(v[i], v[j]));
        ret = max(ret, distSqr(v[(i+1)%n], v[j]));
    }

    return ret;
}


int main()
{
    int c, i, x, y;

    cin >> c;

    for(i = 0; i < c; i++)
    {
        cin >> x >> y;
        v.push_back({x, y});
    }

    convex_hull();

//    for(auto u : v)
//        cout << u.ff << " " << u.ss << "\n";

    int sq = RotatingCallipers();

    cout << fixed << setprecision(8) << sqrt(double(sq));
}
