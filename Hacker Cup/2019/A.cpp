#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("Ain.txt", "r", stdin);
    freopen("Aout.txt", "w", stdout);

    int i, len, t, caseno = 0, dot, B;
    scanf("%d", &t);
    string s;

    while(t--)
    {
        cin >> s;
        len = s.size();
        dot = B = 0;
        for(i = 1; i < len; i++)
        {
            if(s[i] == 'B')
                B++;
            else if(s[i] == '.')
                dot++;
        }
        printf("Case #%d: ", ++caseno);
        if(!dot || !B)
        {
            printf("N\n");
            continue;
        }
        dot > B? printf("N\n") : printf("Y\n");
    }
}
