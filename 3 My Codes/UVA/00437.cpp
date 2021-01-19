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

    for(j = i; j < n; j++)
    {
        if(mybox[j].y < mybox[i].y)
            ret = max(ret, mybox[j].z + call(j));
    }

    return dp[i] = ret;
}

int main()
{
    int i, tempx, tempy, tempz, caseno = 0;

    while(1)
    {
        cin >> n;
        if(!n)
            break;

        for(i = 0; i < n; i++)
        {
            cin >> tempx >> tempy >> tempz;

            mybox[3*i].x = max(tempx, tempy);
            mybox[3*i].y = min(tempx, tempy);
            mybox[3*i].z = tempz;

            mybox[3*i+1].x = max(tempx, tempz);
            mybox[3*i+1].y = min(tempx, tempz);
            mybox[3*i+1].z = tempy;

            mybox[3*i+2].x = max(tempy, tempz);
            mybox[3*i+2].y = min(tempy, tempz);
            mybox[3*i+2].z = tempx;
        }

        n = 3*n;
        sort(mybox, mybox + n, cmp);

        memset(dp, -1, sizeof dp);
        cout << "Case " << ++caseno << ": " << "maximum height = " << call(0) << "\n";

    }
}
