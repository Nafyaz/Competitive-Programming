#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool checkBeauty(string a)
{
    while(a.size() > 1)
    {
        if(a.back() != '0')
            return 0;
        a.pop_back();
    }

    return (a == "1");
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, i, zeroCnt = 0, isZero = 0;
    string a, ugly = "1";

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> a;

        if(a == "0")
            isZero = 1;
        if(isZero)
            continue;

        if(!checkBeauty(a))
        {
            ugly = a;
            continue;
        }

        zeroCnt += (a.size() - 1);
    }

    if(isZero)
        cout << 0;
    else
        cout << ugly << string(zeroCnt, '0');
}
