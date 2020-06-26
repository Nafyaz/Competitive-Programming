#include<bits/stdc++.h>
using namespace std;



int main()
{
    long long i, n, k, a, b;
    cin >> n >> k >> a >> b;

    if(k == 1)
    {
        cout << (n-1) * a;
        return 0;
    }

    i = 1;
    long long cost = 0;
    while(1)
    {
        cout << cost << endl;
        if(i*k <= n)
        {
            cost += min(a*(i*(k-1)), b);
            i *= k;
            if(i == n)
                break;
        }
        else
        {
            cost += a*(n - i);
            break;
        }
    }

    cout << cost;
}
