#include<bits/stdc++.h>
using namespace std;
#define EPS 1e-9
#define PI 2*acos(0.0)

struct point
{
    double x, y;
    point() { x = y = 0.0; }
    point(double _x, double _y) : x(_x), y(_y) {}

    bool operator == (point other) const
    {
        return abs(x - other.x) < EPS && abs(y - other.y) < EPS;
    }

    bool operator < (point other) const
    {
        if(abs(x - other.x) > EPS)
            return x < other.x;
        return y < other.y;
    }

    double dist(point p1, point p2)
    {
        return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
    }

    //rotate point p by theta degrees CCW w.r.t origin (0, 0)
    point Rotate(point p, double theta)
    {
         double rad = theta * PI / 180;
         return point(p.x*cos(rad) - p.y*sin(rad),
                      p.x*sin(rad) + p.y*cos(rad));
    }

};