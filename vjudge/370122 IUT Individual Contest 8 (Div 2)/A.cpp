#include<bits/stdc++.h>
using namespace std;

vector<int> v;
int lcs[1009][1009];

int main()
{
    int i, j, n, m, p;
    string a, b;
    cin >> n >> m >> p;
    cin >> a >> b;


    for(i = 0; i <= n; i++)
        lcs[i][0] = 0;
    for(i = 0; i <= m; i++)
        lcs[0][i] = 0;

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
            if(a[i-1] == b[j-1])
            {
                lcs[i][j] = lcs[i-1][j-1] + 1;
                v.push_back(lcs[i][j]);
            }
            else
                lcs[i][j] = 0;
            cout << setw(4) << lcs[i][j];
        }
        cout << endl;
    }



    sort(v.begin(), v.end(), greater<int>());
    int sum = 0;
    cout << accumulate(v.begin(), v.begin()+min((int)v.size(), p), sum);
}
