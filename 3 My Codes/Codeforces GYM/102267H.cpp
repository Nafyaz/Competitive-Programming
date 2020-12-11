#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define pi acos(-1)

int main()
{
    ld s, v, r;
    cin >> v >> s;
    r = s/2 / sin(pi/v);
    cout << fixed << setprecision(8) <<  pi * r * r << endl;
}
