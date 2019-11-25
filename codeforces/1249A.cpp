#include<bits/stdc++.h>
using namespace std;
int main()
{
     int q, a[110], i, n, ans;
     cin >> q;
     while(q--)
     {
         ans = 1;
         cin >> n;
         for(i = 0; i < n; i++)
            cin >> a[i];
         sort(a, a+n);

         for(i = 0; i < n-1; i++)
         {
             if(a[i] + 1 == a[i+1])
             {
                 ans = 2;
                 break;
             }
         }

         cout << ans << endl;
     }
}
