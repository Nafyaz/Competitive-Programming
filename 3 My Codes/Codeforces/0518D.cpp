#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, t, i;
    double p, mul, ans;

    cin >> n >> p >> t;

    ans = 0;

    for(i = 1, mul = p; i <= t; i++, mul *= p)
    {

        if(i < n)
            ans += i*mul*(1-p);
        else if(i == n)
            ans += i*mul;
        else
            break;

        cout << "i: " << i << "; ans: " << ans << "\n";
    }

//    cout << ans;
}
