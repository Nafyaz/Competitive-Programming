#include<bits/stdc++.h>
using namespace std;
#define EPS 1e-9

struct point
{
    double x, y;
};

int V[109], in[109];
vector<point> poly[109];

double triArea(point p, point q, point r)
{
    double area = 0;

    area += p.x*q.y - p.y*q.x;
    area += q.x*r.y - q.y*r.x;
    area += r.x*p.y - r.y*p.x;

    return abs(area);
}

bool isPointInside(point p, int i)
{
    double polyArea = 0, pointArea = 0;

    for(int k = 0; k < V[i]; k++)
    {
        polyArea += poly[i][k].x * poly[i][(k+1)%V[i]].y;
        polyArea -= poly[i][(k+1)%V[i]].x * poly[i][k].y;

        pointArea += triArea(p, poly[i][k], poly[i][(k+1)%V[i]]);
    }

    return abs(polyArea - pointArea) < EPS;
}

bool isPolyInside(int i, int j)
{
    for(auto p : poly[j])
    {
        if(!isPointInside(p, i))
            return 0;
    }

    return 1;
}

int main()
{
    freopen("out.txt", "w", stdout);

    int t, n, i, j, a, b, ans;
    point p;

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(i = 0; i < n; i++)
        {
            cin >> V[i];
            poly[i].clear();
            in[i] = 1;

            for(j = 0; j < V[i]; j++)
            {
                cin >> a >> b;

                p.x = a;
                p.x = b;

                poly[i].push_back(p);
            }
        }

        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(i == j || !in[i] || !in[j])
                    continue;

                if(isPolyInside(i, j))
                    in[i] = 0;
            }
        }

        ans = 0;

        for(i = 0; i < n; i++)
        {
            ans += in[i];
        }

        cout << ans << "\n";
    }
}
