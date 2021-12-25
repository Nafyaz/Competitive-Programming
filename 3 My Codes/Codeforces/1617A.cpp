#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int t, i, a, b, c;
    string S, T;

    cin >> t;

    while(t--)
    {
        cin >> S >> T;

        sort(S.begin(), S.end());

        if(T != "abc")
        {
            cout << S << "\n";
            continue;
        }

        a = b = c = -1;
        for(i = 0; i < S.size(); i++)
        {
            if(a == -1 && S[i] == 'a')
                a = i;
            if(b == -1 && S[i] == 'b')
                b = i;
            if(S[i] == 'c')
                c = i;
        }

        if(a != -1 && b != -1 && c != -1)
        {
            for(; b < c; b++, c--)
                swap(S[b], S[c]);
        }

        cout << S << "\n";
    }
}
