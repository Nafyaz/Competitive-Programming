#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q, n, k, i, j, c, ans, change;
    char col[4] = "RGB";
    string s;
    scanf("%d", &q);
    while(q--)
    {
        ans = INT_MAX;
        scanf("%d %d\n", &n, &k);
        cin >> s;
        for(i = 0; i < n-k+1; i++)
        {
            for(c = 0; c < 3; c++)
            {
                change = 0;
                for(j = i; j < i+k; j++)
                {
                    if(s[j] != col[(c+j)%3])
                        change++;
                }
                ans = min(ans, change);
            }
        }
        printf("%d\n", ans);
    }
}
