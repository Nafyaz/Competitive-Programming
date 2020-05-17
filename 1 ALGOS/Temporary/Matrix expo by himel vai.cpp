#include<bits/stdc++.h>
using namespace std;

#define LL              long long
#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define ROF(i,a,b)      for(int i=a;i>=b;i--)
#define REP(i,b)        for(int i=0;i<b;i++)
#define MEM(a,x)        memset(a,x,sizeof(a))

LL mod;
const LL N=6;

void MatMul(LL A[N][N], LL B[N][N])
{
    LL R[N][N];
    MEM(R,0);
    REP(i, N) REP(j, N) REP(k, N) R[i][j] = (R[i][j]%mod + (A[i][k] * B[k][j])%mod)%mod;
    REP(i, N) REP(j, N) B[i][j] = R[i][j];
    return;
}


void MatPow(LL R[N][N],LL M[N][N],LL P)
{
    while(P)
    {
        if(P & 1)
            MatMul(M,R);
        MatMul(M,M);
        P = P >> 1;
    }
}

int main()
{

    LL n,M[N][N],R[N][N]; // M is Co-efficient Matrix,R is Base case Matrix
    //Take input values of M and R matrix
    //Input n,We have to find f(n)
    MatPow(R,M,n-2); // Here n-2 may changes in diffrent problems
    //value of f(n) is in R[0][0] position
    return 0;
}
