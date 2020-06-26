#include<bits/stdc++.h>
using namespace std;
#define ui unsigned int

typedef vector<vector<ui>> Mat;

ui mulmod(ui a, ui b)
{
    ui ret = 0;
    while(b)
    {
        if(b&1)
            ret = (ret + a);
        a = (a + a);
        b >>= 1;
    }

    return ret;
}

Mat mul(Mat A, Mat B)
{
    Mat ret(A.size(), vector<ui>(B[0].size()));
    ui i, j, k;

    for(i = 0; i < ret.size(); i++)
    {
        for(j = 0; j < ret[0].size(); j++)
        {
            for(k = 0; k < A[0].size(); k++)
                ret[i][j] = (ret[i][j] + (A[i][k] * B[k][j]));
        }
    }

    return ret;
}

Mat power(Mat A, ui p)
{
    Mat ret(A.size(), vector<ui>(A[0].size()));
    ui i;

    for(i = 0; i < ret.size(); i++)
        ret[i][i] = 1;

    while(p)
    {
        if(p&1)
            ret = mul(ret, A);
        A = mul(A, A);
        p >>= 1;
    }

    return ret;
}

int main()
{
//    freopen("out.txt", "w", stdout);
    ui t, n, i, j, k, caseno = 0, ans;

    Mat G(36, vector<ui>(36));
    map<ui, ui> mp, revmp;
    k = 0;
    for(i = 0; i <= 7; i++)
    {
        for(j = i + 2; j <= 9; j++)
        {
            mp[(1 << i) + (1 << j)] = k;
            revmp[k] = (1 << i) + (1 << j);
            k++;
        }
    }

//    cout << revmp[3] << endl;

    for(i = 0; i < 36; i++)
    {
        for(j = 0; j < 36; j++)
        {
            ui a = (revmp[i] << 1), b = (revmp[j] << 1);
            ui x = a, y = b;

            for(k = 1; (1 << k) <= a; k++)
            {
                if(a & (1 << k))
                {
                    x |= (1 << (k-1));
                    x |= (1 << (k+1));
                }
            }

            if(((x & y) >> 1) == 0)
                G[i][j] = 1;
        }
    }

    cin >> t;
    while(t--)
    {
        Mat Mans;
        cin >> n;
        Mans = power(G, n-1);
        ans = 0;
        for(i = 0; i < 36; i++)
        {
            for(j = 0; j < 36; j++)
                ans = (ans + Mans[i][j]);
        }

        cout << "Case " << ++caseno << ": " << ans << endl;
    }
}
