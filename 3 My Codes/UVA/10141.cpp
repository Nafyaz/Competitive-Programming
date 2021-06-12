#include<bits/stdc++.h>
using namespace std;

int main()
{
    int caseno = 0, n, p, i, r, mxr;
    double d, mnd;

    string s, propName, ans;

    while(cin >> n >> p)
    {
        getline(cin, s);
        if(!n && !p)
            break;

        if(caseno)
            cout << "\n";

        mxr = 0;

        for(i = 0; i < n; i++)
        {
            getline(cin, s);
        }

        while(p--)
        {
            getline(cin, propName);
            cin >> d >> r;
            getline(cin, s);

            for(i = 0; i < r; i++)
            {
                getline(cin, s);
            }

            if(mxr < r)
            {
                mxr = r;
                mnd = d;
                ans = propName;
            }
            else if(mxr == r && mnd > d)
            {
                mnd = d;
                ans = propName;
            }
        }

        cout << "RFP #" << ++caseno << "\n" << ans << "\n";
    }
}
