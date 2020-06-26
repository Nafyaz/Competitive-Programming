#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, n, i;
    string f[110], s[110];
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(i = 0; i < n; i++)
            cin >> f[i] >> s[i];

        for(i = 0; i < n; i++)
        {
            cout << f[i];
            if(count(f, f + n, f[i]) > 1)
                cout << " " << s[i];
            cout << endl;
        }
    }
}
