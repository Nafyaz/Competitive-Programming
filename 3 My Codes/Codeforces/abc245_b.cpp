#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, i, a;
    bool contains[2003] = {0};

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> a;
        contains[a] = 1;
    }

    for(i = 0; i < 2003; i++)
    {
        if(!contains[i])
        {
            cout << i << "\n";
            break;
        }
    }
}
