#include<bits/stdc++.h>
using namespace std;

bool freq[100005][26];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T, n, m, i, j;
    string s;

    cin >> T;

    while(T--)
    {
        cin >> n >> m;

        for(i = 0; i < 2*n-1; i++)
        {
            cin >> s;

            for(j = 0; j < m; j++)
                freq[j][s[j] - 'a'] ^= 1;
        }

        for(i = 0; i < m; i++)
        {
            for(j = 0; j < 26; j++)
            {
                if(freq[i][j])
                {
                    cout << char('a' + j);
                    freq[i][j] = 0;
                }
            }
        }

        cout << "\n";
    }
}
