#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 55
#define mod 1000000007

struct Mat
{
    ll arr[sz][sz], row, col;
    Mat(int r = 0, int c = 0)
    {
        row = r, col = c;
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
                arr[i][j] = 0;
        }
    }

    Mat operator * (Mat &p)
    {
        Mat ret(row, p.col);
        for(int i = 0; i < ret.row; i++)
        {
            for(int j = 0; j < ret.col; j++)
            {
                for(int k = 0; k < col; k++)
                    ret.arr[i][j] = (ret.arr[i][j] + (arr[i][k]*p.arr[k][j])%mod)%mod;
            }
        }
        return ret;
    }

    Mat power(ll p)
    {
        Mat ret(row, col), base = *this;
        for(int i = 0; i < row; i++)
            ret.arr[i][i] = 1;

        while(p)
        {
            if(p&1)
                ret = ret * base;
            base = base*base;
            p >>= 1;
        }
        return ret;
    }
};


int main()
{
    ll t, m, n, i, j;
    cin >> t;
    while(t--)
    {
        cin >> m >> n;
        Mat ans(m, m);
        for(i = 0; i < m; i++)
        {
            for(j = 0; j < m; j++)
                cin >> ans.arr[i][j];
        }

        ans = ans.power(n);
        for(i = 0; i < m; i++)
        {
            for(j = 0; j < m; j++)
                cout << ans.arr[i][j] << " ";
            cout << endl;
        }
    }
}
