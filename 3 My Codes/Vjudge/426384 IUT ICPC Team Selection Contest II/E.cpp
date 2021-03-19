#include<bits/stdc++.h>
using namespace std;

class hole
{
public:
    double x, y, z, r, st, ed;


};

bool func(hole a, hole b)
{
    return (a.x-a.r) < b.x-b.r;
}

double w_from_left(double l)
{
    double weight = 100*100*l;


}

int main()
{
    int n, s, i;

    hole h[10009];

    double w;

    while(cin >> n >> s)
    {
        for(i = 0; i < n; i++)
            cin >> h[i].r >> h[i].x >> h[i].y >> h[i].z;

        sort(h, h+n, func);

        w = 100.0/s;
    }
}
