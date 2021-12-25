#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    ll t, a, b, s, flag, pow, adigit, sdigit, sdec;

    cin >> t;

    while(t--)
    {
        cin >> a >> s;

        pow = 1;
        flag = 1;
        b = 0;
        while(s)
        {
            adigit = a%10;
            sdigit = s%10;
            sdec = s%100;

            if(adigit > sdec)
            {
                flag = 0;
                break;
            }

            if(adigit <= sdigit)
            {
                b = (sdigit - adigit)*pow + b;
                s /= 10;
            }
            else if(sdec - adigit > 9)
            {
                flag = 0;
                break;
            }
            else
            {
                b = (sdec - adigit)*pow + b;
                s /= 100;
            }

            pow *= 10;
            a /= 10;
        }

        if(a)
            flag = 0;

        if(!flag)
            cout << "-1\n";
        else
            cout << b << "\n";
    }
}
