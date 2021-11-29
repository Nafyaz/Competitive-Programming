#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i;
    string a, b, ans = "Easy";

    cin >> a >> b;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    for(i = 0; i < min(a.size(), b.size()); i++)
    {
        if(a[i]-'0' + b[i]-'0' > 9)
            ans = "Hard";
    }

    cout << ans;
}
