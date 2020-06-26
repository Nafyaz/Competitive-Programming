//slight modification after reading tutorial
//we don't need flag, lol
//modification2: we don't need len as well -_-
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i;
    scanf("%d", &n);
    string s;
    cin >> s;

    char x[10];
    for(i = 1; i < 10; i++)
        cin >> x[i];

    for(i = 0; i < n; i++)
    {
        //printf("%c %c\n", s[i], x[s[i] - '0']);
        if(s[i] < x[s[i] - '0'])
        {
            while(i < n && s[i] <= x[s[i] - '0'])
            {
                s[i] = x[s[i] - '0'];
                i++;
            }
            break;
        }
    }
    cout << s;
}
