//Credit goes to NiloyRafi
#include<bits/stdc++.h>
using namespace std;

int n,m,v,a[300009],b[300009],i;

bool check(int x,int y)
{
    for(int i = 0; i<m; i++)
    {
        if(a[i]==x||a[i]==y|| b[i]==x||b[i]==y)
            continue;
        if(y)
            return false;
        return (check(x,a[i])||check(x,b[i]));
    }

    return true;
}

int main()
{
    cin >> n >> m;
    for(i = 0; i < m; i++)
        cin>>a[i]>>b[i];

    if(check(a[0],0) || check(b[0],0))
        cout<<"YES";
    else
        cout<<"NO";
}
