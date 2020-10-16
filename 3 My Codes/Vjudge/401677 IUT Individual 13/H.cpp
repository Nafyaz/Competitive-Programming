#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n, h[100009], i, x, mx, temp;
    while(1)
    {
        cin >> n;

        if(!n)
            return 0;

        stack<ll> s;

        s.push(0);
        mx = 0;

        for(i = 1; i <= n+1; i++)
        {
            if(i <= n)
                cin >> h[i];
            else
                h[i] = 0;

            if(s.empty() || h[s.top()] <= h[i])
                s.push(i);
            else
            {
                while(h[s.top()] > h[i] && s.top() != 0)
                {
                    temp = s.top();
                    s.pop();
                    x = h[temp] * (i - s.top() - 1);
//                    cout << "area: " << x << endl;
                    mx = max(mx, x);
                }
                s.push(i);
            }

        }

        cout << mx << "\n";
    }

}

