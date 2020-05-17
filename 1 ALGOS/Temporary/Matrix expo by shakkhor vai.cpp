#include<bits/stdc++.h>
using namespace std;

const int N=2;

void MatMul(int A[N][N], int B[N][N])
{
    int R[N][N];
    memset(R, 0, sizeof(R));
    REP(i, N) REP(j, N) REP(k, N) R[i][j] = (R[i][j] + A[i][k] * B[k][j]);
    REP(i, N) REP(j, N) B[i][j] = R[i][j];
}


void MatPow(int R[N][N],int M[N][N],int P)
{
    while(P)
    {
        if(P & 1) MatMul(M, R);
        MatMul(M, M);
        P = P >> 1;
    }
}

