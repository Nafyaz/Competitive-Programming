#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, ans = 0;
    string a, b;
    map<char, int> freq;

    cin >> n >> a >> b;

    for(i = 0; i < n/2; i++)
    {
        char a1 = a[i], a2 = a[n-i-1];
        char b1 = b[i], b2 = b[n-i-1];

        if(a1 > a2)
            swap(a1, a2);
        if(b1 > b2)
            swap(b1, b2);

        if((a1 == b1 && a2 == b2) || (a1 == a2 && b1 == b2))
            continue;

        if(a1 == b1 || a1 == b2 || a2 == b1 || a2 == b2 || b1 == b2)
            ans++;
        else
            ans += 2;
    }

    if(n%2 == 1 && a[n/2] != b[n/2])
        ans++;

    cout << ans;
}
