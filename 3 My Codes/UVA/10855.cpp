#include<bits/stdc++.h>
using namespace std;

string s1[1000], s2[1000];

void Rotate(int n)
{
    string temp[1000], ts;
    int i, j;
    for(i = 0; i < n; i++)
    {
        ts = "";
        for(j = n-1; j >= 0; j--)
            ts = ts + s2[j][i];
        temp[i] = ts;
    }

    for(i = 0; i < n; i++)
        s2[i] = temp[i];
}

bool check(int i, int j, int n)
{
    for(int x = 0; x < n; x++)
    {
        for(int y = 0; y < n; y++)
        {
            if(s1[x+i][y+j] != s2[x][y])
                return false;
        }
    }

    return true;
}

int main()
{
    int N, n, i, j, cnt, ans;

    while(cin >> N >> n)
    {
        if(!N && !n)
            break;

        for(i = 0; i < N; i++)
            cin >> s1[i];

        for(i = 0; i < n; i++)
            cin >> s2[i];

        cnt = 4;
        while(cnt--)
        {
            ans = 0;
            for(i = 0; i <= N-n; i++)
            {
                for(j = 0; j <= N-n; j++)
                {
                    if(check(i, j, n))
                        ans++;
                }
            }

//            for(i = 0; i < n; i++)
//            {
//                for(j = 0; j < n; j++)
//                    cout << s2[i][j];
//                cout << "\n";
//            }
//            cout << "\n";

            cout << ans;
            if(cnt)
                cout << " ";
            Rotate(n);
        }

        cout << "\n";
    }
}
