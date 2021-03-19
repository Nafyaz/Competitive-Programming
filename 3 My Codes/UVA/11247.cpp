#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll m, x;

    while(cin >> m >> x)
    {
        if(!m && !x)
            break;

        if(m == 1 || x == 100)
            cout << "Not found\n";
        else if((100*(m-1) - 1)/(100-x) >= m)
            cout << (100*(m-1) - 1)/(100-x) << "\n";
        else
            cout << "Not found\n";
    }
}
