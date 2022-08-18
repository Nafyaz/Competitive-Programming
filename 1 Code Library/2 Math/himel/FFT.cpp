#include<bits/stdc++.h>
using namespace std;

#define Fast            ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define fWrite          freopen ("out.txt","w",stdout);
#define TC              int t;cin >> t;FOR(tc,1,t)
#define LL              long long
#define ULL             unsigned long long
#define PI              acos(-1.0)
#define ff              first
#define ss              second
#define pb              push_back
#define pii             pair<int,int>
#define all(a)          a.begin(),a.end()
#define MEM(a,x)        memset(a,x,sizeof(a))
#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define ROF(i,a,b)      for(int i=a;i>=b;i--)
#define REP(i,b)        for(int i=0;i<b;i++)

typedef complex<double> base;

void fft(vector<base> & a, bool invert) {
	int n = (int)a.size();

	for (int i = 1, j = 0; i<n; ++i) {
		int bit = n >> 1;
		for (; j >= bit; bit >>= 1)j -= bit;
		j += bit;
		if (i < j)swap(a[i], a[j]);
	}

	for (int len = 2; len <= n; len <<= 1) {
		double ang = 2 * PI / len * (invert ? -1 : 1);
		base wlen(cos(ang), sin(ang));
		for (int i = 0; i<n; i += len) {
			base w(1);
			for (int j = 0; j<len / 2; ++j) {
				base u = a[i + j], v = a[i + j + len / 2] * w;
				a[i + j] = u + v;
				a[i + j + len / 2] = u - v;
				w *= wlen;
			}
		}
	}
	if (invert)for (int i = 0; i<n; ++i)a[i] /= n;
}

vector<LL> Mul(vector<LL>& a, vector<LL>& b)
{
	vector<base> fa(a.begin(), a.end()), fb(b.begin(), b.end());
	int n = 1;
	while (n < max(a.size(), b.size()))  n <<= 1;
	n <<= 1;
	fa.resize(n), fb.resize(n);

	fft(fa, false), fft(fb, false);
	for (int i = 0; i<n; ++i)fa[i] *= fb[i];
	fft(fa, true);

	vector<LL> res;
	res.resize(n);
	for (int i = 0; i<n; ++i)res[i] = round(fa[i].real());
	return res;
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        string a,b;
        cin >> a >> b;
        vector<LL>v1,v2;

        int sign = 0;
        if(a[0] == '-'){
            sign = 1 - sign;
            a.erase(a.begin());
        }
        if(b[0] == '-'){
            sign = 1 - sign;
            b.erase(b.begin());
        }

        for(int i = 0;i < a.size();i++){
            int d = a[i] - '0';
            v1.push_back(d);
        }
        for(int i = 0;i < b.size();i++){
            int d = b[i] - '0';
            v2.push_back(d);
        }

        reverse(all(v1)),reverse(all(v2)); //Reverse needed if v1 is in x^n+x^n-1+.....+x^1+1 form
        vector<LL>v = Mul(v1,v2);

        int carry = 0;
        vector<int>answer;
        for(int i = 0;i < v.size();i++){
            int temp = v[i];
            temp += carry;
            answer.push_back(temp % 10);
            carry = temp/10;
        }
        while(answer.size() > 1 and answer.back() == 0)answer.pop_back();
        reverse(all(answer));

        for(int i : answer)cout << i;
        cout << "\n";

    }
}
