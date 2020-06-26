#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, i, n, k, p, q;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(i = 1; i <= n; i++)
        {
            if(k <= i)
            {
                p = i;
                q = k-1;
                break;
            }
            k -= i;
        }

        for(i = n-1; i >= 0; i--)
        {
            if(i != p && i != q)
                cout << 'a';
            else
                cout << 'b';
        }
        cout << endl;
    }
}
