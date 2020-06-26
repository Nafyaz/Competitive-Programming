#include<bits/stdc++.h>
using namespace std;

int ans[15];

int func(int n)
{
    if(ans[n])
        return ans[n];
    for(int i = 0; i < n; i++)
    {
        ans[n] += func(i) * func(n-i-1);
    }
    return ans[n];
}

int main()
{
    int n;
    ans[0] = ans[1] = 1;
    scanf("%d", &n);
    while(1)
    {
        cout << func(n) << endl;

        if(scanf("%d", &n) == 1)
            cout << endl;
        else
            break;
    }
}

