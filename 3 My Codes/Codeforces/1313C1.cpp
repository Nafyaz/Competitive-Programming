#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n, m[1003], i, j, mxfloors, floors, idx, mn;

    cin >> n;

    for(i = 0; i < n; i++)
        cin >> m[i];

    mxfloors = 0;
    idx = -1;
    for(i = 0; i < n; i++)
    {
        floors = m[i];
        mn = m[i];
        for(j = i-1; j >= 0; j--)
        {
            mn = min(mn, m[j]);
            floors += mn;
        }

        mn = m[i];
        for(j = i+1; j < n; j++)
        {
            mn = min(mn, m[j]);
            floors += mn;
        }

        if(floors > mxfloors)
        {
            mxfloors = floors;
            idx = i;
        }
    }

    for(i = idx-1; i >= 0; i--)
        m[i] = min(m[i], m[i+1]);
    for(i = idx+1; i < n; i++)
        m[i] = min(m[i], m[i-1]);

    for(i = 0; i < n; i++)
        cout << m[i] << " ";
}
