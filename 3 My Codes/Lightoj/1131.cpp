#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef vector<vector<ll>> Mat;
ll mod;
Mat mul(Mat A, Mat B)
{
    Mat ret(A.size(), vector<ll>(B[0].size()));
    ll i, j, k;
    for(i = 0; i < ret.size(); i++)
    {
        for(j = 0; j < ret[0].size(); j++)
        {
            for(k = 0; k < A[0].size(); k++)
                ret[i][j] = (ret[i][j] + (A[i][k] * B[k][j])%mod)%mod;
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
    ll t, i, q, n, caseno = 0;
    Mat M(6, vector<ll>(6)), F(6, vector<ll>(6)), ans(6, vector<ll>(6));
    M[1][0] = M[2][1] = M[4][3] = M[5][4] = 1;
    cin >> t;
    while(t--)
    {
        cin >> M[0][0] >> M[0][1] >> M[0][5];
        cin >> M[3][3] >> M[3][4] >> M[3][2];

        for(i = 2; i >= 0; i--)
            cin >> F[i][0];
        for(i = 5; i >= 3; i--)
            cin >> F[i][0];

        cin >> mod >> q;

        cout << "Case " << ++caseno << ":" << endl;
        while(q--)
        {
            cin >> n;
            ans = mul(power(M, n), F);
//            for(i = 0; i < ans.size(); i++)
//                cout << ans[i][0] << " ";
            cout << ans[2][0] << " " << ans[5][0] << endl;
        }
    }
}
