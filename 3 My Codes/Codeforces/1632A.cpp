#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T, n;
    string s;

    cin >> T;

    while(T--)
    {
        cin >> n >> s;

        cout << ((n < 3 && s != "00" && s != "11")? "YES\n" : "NO\n");
    }
}
