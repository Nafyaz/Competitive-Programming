#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, x[4], y[4];

    cin >> n;

    cout << "INTERSECTING LINES OUTPUT\n";
    while(n--)
    {
        for(i = 0; i < 4; i++)
            cin >> x[i] >> y[i];

        if((y[1]-y[0])*(x[3]-x[2]) == (y[3]-y[2])*(x[1]-x[0]))
        {
            if((y[2]-y[0])*(x[1]-x[0]) == (y[1]-y[0])*(x[2]-x[0]))
                cout << "LINE\n";
            else
                cout << "NONE\n";
        }
        else
        {
            cout << "POINT ";
            double a[2], b[2], c[2], det, px, py;

            a[0] = y[0]-y[1];
            b[0] = x[1]-x[0];
            c[0] = a[0]*x[0] + b[0]*y[0];

            a[1] = y[2]-y[3];
            b[1] = x[3]-x[2];
            c[1] = a[1]*x[2] + b[1]*y[2];

            det = a[0]*b[1]-a[1]*b[0];
            px = (c[0]*b[1]-c[1]*b[0])/det;
            py = (a[0]*c[1]-a[1]*c[0])/det;

            cout << fixed;
            cout << setprecision(2) << px << " " << py << "\n";
        }

    }
    cout << "END OF OUTPUT\n";
}
