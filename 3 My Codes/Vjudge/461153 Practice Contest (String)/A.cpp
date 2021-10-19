#include<bits/stdc++.h>
using namespace std;

int LPS[200005];

void KMP(string s)
{
    int i, j;

    LPS[0] = 0;

    for(i = 1; i < s.size(); i++)
    {
        j = LPS[i-1];

        while(j > 0 && s[i] != s[j])
            j = LPS[j-1];

        if(s[i] == s[j])
            j++;

        LPS[i] = j;
    }
}

int main()
{
    int T, n, q, p, k;
    string s;

    cin >> T;

    while(T--)
    {
        cin >> n >> q >> s;

        KMP(s);

        while(q--)
        {
            cin >> p >> k;


        }
    }
}
