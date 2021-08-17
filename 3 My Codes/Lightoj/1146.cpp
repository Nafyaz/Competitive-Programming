#include<bits/stdc++.h>
using namespace std;

struct point
{
    double x, y;

    double dist(point p)
    {
        return sqrt((p.x - x)*(p.x - x) + (p.y - y)*(p.y - y));
    }
};

int main()
{
    int t, caseno = 0, i;
    double low, mid1, mid2, high;
    double distMid1, distMid2;

    point A, B, C, D, M1, M2;

    cin >> t;

    while(t--)
    {
        cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;

        low = 0;
        high = 1;

        for(i = 0; i < 100; i++)
        {
            mid1 = (2*low + high)/3;
            mid2 = (low + 2*high)/3;

            M1.x = (1-mid1)*A.x + mid1*B.x;
            M1.y = (1-mid1)*A.y + mid1*B.y;
            M2.x = (1-mid1)*C.x + mid1*D.x;
            M2.y = (1-mid1)*C.y + mid1*D.y;
            distMid1 = M1.dist(M2);

            M1.x = (1-mid2)*A.x + mid2*B.x;
            M1.y = (1-mid2)*A.y + mid2*B.y;
            M2.x = (1-mid2)*C.x + mid2*D.x;
            M2.y = (1-mid2)*C.y + mid2*D.y;
            distMid2 = M1.dist(M2);

//            cout << fixed;
//            cout << setprecision(7) << mid1 << " " << distMid1 << "; " << mid2 << " " << distMid2 << "\n";

            if(distMid1 <= distMid2)
                high = mid2;
            else
                low = mid1;
        }

        cout << fixed;
        cout << "Case " << ++caseno << ": " << setprecision(7) << distMid2 << "\n";
    }
}
