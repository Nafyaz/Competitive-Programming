#include<bits/stdc++.h>
using namespace std;
#define N 100009

int flag[N/64];

void bitsieve()
{
    int i, j;
    for(i = 3; i < N; i += 2)
    {
        if(i%100 == 55)
            cout << i << endl;
        if((flag[i/64] & (1 << ((i%64) >> 1))) == 0)
        {
            for(j = i * i; j < N; j += 2 * i)
                flag[j/64] |= (1 << ((j%64) >> 1));
        }
    }
}

int main()
{
    bitsieve();
    cout << "lol";
//    for(int i = 3; i < 100; i += 2)
//    {
//        cout << i << " " << (flag[i/64] & (1 << (i >> 1))) << endl;
//    }
    int t, n, x, y, p, ans;
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n < 2)
        {
            cout << 0 << endl;
            continue;
        }
        ans = 1;
        for(x = 1; x * x < n; x++)
        {
            for(y = 1; x*x + y*y*y*y <= n; y++)
            {
                p = x*x + y*y*y*y;
                if((p & 1) && (flag[p/64] & (1 << (p >> 1))) == 0)
                {
                    cout << x << " " << y << " " << p << endl;
                    ans++;
                }
            }
        }

        cout << ans << endl;
    }
}
