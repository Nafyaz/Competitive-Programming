#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
     ll t, caseno = 0, n, i, j, x1, x2, y1, y2, a, b, c, d;

     cin >> t;

     while(t--)
     {
         cin >> n;
         y1 = x1 = INT_MIN;
         y2 = x2 = INT_MAX;
         for(i = 0; i < n; i++)
         {
             cin >> a >> b >> c >> d;
             x1 = max(x1, a);
             y1 = max(y1, b);
             x2 = min(x2, c);
             y2 = min(y2, d);
         }

         cout << "Case " << ++caseno << ": " << max(0LL, x2 - x1)*max(0LL, y2 - y1) << endl;
     }
}
