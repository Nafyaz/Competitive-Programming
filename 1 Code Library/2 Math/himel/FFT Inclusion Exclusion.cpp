// Spoj Triple Sums

#include<bits/stdc++.h>
#define PI acos(-1.0)
#define ll long long
using namespace std;
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

vector<ll> Mul(vector<ll>& a, vector<ll>& b)
{
	vector<base> fa(a.begin(), a.end()), fb(b.begin(), b.end());
	int n = 1;
	while (n < max(a.size(), b.size()))  n <<= 1;
	n <<= 1;
	fa.resize(n), fb.resize(n);

	fft(fa, false), fft(fb, false);
	for (int i = 0; i<n; ++i)fa[i] *= fb[i];
	fft(fa, true);

	vector<ll> res;
	res.resize(n);
	for (int i = 0; i<n; ++i)res[i] = round(fa[i].real());
	return res;
}

const int N=40004;
int arr[N];
int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int tmp;
        cin >> tmp;
        arr[tmp+20000]++;
    }
    vector<ll>v1,v2,v3;
    for(int i=0;i<N;i++)
    {
        v1.push_back(arr[i]);
        v2.push_back(arr[i]);
        v3.push_back(arr[i]);
    }
    vector<ll>v=Mul(v1,v2);
    v=Mul(v,v3);
    vector<ll>dbl(v.size()),tri(v.size());
    for(ll i=0;i<v1.size();i++)
    {
        dbl[i+i]=v1[i]*v2[i]; // All (i,i) Pairs
        tri[i+i+i]=v1[i]*v2[i]*v3[i]; // All (i,i,i) Triplets
    }
    dbl=Mul(dbl,v3); // All (i,i,j) Triplets
    for(ll i=0;i<v.size();i++)
    {
        v[i] = v[i] - (3 * dbl[i] - 2 * tri[i]); // 3 (i,i,j) Triplets have 3 (i,i,i) triplets. So Remove 2 (i,i,i) triplets.
        v[i]/=6; // (i,j,k) can be oriented in 3! way
        if(v[i])cout << i - 60000 << " : " << v[i] << "\n"; // Handle negative value
    }
}
