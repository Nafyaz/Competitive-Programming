#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, caseno = 0;
    double x, y, c, c2, tl, th, tmid, theta1, theta2;

    scanf("%d", &t);

    while(t--)
    {
        cin >> x >> y >> c;
        th = min(x, y);
        tl = 0;

        do
        {
            tmid = (th+tl)/2;
            theta1 = acos(tmid/x);
            theta2 = acos(tmid/y);

            c2 = tmid / (1/tan(theta1) + 1/tan(theta2));
            if(c > c2)
                th = tmid;
            else
                tl = tmid;
            //cout << c2 << " " << tmid << endl;

        }while(abs(c2 - c) > 0.0000001);

        cout << "Case " << ++caseno << ":" << " " << fixed << setprecision(9) << tmid << endl;
    }
}

