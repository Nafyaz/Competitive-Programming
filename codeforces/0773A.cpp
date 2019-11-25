//Credit goes to YouKn0wWho
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll i,j,k,n,t,m,x,y,p,q;
    cin >> t;

    while(t--)
    {
        cin >> x >> y >> p >> q;
        if(p == q && x != y || p == 0 && x != 0)
            cout << -1 << endl;
        else if(p == q && x == y || p == 0 && x == 0)
            cout << 0 << endl;
        else
            cout << q*max( (x+p-1)/p, (y-x+q-p-1)/(q-p) ) - y << endl;
    }
}
