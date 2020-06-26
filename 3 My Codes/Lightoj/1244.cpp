#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 10007

typedef vector<vector<ll>> Mat;
Mat mul(Mat A, Mat B)
{
    Mat ret(A.size(), vector<ll>(B[0].size()));
    ll i, j, k;

    for(i = 0; i < A.size(); i++)
    {
        for(j = 0; j < B[0].size(); j++)
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
    ll t, n, caseno = 0;
    Mat M(3, vector<ll>(3)), F(3, vector<ll>(1));
    F[0][0] = 1;
    F[1][0] = 2;
    F[2][0] = 1;
    M[1][2] = 2;
    M[0][1] = M[1][0] = M[1][1] = M[2][0] = M[2][2] = 1;

    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << "Case " << ++caseno << ": " << mul(power(M, n-1), F)[0][0] << endl;
    }
}
