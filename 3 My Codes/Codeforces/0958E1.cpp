#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct Point
{
public:
    ll x, y;
};

ll r, b;
ll baseToShip[11];

Point ship[11], base[11];

bool interSect(Point p1, Point p2, Point p3, Point p4)
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

    ll det = a1*b2 - b1*a2;

//    cout << det << "\n";

    if(!det)
        return 0;

    ll px = (b2*c1 - b1*c2);
    ll py = (a1*c2 - a2*c1);

//    cout << px << " " << py << "\n";

    if(px < min(p1.x*det, p2.x*det) || px > max(p1.x*det, p2.x*det) || py < min(p1.y*det, p2.y*det) || py > max(p1.y*det, p2.y*det))
        return 0;
    if(px < min(p3.x*det, p4.x*det) || px > max(p3.x*det, p4.x*det) || py < min(p3.y*det, p4.y*det) || py > max(p3.y*det, p4.y*det))
        return 0;

    return 1;
}

bool isOk(ll i, ll j)
{
    if(i == 0)
        return 1;

    for(ll k = 0; k < i; k++)
    {
//        cout << "k: " << k << "; i: " << i << "; j: " << j << "\n";
        if(interSect(base[k], ship[baseToShip[k]], base[i], ship[j]))
            return 0;
    }

    return 1;
}

bool call(ll i, ll mask)
{
    ll j;
//    cout << i << " " << mask << "\n";
//    for(j = 0; j < b; j++)
//        cout << baseToShip[i] << " ";
//    cout << "\n\n";

    if(i == b)
        return 1;

    for(j = 0; j < r; j++)
    {
//        if(i == 1 && mask == 1 && j == 1)
//        {
//            cout << "lol: " << (mask&(1<<j)) << "\n";
//            for(ll k = 0; k < b; k++)
//                cout << baseToShip[k] << " ";
//            cout << "\n";
//            cout << "isOk: " << isOk(i, j) << "\n";
//        }

        if((mask&(1<<j)) == 0 && isOk(i, j))
        {
            baseToShip[i] = j;
            if(call(i+1, mask | (1<<j)))
                return 1;
        }
    }

    return 0;
}

int main()
{
    ll i;

    cin >> r >> b;

    for(i = 0; i < r; i++)
        cin >> ship[i].x >> ship[i].y;
    for(i = 0; i < b; i++)
        cin >> base[i].x >> base[i].y;

    if(r != b)
    {
        cout << "No";
        return 0;
    }

//    cout << isOk(1, 1);
//    cout << interSect(base[0], ship[0], base[1], ship[1]);

    cout << (call(0, 0)? "Yes" : "No");
}
