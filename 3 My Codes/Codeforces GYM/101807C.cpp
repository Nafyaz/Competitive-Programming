#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int q, x;

    cin >> q;

    while(q--)
    {
        cin >> x;

        if(x&(x-1))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}

