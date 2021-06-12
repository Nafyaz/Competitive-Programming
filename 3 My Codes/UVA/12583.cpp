#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, n, k, i, j, caseno = 0;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> n >> k >> s;
        int ans = 0;

        for(i = 0; i < n; i++)
        {
            for(j = max(0, i - k); j < i; j++)
            {
                if(s[j] == s[i])
                {
                    ans++;
                    break;
                }
            }
        }
        printf("Case %d: %d\n", ++caseno, ans);
    }
}

