#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, j, a[100009], ans[100009], par[100009];

    i = 0;

    while(cin >> a[i++])
        n = i;

    for(i = 0; i < n; i++)
    {
        ans[i] = 1;
        par[i] = -1;
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < i; j++)
        {
            if(a[j] < a[i] && ans[j] + 1 >= ans[i])
            {
                ans[i] = ans[j] + 1;
                par[i] = j;
            }
        }
    }

    int len = 0, x;
    for(i = 0; i < n; i++)
    {
        if(len <= ans[i])
        {
            len = ans[i];
            x = i;
        }
    }

    cout << len << endl << '-' << endl;
    stack<int> s;
    while(x != -1)
    {
        s.push(x);
        x = par[x];
    }

    while(!s.empty())
    {
        cout << a[s.top()] << endl;
        s.pop();
    }
}
