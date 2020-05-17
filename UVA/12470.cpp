#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000009

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
    ll i, j;
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
    ll n, i, j;
    Mat T(3, vector<ll>(1)), M(3, vector<ll>(3));

    T[0][0] = 0;
    T[1][0] = 1;
    T[2][0] = 2;

    M[0][0] = 0, M[0][1] = 1, M[0][2] = 0;
    M[1][0] = 0, M[1][1] = 0, M[1][2] = 1;
    M[2][0] = 1, M[2][1] = 1, M[2][2] = 1;

    while(1)
    {
        cin >> n;
        if(!n)
            return 0;
        cout << mul(power(M, n-1), T)[0][0] << endl;
    }
}
