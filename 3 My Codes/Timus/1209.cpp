#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n, a, art, i;

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> a;

        a--;
        a *= 2;
        art = sqrt(a);

        if(art*(art+1) == a)
            cout << 1 << " ";
        else
            cout << 0 << " ";
    }

}
