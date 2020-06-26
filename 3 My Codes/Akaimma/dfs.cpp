// Matrix Exponential Sajjad Abeer

#include <bits/stdc++.h>
using namespace std;
#define VT 					long long
#define MOD 				1000000007
#define CLR(x, y) 			memset(x, y, sizeof(x))

const int rows=258;
const int cols=258;

struct Matrix{
	int r, c;
	VT m[rows][cols];
	void reset(int row=0, int col=0){
		r=row; c=col;
		memset(m, 0, sizeof(m));
	}
	Matrix(int row=0, int col=0){
		r=row; c=col;
		memset(m, 0, sizeof(m));
	}
	Matrix(vector<vector<VT> > v){
		r=v.size();
		c=0; if(v.size()) c=v[0].size();
		for(int i=0; i<r; i++){
			for(int j=0; j<c; j++){
				m[i][j]=v[i][j];
			}
		}
	}
	void iden() { for(int i=0; i<r; i++) m[i][i] = 1; }
	Matrix operator *(Matrix &B){
		if(c!=B.r) printf("--- Can't multiply ---\n");
		Matrix C=Matrix(r, B.c);
		for(int i=0; i<C.r; i++){
			for(int j=0; j<C.c; j++){
				VT val=0;
				for(int k=0; k<c; k++){
					val+=m[i][k]*B.m[k][j];
					if(val>=MOD) val%=MOD;
				}
				C.m[i][j]=val;
			}
		}
		return C;
	}
	Matrix exp(long long p){
		Matrix ans(r, c), b = *this; ans.iden();
		while(p){
			if(p&1) ans = ans * b;
			b = b * b; p>>=1;
		}
		return ans;
	}
	Matrix operator +(const Matrix& B){
		if(r!=B.r || c!=B.c) printf("--- Can't add ---\n");
		Matrix C=Matrix(r, c);
		for(int i=0; i<r; i++){
			for(int j=0; j<c; j++){
				C.m[i][j]=(m[i][j]+B.m[i][j])%MOD;
			}
		}
		return C;
	}
	void print(){
		printf("------ %d x %d ------\n", r, c);
		for(int i=0; i<r; i++){
			for(int j=0; j<c; j++){
				if(j) printf(" ");
				printf("%3lld", m[i][j]);
			}
			printf("\n");
		}
		printf("-------- end --------\n");
	}
};

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
	VT n;
	Matrix M=Matrix(3, 3);
	for(int i=0; i<3; i++) M.m[0][i]=1;
	for(int i=1; i<3; i++) M.m[i][i-1]=1;
	int bases[3]={0, 1, 2};
	while(scanf("%lld", &n) && n){
		if(n<=3){ /// 1 indexed
			printf("%d\n", bases[n-1]);
			continue;
		}
		Matrix ans=M.exp(n-3); /// 1 indexed
		VT tot=0;
		for(int i=0; i<3; i++){
			tot+=ans.m[0][i]*bases[3-i-1];
		}
		printf("%lld\n", tot%MOD);
	}
	return 0;
}
