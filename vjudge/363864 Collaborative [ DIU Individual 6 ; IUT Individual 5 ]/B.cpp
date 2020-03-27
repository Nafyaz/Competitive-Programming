#include<bits/stdc++.h>
using namespace std;

int val[10009];

int main()
{
    int n, x, y, flag;
    for(x = 0; x*x*x < 10009; x++)
    {
        val[x*x*x] = x;
    }
    while(1)
    {
        cin >> n;
        if(!n)
            return 0;
        flag = 0;
        for(y = 1; y*y*y < n; y++)
        {
            if(val[n - y*y*y])
            {
                flag = 1;
                cout << val[n-y*y*y] << " " << y << endl;
                break;
            }
        }

        if(!flag)
            cout << "No solution" << endl;
    }
}
