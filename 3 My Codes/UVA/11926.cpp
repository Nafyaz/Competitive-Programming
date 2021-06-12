#include<bits/stdc++.h>
using namespace std;
#define N 1000000

bitset<N> bs;

int main()
{
//    freopen("out.txt", "w", stdout);
    int n, m, i, j, st, ed, interval, ans;

    while(cin >> n >> m)
    {
        if(!n && !m)
            break;

        bs.reset();

        ans = 1;

        while(n--)
        {
            cin >> st >> ed;
            for(i = st; i < ed && ans; i++)
            {
                if(bs[i])
                    ans = 0;
                else
                    bs[i] = 1;
            }
        }

        while(m--)
        {
            cin >> st >> ed >> interval;
            for(i = st; i < N && ans; i += interval)
            {
                for(j = i; j < i + ed-st && ans; j++)
                {
                    if(bs[j])
                        ans = 0;
                    bs[j] = 1;
                }
            }
        }

        if(ans)
            cout << "NO CONFLICT\n";
        else
            cout << "CONFLICT\n";
    }
}
