#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T, l, r, k;

    cin >> T;

    while(T--)
    {
        cin >> l >> r >> k;

        if(l == r)
        {
            if(l == 1)
                cout << "NO\n";
            else
                cout << "YES\n";
        }
        else if((r-l+1)%2 == 0)
        {
            if(k >= (r-l+1)/2)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        else
        {
            int oddCount = (r-l+1)/2;
            if(l%2 == 1)
                oddCount++;

            if(k >= oddCount)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}
