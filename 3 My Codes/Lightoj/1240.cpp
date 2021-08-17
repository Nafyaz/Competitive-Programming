#include<bits/stdc++.h>
using namespace std;

struct point
{
    double x, y, z;

    double dist(point p)
    {
        return sqrt((p.x-x)*(p.x-x) + (p.y-y)*(p.y-y) + (p.z-z)*(p.z-z));
    }
};

int main()
{
    int t, caseno = 0, i;

    double low, high, mid1, mid2, distMid1, distMid2;
    point A, B, P, M1, M2;

    cin >> t;

    while(t--)
    {
        cin >> A.x >> A.y >> A.z;
        cin >> B.x >> B.y >> B.z;
        cin >> P.x >> P.y >> P.z;

        low = 0;
        high = 1;

        for(i = 0; i < 100; i++)
        {
            mid1 = (2*low + high)/3;
            mid2 = (low + 2*high)/3;

            M1.x = (1-mid1)*A.x + mid1*B.x;
            M1.y = (1-mid1)*A.y + mid1*B.y;
            M1.z = (1-mid1)*A.z + mid1*B.z;

            M2.x = (1-mid2)*A.x + mid2*B.x;
            M2.y = (1-mid2)*A.y + mid2*B.y;
            M2.z = (1-mid2)*A.z + mid2*B.z;

            distMid1 = P.dist(M1);
            distMid2 = P.dist(M2);

            if(distMid1 <= distMid2)
                high = mid2;
            else
                low = mid1;
        }

        cout << fixed;
        cout << "Case " << ++caseno << ": " << setprecision(7) << distMid1 << "\n";
    }
}
