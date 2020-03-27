#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long t, n, k, x, p, q, i;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        x = sqrt(2*k);

        if(x*(x+1)/2 < k)
            x++;

        p = x;
        q = k - x*(x-1)/2-1;

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
