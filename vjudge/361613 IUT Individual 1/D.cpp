#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i, n, dis[2000], flag;

    while(1)
    {
        cin >> n;
        if(n == 0)
            break;
        for(i = 0; i < n; i++)
            cin >> dis[i];
        sort(dis, dis+n);

        flag = 1;
        for(i = 1; i < n; i++)
        {
            if(dis[i] - dis[i-1] > 200)
            {
                flag = 0;
                break;
            }
        }

        if(1422 - dis[n-1] > 100)
            flag = 0;

//        cout << dis[n-1] << endl;
        cout << (flag? "POSSIBLE" : "IMPOSSIBLE") << endl;
    }
}
/*
2
0
900
8
1400
1200
1000
800
600
400
200
0
0
*/
