#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t, r, b, k, rcount, bcount, gcd;
    cin >> t;
    while(t--)
    {
        cin >> r >> b >> k;

        if(r > b)
            swap(r, b);

        gcd = __gcd(r, b);
        rcount = b / gcd;
        bcount = r / gcd;

        if (rcount == 1)
            cout << "OBEY" << endl;
        else if(((rcount -1)+ bcount -1) / bcount >= k)
            cout << "REBEL" << endl;
        else
            cout << "OBEY" << endl;
    }
}
