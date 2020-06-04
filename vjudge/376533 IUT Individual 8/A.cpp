#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define pi acos(-1)

int main()
{
    ld a, b, v, A, s, x, y;
    while(1)
    {
        cin >> a >> b >> v >> A >> s;
        if(!a && !b && !v && !A && !s)
            return 0;

//        cout << pi << endl;
        ld d = v*s;
        A = pi/180*A;
        x = (d*cos(A) + a/2) /a;
        y = (d*sin(A) + b/2) /b;
        cout << (int)x << " " << (int)y << endl;
    }
}
