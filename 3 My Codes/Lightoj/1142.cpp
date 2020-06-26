#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 10
typedef vector<vector<ll>> Mat;

Mat add(Mat A, Mat B)
{
    ll i, j;
    for(i = 0; i < A.size(); i++)
    {
        for(j = 0; j < A[0].size(); j++)
            A[i][j] = (A[i][j] + B[i][j])%mod;
    }
    return A;
}

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

Mat call(Mat A, ll k)
{
    if(k == 1)
        return A;
    Mat ret;
    if(k&1)
        ret = add(call(A, k-1), power(A, k));
    else
    {
        ret = call(A, k>>1);
        ret = add(ret, mul(power(A, k>>1), ret));
    }
    return ret;
}

int main()
{
    ll t, caseno = 0, n, i, j, k;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        Mat M(n, vector<ll>(n));
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
                cin >> M[i][j];
        }

        M = call(M, k);

        cout << "Case " << ++caseno << ":\n";
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
                cout << M[i][j];
            cout << endl;
        }
    }

}
