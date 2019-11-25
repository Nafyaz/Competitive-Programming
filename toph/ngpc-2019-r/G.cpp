#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll t, i, a, b, k, n, l, r;
    cin >> t;

    while(t--)
    {
        cin >> a >> k >> l >> r;

        n = 1LL << k;
        if((a&n) == 0)
        {
            cout << "Even" << endl;
            continue;
        }

//        ll low, high;
//
//        low = l&n ?  (l&(n-1)) + 1: 0;
//        high = r&n ? (r&(n-1)) + 1: 0;
//
//        low += (l >> (k+1)) << k;
//        high += (r >> (k+1)) << k;
//
//        ll Count = high - low;
//
//        if(l&n)
//            Count++;
//
//        if(!Count)
//        {
//            cout << "Even" << endl;
//            continue;
//        }
//
//        bool firstParity;
//        if(l&n)
//            firstParity = l&1;
//        else
//        {
//            if(l < n)
//                firstParity = 0;
//            else
//            {
//                low = l >> (k+1);
//                low++;
//                low = low << (k+1);
//                low += n;
//
//                firstParity = low&1;
//            }
//        }
//
//        if(Count&1)
//            cout << (firstParity? "Even" : "Odd") << endl;
//        else
//            cout << "-_-" << endl;


        ll ans = 0;
        for(i = l; i <= r; i++)
        {
            if(i&n == 0)
            {
                i = i >> k;
                i++;
                i << k;
                continue;
            }

            ans = (ans + i)&1;
        }

        cout << (ans? "Odd" : "Even") << endl;
    }
}
