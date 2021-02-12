#include<bits/stdc++.h>
using namespace std;

int main()
{
    double Ax, Ay, Bx, By, Cx, Cy;
    double a, b, c, s, delta;
    double h, k, r;

    while(cin >> Ax >> Ay >> Bx >> By >> Cx >> Cy)
    {
        a = sqrt((Bx-Cx)*(Bx-Cx) + (By-Cy)*(By-Cy));
        b = sqrt((Ax-Cx)*(Ax-Cx) + (Ay-Cy)*(Ay-Cy));
        c = sqrt((Ax-Bx)*(Ax-Bx) + (Ay-By)*(Ay-By));

        s = (a + b + c) / 2;
        delta = sqrt(s*(s-a)*(s-b)*(s-c));

        r = a*b*c/4/delta;

        double a1, b1, c1; //a1*h + b1*k = c1
        double a2, b2, c2; //a2*h + b2*k = c2

        a1 = 2*(Ax - Bx);
        b1 = 2*(Ay - By);
        c1 = (Ax + Bx)*(Ax - Bx) + (Ay + By)*(Ay - By);

        a2 = 2*(Bx - Cx);
        b2 = 2*(By - Cy);
        c2 = (Bx + Cx)*(Bx - Cx) + (By + Cy)*(By - Cy);

        h = (c1*b2 - b1*c2) / (a1*b2 - b1*a2);
        k = (a1*c2 - c1*a2) / (a1*b2 - b1*a2);

        cout << fixed;
        cout << setprecision(3) << "(x" << (h<=0? " + " : " - ") << abs(h) << ")^2 + (y" <<  (k<=0? " + " : " - ") << abs(k) << ")^2 = " << r << "^2\n";

        double e = h*h + k*k - r*r;
        cout << setprecision(3) << "x^2 + y^2" << (h<=0? " + " : " - ") << abs(2*h) << "x" << (k<=0? " + " : " - ") << abs(2*k) << "y" << (e>=0? " + " : " - ") << abs(e) << " = 0\n\n";
    }
}
