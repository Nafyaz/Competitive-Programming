#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, a[1009], b[1009];
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> a[i];

    int dir, cnt, turn, mn = INT_MAX;

    dir = 1, cnt = 0, i = 0, turn = 0;
    memset(b, 0, sizeof b);
    while(cnt < n)
    {
        while(i >= 0 && i < n)
        {
            if(a[i] <= cnt && b[i] == 0)
            {
                cnt++;
                b[i] = 1;
            }
            i += dir;
        }
        i = (dir == 1? n-1 : 0);
        turn++;
        dir *= -1;
    }
    mn = min(mn, turn-1);

//    dir = -1, cnt = 0, i = n-1, turn = 0;
//    memset(b, 0, sizeof b);
//    while(cnt < n)
//    {
//        while(i >= 0 && i < n)
//        {
//            if(a[i] <= cnt && b[i] == 0)
//            {
//                cnt++;
//                b[i] = 1;
//            }
//            i += dir;
//        }
//        i = (dir == 1? n-1 : 0);
//        turn++;
//        dir *= -1;
//    }
//    mn = min(mn, turn-1);

    cout << mn;
}
