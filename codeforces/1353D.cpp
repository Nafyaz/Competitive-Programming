#include<bits/stdc++.h>
using namespace std;

int a[200009], n, x;

void call(int sz)
{
    int i, z = 0;
    for(i = 0; i < n; i++)
    {
        if(a[i])
            z = 0;
        else
            z++;
        if(z == sz)
        {
            a[i-sz/2] = x++;
            z = 0;
        }
    }
}

int main()
{
    int t, i, sz;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i = 0; i < n; i++)
            a[i] = 0;

        x = 1;
        queue<int> q;
        q.push(n);
        while(!q.empty())
        {
            sz = q.front();
            if(!sz)
                break;
            q.pop();
            call(sz);
            if(sz&1)
                q.push(sz>>1);
            else
            {
                q.push(sz>>1);
                q.push((sz>>1) -1);
            }
        }

        for(i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
}
