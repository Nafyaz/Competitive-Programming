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

    //rotate p by theta degrees CCW w.r.t origin (0, 0)
    point Rotate(point p, double theta)
    {
         double rad = theta * PI / 180;
         return point(p.x*cos(rad) - p.y*sin(rad),
                      p.x*sin(rad) + p.y*cos(rad));
    }
};

struct line
{
    //ax + by = c
    double a, b, c;

    //the answer is stored in third parameter (pass by reference)
    void pointsToLine(point p1, point p2, line &l)
    {
        if(abs(p1.x - p2.x) < EPS)
        {
            l.a = 1;
            l.b = 0;
            l.c = -p1.x;
        }
        else
        {
            double delx, dely;

            delx = p2.x - p1.x;
            dely = p2.y - p1.x;

            l.a = -dely / delx;
            l.b = 1; //we fix the value of b to 1.0
            l.c = -(p1.x*dely - p1.y*delx) / delx;
        }
    }

    bool areParallel(line l1, line l2)
    {
        return (abs(l1.a-l2.a) < EPS) && (abs(l1.b-l2.b) < EPS);
    }

    bool areSame(line l1, line l2)
    {
        return areParallel(l1, l2) && (abs(l1.c - l2.c) < EPS);
    }
};