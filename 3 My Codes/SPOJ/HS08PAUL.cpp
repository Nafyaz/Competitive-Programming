#include<bits/stdc++.h>
using namespace std;
#define N 10000009

bitset<N> flag, used;
int cnt[10000009];

void sieve()
{
    int i, j;
    flag[0] = flag[1] = 1;
    for(i = 4; i <= N; i += 2)
        flag[i] = 1;
    for(i = 3; i * i <= N; i += 2)
    {
        if(!flag[i])
        {
            for(j = i * i; j <= N; j += 2 * i)
                flag[j] = 1;
        }
    }
}

int main()
{
    sieve();

    int t, n, x, y, p, i;
    for(x = 1; x * x < N; x++)
    {
        for(y = 1; x*x + y*y*y*y < N; y++)
        {
            p = x*x + y*y*y*y;
            if(used[p] == 0 && flag[p] == 0)
                used[p] = 1;
        }
    }

    for(i = 2; i < N; i++)
        cnt[i] = cnt[i-1] + (int)used[i];

//    for(i = 0; i < 10; i ++)
//        cout << cnt[i] << " ";

    cin >> t;
    while(t--)
    {
        cin >> n;

        cout << cnt[n] << endl;
    }
}
