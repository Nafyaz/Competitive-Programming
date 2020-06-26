#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, x[3], intx1[3], intx2[3], dis, ans;

    while(1)
    {
        cin >> n;
        if(n == 0)
            break;

        intx1[0] = intx1[1] = intx1[2] = INT_MIN;
        intx2[0] = intx2[1] = intx2[2] = INT_MAX;

        while(n--)
        {
            for(i = 0; i < 3; i++)
                cin >> x[i];
            cin >> dis;

            for(i = 0; i < 3; i++)
            {
                intx1[i] = max(intx1[i], x[i]);
                intx2[i] = min(intx2[i], x[i] + dis);
            }
        }

        ans = 1;

        for(i = 0; i < 3; i++)
        {
//            cout << intx1[i] << " " << intx2[i] << endl;
            ans = ans * max(0, intx2[i] - intx1[i]);
        }
        cout << ans << endl;
    }
}
/*
2
0  0  0  10
9  1  1  5
3
0  0  0  10
9  1  1  5
8  2  2  3
0
*/
