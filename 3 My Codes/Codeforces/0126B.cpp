#include<bits/stdc++.h>
using namespace std;

string s;
int n;
int F[1000006];

void KMP()
{
    int i, j;

    F[0] = 0;
    for(i = 1; i < n; i++)
    {
        j = F[i-1];

        while(j > 0 && s[i] != s[j])
            j = F[j-1];

        if(s[i] == s[j])
            j++;

        F[i] = j;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int i, ans;

    cin >> s;
    n = s.size();

    KMP();

    ans = 0;
    for(i = 0; i < n-1; i++)
    {
        if(F[i] == F[n-1])
        {
            ans = F[n-1];
            break;
        }
    }

    if(ans != 0)
        cout << s.substr(0, ans);
    else if(F[F[n-1] - 1] != 0)
        cout << s.substr(0, F[F[n-1] - 1]);
    else
        cout << "Just a legend";
}
