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

    for(ll i = 0; i < ret.size(); i++)
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
    Mat A(3, vector<ll>(3));
    Mat B;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
            A[i][j] = i+j;
    }

    B = power(A, 0);
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
            cout << B[i][j] << " ";
        cout << endl;
    }
}
