#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi 2*acos(0)

int main()
{
    freopen("in.txt", "w", stdout);
    ll n;
    ll r1, r2, d, w;
    double sg, s, area, a, h1, h2;
    double volume_of_sphere_1, volume_of_sphere_2, volume;
    double surface_of_sphere_1, surface_of_sphere_2, surface;

    srand (time(NULL));
    n = rand()%100 + 1;
    cout << n << "\n";

    while(n--)
    {

        r1 = rand()%500 + 1;
        r2 = rand()%500 + 1;
        d = rand()%(r1+r2-1 - max(r1, r2)) + max(r1, r2) + 1;

        sg = (rand()%999 + 1) / 100.0;

        s = (r1 + r2 + d) / 2.0;
        area = sqrt(s*(s-r1)*(s-r2)*(s-d));
        a = 2*area/d;

        h1 = r1 - sqrt(r1*r1 - a*a);
        volume_of_sphere_1 = (4.0/3*pi*r1*r1*r1) - (pi*h1*h1/3*(3*r1-h1));
        surface_of_sphere_1 = (4*pi*r1*r1) - (2*pi*r1*h1);

        h2 = r2 - sqrt(r2*r2 - a*a);
        volume_of_sphere_2 = (4.0/3*pi*r2*r2*r2) - (pi*h2*h2/3*(3*r2-h2));
        surface_of_sphere_2 = (4*pi*r2*r2) - (2*pi*r2*h2);

        volume = volume_of_sphere_1 + volume_of_sphere_2;
        surface = surface_of_sphere_1 + surface_of_sphere_2;


        w = rand()%20 - 10 + (ll)volume*sg;


        cout << r1 << " " << r2 << " " << d << " " << w << " " << sg << "\n";
    }
}
