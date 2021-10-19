#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, cnt, p[102];
    string s;

    cin >> n;

    for(i = 0; i < n; i++)
        cin >> p[i];
    getline(cin, s);

    for(i = 0; i < n; i++)
    {
        getline(cin, s);

        cnt = 0;
        for(auto u : s)
        {
            if(u == 'a' || u == 'e' || u == 'i' || u == 'o' || u == 'u' || u == 'y')
                cnt++;
        }

        if(cnt != p[i])
        {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
}
