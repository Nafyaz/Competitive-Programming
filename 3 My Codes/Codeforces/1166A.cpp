#include<bits/stdc++.h>
using namespace std;
int nC2(int n)
{
    return n*(n - 1) / 2;
}
int main()
{
    int n, ans = 0;
    scanf("%d", &n);
    int i, a[26] = {0};
    string s;
    for(i = 0; i < n; i++)
    {
        cin >> s;
        a[s[0] - 'a'] ++;
    }
    for(i = 0; i < 26; i++)
    {
        ans += nC2(a[i]/2) + nC2(a[i] - a[i]/2);
    }
    printf("%d", ans);
}
