#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, k, i, isPal;
    string s;

    cin >> t;

    while(t--)
    {
        cin >> n >> k >> s;

        isPal = 1;
        for(i = 0; i < n/2; i++)
        {
            if(s[i] != s[n-i-1])
            {
                isPal = 0;
                break;
            }
        }

        if(!isPal && k)
            cout << "2\n";
        else
            cout << "1\n";
    }
}
