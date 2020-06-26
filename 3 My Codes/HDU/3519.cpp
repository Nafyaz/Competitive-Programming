#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 10007

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

ll bigmod(ll a, ll p)
{
    ll ret = 1;
    while(p)
    {
        if(p&1)
            ret = (ret*a)%mod;
        a = (a*a)%mod;
        p >>= 1;
    }
    return ret;
}

int main()
{
    ll n;
    Mat M(2, vector<ll>(2)), F(2, vector<ll>(1));
    F[0][0] = 1;
    F[1][0] = 1;
    M[0][0] = 0, M[0][1] = 1;
    M[1][0] = 1, M[1][1] = 1;

    while(cin >> n)
    {
//        cout << n << " " << bigmod(2, n) << endl;
        cout << ((bigmod(2, n) - 2*mul(power(M, n), F)[0][0])%mod + mod)%mod << endl;
    }

}
