#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 107
#define mod 1000000000

struct Mat
{
    ll row, col, arr[sz][sz];

    Mat(ll r=0, ll c=0)
    {
        row = r, col = c;
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
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

    Mat power (ll p)
    {
        Mat base = *this;
        Mat ret(row, col);
        for(int i = 0; i < row; i++)
            ret.arr[i][i] = 1;

        while(p > 0)
        {
            if(p&1)
                ret = ret * base;
            base = base * base;
            p >>= 1;
        }

        return ret;
    }
};

int main()
{
    ll t, n, i, j, x;
    cin >> t;
    while(t--)
    {
        cin >> x;
        Mat a(x, 1), m(x, x);
        for(i = 0; i < x; i++)
            cin >> a.arr[i][0];
        for(i = x-1; i >= 0; i--)
            cin >> m.arr[x-1][i];
        for(i = 0; i < x-1; i++)
            m.arr[i][i+1] = 1;
        cin >> n;

        m = m.power(n-1);
//        for(i = 0; i < x; i++)
//        {
//            for(j = 0; j < x; j++)
//                cout << m.arr[i][j] << " ";
//            cout << endl;
//        }
//        a = m*a;
//        for(i = 0; i < x; i++)
//            cout << a.arr[i][0] << endl;
        cout << (m*a).arr[0][0] << endl;
    }
}
