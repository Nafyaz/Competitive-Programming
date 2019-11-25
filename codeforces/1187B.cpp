#include<bits/stdc++.h>
using namespace std;

int num[200010][26], x = 1;

bool check(int *f, int i)
{
    for(int j = 0; j < 26; j++)
    {
        if(f[j] > num[i][j])
            return 0;
//        if(x)
//            printf("%d ", f[j]);
    }
    x = 0;
    return 1;
}


int main()
{
    int n, i, j, m, l, r, mid, f_name[26];
    string s, t;

    scanf("%d", &n);
    cin >> s;

    for(i = 1; i <= n; i++)
    {
        for(j = 0; j < 26; j++)
            num[i][j] = num[i-1][j];
        num[i][s[i-1] - 'a']++;
    }

//    for(i = 0; i < 26; i++)
//        printf("%c ", 'a' + i);
//    printf("\n");
//    for(i = 1; i <= n; i++)
//    {
//        for(j = 0; j < 26; j++)
//            printf("%d ", num[i][j]);
//        printf("\n");
//    }

    scanf("%d", &m);
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < 26; j++)
            f_name[j] = 0;

        cin >> t;

        for(j = 0; j < t.size(); j++)
            f_name[t[j] - 'a']++;

        l = 1; r = n;

        while(l <= r)
        {
            mid = (l+r)/2;
//            printf("%d %d %d ", l, r, mid);
//            printf("\n");
            if(check(f_name, mid))
                r = mid - 1;
            else
                l = mid + 1;
        }
        printf("%d\n", l);
    }
}
