#include<bits/stdc++.h>
using namespace std;

int lps[3009][3009];

int main()
{
    string a, ans;
    int i, j, n;
    cin >> a;
    n = a.size();

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


    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= n; j++)
            cout << lps[i][j] << " ";
        cout << "\n";
    }
}
