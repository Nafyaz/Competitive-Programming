#include<bits/stdc++.h>
using namespace std;

int x[102], bitCnt[32];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, l, i, j, y, ans;

    cin >> t;

    while(t--)
    {
        cin >> n >> l;

        memset(bitCnt, 0, sizeof bitCnt);
        for(i = 0; i < n; i++)
        {
            cin >> x[i];
            for(j = 0; (1 << j) <= x[i]; j++)
                bitCnt[j] += ((x[i] & (1<<j)) != 0);
        }

//        for(i = 0; i < 32; i++)
//            cout << "i: " << i << " bitCnt: " << bitCnt[i] << "\n";

        y = 0;
        for(i = 0; i < 32; i++)
        {
            if(2*bitCnt[i] - n >= 0)
                y |= (1 << i);
        }

//        int sum = 0, ansSum = 0;
//        for(i = 0; i < n; i++)
//        {
//            sum += __builtin_popcount(x[i] ^ y);
//            ansSum += __builtin_popcount(x[i] ^ ans);
//        }

        cout << y << "\n";

//        cout << "y: " << y << " sum: " << sum << "\n";
//        cout << "ans: " << ans << " ansSum: " << ansSum << "\n";
    }
}
/*
7
3 5 17
18 9 21
3 5 18
18 18 18
1 1 1
1
5 30 1
1 2 3 4 5
6 10 39
99 35 85 46 78 55
2 1 0
0 1
8 8 2
5 16 42 15 83 65 78 42
*/
