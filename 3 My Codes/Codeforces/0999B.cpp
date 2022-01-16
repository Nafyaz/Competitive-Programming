#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int i, n;
    string s;

    cin >> n >> s;

    for(i = 1; i <= n; i++)
    {
        if(n%i == 0)
            reverse(s.begin(), s.begin()+i);
    }

    cout << s;
}
