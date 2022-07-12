typedef vector<vector<ll>> Mat;

Mat Mul(Mat A, Mat B)
{
    Mat ret(A.size(), vector<ll>(B[0].size()));
    ll i, j, k;

    for(i = 0; i < ret.size(); i++)
    {
        for(j = 0; j < ret[0].size(); j++)
        {
            for(k = 0; k < A[0].size(); k++)
                ret[i][j] = (ret[i][j] + (A[i][k]*B[k][j])%MOD)%MOD;
        }
    }

    return ret;
}

Mat Pow(Mat A, ll p)
{
    Mat ret(A.size(), vector<ll>(A[0].size()));

    for(ll i = 0; i < ret.size(); i++)
        ret[i][i] = 1;

    while(p)
    {
        if(p&1)
            ret = Mul(ret, A);
        A = Mul(A, A);
        p >>= 1;
    }
    return ret;
}