#include<bits/stdc++.h>
using namespace std;
#define N 1000009
#define ll long long

ll sq[N];

int main()
{
    ll sz, p, i, border, line, col;

    for(i = 1; i < N; i += 2)
        sq[i/2] = i*i;

    while(cin >> sz >> p)
    {
        if(!sz && !p)
            break;

        if(p == 1)
        {
            cout << "Line = " << sz/2+1 << ", column = " << sz/2+1 << ".\n";
            continue;
        }

        border = lower_bound(sq, sq+sz/2, p) - sq;

        line = sz/2 + border;
        col = sz/2 + max(0LL, border - 1);

        p = p - sq[border-1];

        if(p < 2*border+1)
        {
            cout << "Line = " << sz/2+1 + border << ", column = " << sz/2+1 + border-p << ".\n";
            continue;
        }

        p = p - 2*border;
        if(p < 2*border+1)
        {
            cout << "Line = " << sz/2+1 + border-p << ", column = " << sz/2+1 - border << ".\n";
            continue;
        }

        p = p - 2*border;
        if(p < 2*border+1)
        {
            cout << "Line = " << sz/2+1 - border << ", column = " << sz/2+1 - border+p << ".\n";
            continue;
        }

        p = p - 2*border;
        if(p < 2*border+1)
        {
            cout << "Line = " << sz/2+1 - border+p << ", column = " << sz/2+1 + border << ".\n";
            continue;
        }
    }
}
