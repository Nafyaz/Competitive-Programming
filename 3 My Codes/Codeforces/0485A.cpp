#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll a, m;
    bool found[100005] = {0};

    cin >> a >> m;

    a = a%m;
    while(!found[a])
    {
        found[a] = 1;

        a = (2*a)%m;
        if(a == 0)
        {
            cout << "Yes";
            return 0;
        }
    }

    cout << "No";
}
