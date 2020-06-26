#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long t, x, y, p, q, i, a, b;
    cin >> t;

    while(t--)
    {
        cin >> x >> y >> p >> q;
        if(p == 1 && q == 1 && x < y)
        {
            cout << -1 << endl;
            continue;
        }
        else if(p == 1 && q == 1)
        {
            cout << 0 << endl;
            continue;
        }
        else if(p == 0 && x > 0)
        {
            cout << -1 << endl;
            continue;
        }
        else if(p == 0)
        {
            cout << 0 << endl;
            continue;
        }

        i = max({y/q, x/p, (y-x)/(q-p)});
        while(1)
        {
            b = q*i - y;
            a = p*i - x;

            if(b >= 0 && a >= 0 && a <= b)
            {
                cout << b << endl;
                break;
            }

            i++;
        }
    }
}
