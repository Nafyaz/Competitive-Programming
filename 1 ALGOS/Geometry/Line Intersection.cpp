#include<bits/stdc++.h>
using namespace std;

struct point
{
    ll x, y;
};

bool intersect(point p1, point p2, point p3, point p4)
{
    ll a1, b1, c1;
    a1 = p1.y - p2.y;
    b1 = p2.x - p1.x;
    c1 = p2.x*p1.y - p1.x*p2.y;
    
    ll a2, b2, c2;
    a2 = p3.y - p4.y;
    b2 = p4.x - p3.x;
    c2 = p4.x*p3.y - p3.x*p4.y;

    ll det = a1*b2 - b1*a2;

    if(!det)
        return 0;

    ll px = (b2*c1 - b1*c2);
    ll py = (a1*c2 - a2*c1);

    if(px < min(p1.x*det, p2.x*det) || px > max(p1.x*det, p2.x*det) || py < min(p1.y*det, p2.y*det) || py > max(p1.y*det, p2.y*det))
        return 0;
    if(px < min(p3.x*det, p4.x*det) || px > max(p3.x*det, p4.x*det) || py < min(p3.y*det, p4.y*det) || py > max(p3.y*det, p4.y*det))
        return 0;

    return 1;
}

int main()
{
    point p1{10, 0}, p2{0, 20}, p3{5, 5}, p4{10009, 10009};
    cout  << intersect(p1, p2, p3, p4);
}
