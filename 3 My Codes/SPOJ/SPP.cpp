#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll mod;
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
    for(i = 0; i < A.size(); i++)
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
    ll t, k, m, n, i, sum1, sum2;
    cin >> t;
    while(t--)
    {
        cin >> k;
        Mat M(k+1, vector<ll>(k+1)), F(k+1, vector<ll>(1));
        for(i = 0; i < k; i++)
            cin >> F[i][0];
        F[k][0] = 0;
        for(i = k-1; i >= 0; i--)
            cin >> M[k-1][i];
        M[k][0] = M[k][k] = 1;
        for(i = 0; i < k-1; i++)
            M[i][i+1] = 1;

        cin >> m >> n >> mod;

        sum1 = mul(power(M, m-1), F)[k][0];
        sum2 = mul(power(M, n), F)[k][0];

        cout << (sum2 - sum1 + mod)%mod << endl;
    }
}
