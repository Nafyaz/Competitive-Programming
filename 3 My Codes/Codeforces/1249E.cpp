#include<bits/stdc++.h>
using namespace std;

int n, c, a[200009], b[200009], t[200009], vis[200009];

void func(int f)
{
    if(f == n)
        return;

    if(t[f] + a[f+1] < t[f+1])
    {
        t[f+1] = t[f] + a[f+1];
        func(f+1);
    }

    int sum = 0;
    for(int i = f+1; i <= n; i++)
    {
        sum += b[i];
        if(t[f] + c + sum < t[i])
        {
            t[i] = t[f] + c + sum;
            func(i);
        }
    }

    return;
}

int main()
{
    int i;

    cin >> n >> c;

    for(i = 1; i < n; i++)
        cin >> a[i];
    for(i = 1; i < n; i++)
        cin >> b[i];

    for(i = 1; i <= n; i++)
        t[i] = INT_MAX;
    t[0] = 0;

    func(0);

    for(i = 0; i < n; i++)
        cout << t[i] << " ";
}
