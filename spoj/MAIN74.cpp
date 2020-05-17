#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

typedef vector<vector<ll>> Mat;

Mat mul(Mat A, Mat B)
{
    Mat ret(A.size(), vector<ll>(B[0].size()));
    ll i, j, k;
    for(i = 0; i < ret.size(); i++)
    {
        for(j = 0; j < ret[0].size(); j++)
        {
            for(k = 0; k < A[0].size(); k++)
                ret[i][j] = (ret[i][j] + (A[i][k]*B[k][j])%mod)%mod;
        }
    }
    return ret;
}

Mat power(Mat A, ll p)
{
    Mat ret(A.size(), vector<ll>(A[0].size()));
    ll i;
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
    ll t, n;
    Mat F(2, vector<ll>(1)), M(2, vector<ll>(2));
    F[0][0] = 0;
    F[1][0] = 1;
    M =
    {
        {0, 1},
        {1, 1}
    };
//
//    for(ll i = 0; i < 50; i++)
//        cout << i << " " << mul(power(M, i), F)[0][0] << endl;

    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n == 0)
            cout << 0 << endl;
        else if(n == 1)
            cout << 2 << endl;
        else
            cout << mul(power(M, n+3), F)[0][0] << endl;
    }
}
