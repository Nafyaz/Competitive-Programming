#include<bits/stdc++.h>
using namespace std;

int lps[1009][1009];

int main()
{
//    freopen("out.txt", "w", stdout);
    string a, ans;
    int i, j, n, t;

    cin >> t;
    getline(cin, a);

    while(t--)
    {
        getline(cin, a);
        n = a.size();

        if(!n)
        {
            cout << "0\n";
            continue;
        }

        memset(lps, 0, sizeof lps);

        for(i = 1; i <= n; i++)
            lps[i][i] = 1;

        for(i = 2; i <= n; i++)
        {
            for(j = 1; j <= n - i + 1; j++)
            {
                if(a[j-1] == a[j+i-2])
                    lps[j][j+i-1] = lps[j+1][j+i-2] + 2;
                else
                    lps[j][j+i-1] = max(lps[j+1][j+i-1], lps[j][j+i-2]);
            }
        }

        cout << lps[1][n] << "\n";
    }
}

