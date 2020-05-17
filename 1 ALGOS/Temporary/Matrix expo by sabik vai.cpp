//http://lightoj.com/volume_showproblem.php?problem=1065

ll T,a,b,n,m,mod,out;

struct Matrix
{
    ll mat[2][2];
    ll N;
    Matrix():N(2) {}
    Matrix(ll n):N(n) {}
    Matrix multiply(Matrix B)
    {
        Matrix C;
        for(ll r = 0; r < N; r++){
            for(ll c = 0; c < N; c++)
            {
                C.mat[r][c] = 0;
                for(ll k = 0 ; k < N; k++)
                    C.mat[r][c] =  (C.mat[r][c] + (mat[r][k]*B.mat[k][c])%mod)%mod;
            }
        }
        return C;
    }
    Matrix power(ll n)
    {
        if(n == 1)
            return (*this);
        Matrix P;
        P = power(n/2);
        P = P.multiply(P);
        if(n & 1)
            P = multiply(P);
        return P;
    }
    void init()
    {
        mat[0][0] = 0;
        mat[0][1] = 1;
        mat[1][0] = 1;
        mat[1][1] = 1;
    }
};
int main()
{
    Matrix ans, base;
    scanf("%lld", &T);
    repl(tc,1,T)
    {
        scanf("%lld %lld %lld %lld", &a, &b, &n, &m);
        mod = 1;
        while(m--) mod*=10;
        a %= mod;
        b %= mod;
        if(n < 2)
        {
            if(n == 0) out = a;
            else out = b;
        }
        else
        {
            base.init();
            ans = base.power(n-1);
            out = ( (ans.mat[1][0]*a)%mod + (ans.mat[1][1]*b)%mod ) % mod;
        }
        printf("Case %lld: %lld\n", tc, out);
    }
}

