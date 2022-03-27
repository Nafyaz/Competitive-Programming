#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll w, m, k, st;

    cin >> w >> m >> k;

    st = m;

    ll rem, digits, canTake;

    while(1)
    {
        digits = log10(m) + 1;
        rem = (ll)pow(10, digits) - m;

        canTake = min(rem, w/digits/k);

//        cout << w << " " << m << " " << k << "\n" << digits << " " << rem << " " << canTake << "\n";

        if(canTake == 0)
            break;

        w -= canTake*digits*k;
        m += canTake;
    }

    cout << m - st;
}
