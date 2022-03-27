//Read editorial, didn't understand the proof.
//Note taken. Will come back to it later.
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, s, i;

    cin >> n >> s;

    if(s >= 2*n)
    {
        cout << "YES\n";
        for(i = 0; i+1 < n; i++)
            cout << "2 ";
        cout << s - 2*(n-1) << "\n";
        cout << 1;
    }
    else
        cout << "NO";
}
