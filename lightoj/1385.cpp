#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, caseno = 0;
    long double a, b, c, d1, d2;

    cin >> t;

    while(t--)
    {
        cin >> a >> b >> c;
        cout << "Case " << ++caseno << ": ";
        if(b == 0 || b*b <= a*c)
        {
            cout << -1 << endl;
            continue;
        }
        d1 = a*c/b;
        d2 = a*c*(a+b)*(b+c)/(b*(b*b - a*c));

        cout << fixed;
        cout << setprecision(9) << d1 + d2 << endl;
    }
}
