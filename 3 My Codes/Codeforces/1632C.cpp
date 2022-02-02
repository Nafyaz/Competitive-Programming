#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T, a, b, i, ans;

    cin >> T;

    while(T--)
    {
        cin >> a >> b;

        ans = b-a;

        for(i = 0; a+i < b; i++)
        {
//            cout << "i: " << i << " " << i+1+ ((a+i)|b) - b << "\n";
            ans = min(ans, i+ 1+((a+i)|b) - b);
            ans = min(ans, i+ 1+(a|(b+i)) - b-i);
        }

        cout << ans << "\n";
    }
}
