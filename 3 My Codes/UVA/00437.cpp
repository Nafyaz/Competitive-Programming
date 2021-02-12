#include<bits/stdc++.h>
using namespace std;

class box
{
public:
    int x, y, z;
};

int n, dp[100];
box mybox[100];

bool cmp(box a, box b)
{
    if(a.x != b.x)
        return a.x > b.x;
    return a.y > b.y;
}

int call(int i)
{
    if(dp[i] != -1)
        return dp[i];

    int j, ret = 0;

    for(j = i+1; j < n; j++)
    {
        if(mybox[j].y < mybox[i].y && mybox[j].x < mybox[i].x)
            ret = max(ret, call(j));
    }

    return dp[i] = ret + mybox[i].z;
}

int main()
{
//    freopen("out.txt", "w", stdout);
    int i, tempx, tempy, tempz, caseno = 0;

    mybox[0].x = INT_MAX;
    mybox[0].y = INT_MAX;
    mybox[0].z = 0;

    while(1)
    {
        cin >> n;
        if(!n)
            break;

        for(i = 1; i <= n; i++)
        {
            cin >> tempx >> tempy >> tempz;

            mybox[3*i-2].x = max(tempx, tempy);
            mybox[3*i-2].y = min(tempx, tempy);
            mybox[3*i-2].z = tempz;

            mybox[3*i-1].x = max(tempx, tempz);
            mybox[3*i-1].y = min(tempx, tempz);
            mybox[3*i-1].z = tempy;

            mybox[3*i].x = max(tempy, tempz);
            mybox[3*i].y = min(tempy, tempz);
            mybox[3*i].z = tempx;
        }

        n = 3*n + 1;
        sort(mybox, mybox + n, cmp);

//        memset(dp, -1, sizeof dp);
//        call(0);
//        for(i = 0; i < n; i++)
//        {
//            cout << mybox[i].x << " " << mybox[i].y << " " << mybox[i].z;
//            cout << setw(4) << dp[i] << "\n";
//        }


        memset(dp, -1, sizeof dp);
        cout << "Case " << ++caseno << ": " << "maximum height = " << call(0) << "\n";

    }
}
/*
2
1  1  1
1  2  1
2
100 100 100
102  98 100
*/
