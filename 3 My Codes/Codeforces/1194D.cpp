#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, n, k;

    cin >> T;

    while(T--)
    {
        cin >> n >> k;

        if(k%3 != 0)
        {
            if(n%3 != 0)
                cout << "Alice\n";
            else
                cout << "Bob\n";
        }
        else
        {
            n = n%(k+1);
            if(n%3 != 0 || n == k)
                cout << "Alice\n";
            else
                cout << "Bob\n";
        }
    }
}
/*
n:      0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26  27  28  29  30
k%3!=0: 0   1   1   0   1   1   0   1   1   0   1   1   0   1   1   0   1   1   0   1   1   0   1   1   0   1   1   0   1   1   0
k = 3:  0   1   1   1   0   1   1   1   0   1   1   1   0   1   1   1   0   1   1   1   0   1   1   1   0   1   1   1   0   1   1
k=6:    0   1   1   0   1   1   1   0   1   1   0   1   1   1   0   1   1   0   1   1   1   0   1   1   0   1   1   1   0   1   1
*/
