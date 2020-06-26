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
    Mat ret(A.size(), vector<ll>(A.size()));
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
    ll n, t;
    Mat F(4, vector<ll>(1)), M(4, vector<ll>(4));

    F[0][0] = 0;
    F[1][0] = 1;
    F[2][0] = 1;
    F[3][0] = 1;

    M[0][0] = 0, M[0][1] = 1, M[0][2] = 0, M[0][3] = 0;
    M[1][0] = 1, M[1][1] = 1, M[1][2] = 1, M[1][3] = 0;
    M[2][0] = 0, M[2][1] = 0, M[2][2] = 1, M[2][3] = 1;
    M[3][0] = 0, M[3][1] = 0, M[3][2] = 0, M[3][3] = 1;

    cin >> t;
    while(t--)
    {
        cin >> n >> mod;
        cout << mul(power(M, n), F)[0][0] << endl;
    }
}

