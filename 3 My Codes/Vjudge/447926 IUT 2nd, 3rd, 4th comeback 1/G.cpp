#include<bits/stdc++.h>
using namespace std;

int nextAlive[300009];
int killedBy[300009];

int findNext(int i)
{
    if(i == nextAlive[i])
        return i;
    return nextAlive[i] = findNext(nextAlive[i]);
}

int main()
{
    int n, m, i, l, r, x;

    cin >> n >> m;

    for(i = 1; i <= n+1; i++)
    {
        nextAlive[i] = i;
    }

    while(m--)
    {
        cin >> l >> r >> x;

        for(i = findNext(l); i <= r; i = findNext(i+1))
        {
            if(i != x)
            {
                killedBy[i] = x;
                nextAlive[i] = findNext(i+1);
            }
        }
    }

    for(i = 1; i <= n; i++)
        cout << killedBy[i] << " ";
}
