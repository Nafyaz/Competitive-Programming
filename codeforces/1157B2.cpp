#include "bits/stdc++.h"
using namespace std;


int main(int argc, char const *argv[])
{
	int n;
	string s;
	//cin >> n >> s;
	/*for(int i = 1; i < 10; i++) {
		cin >> f[i];
	}*/
	n = 9;
	s = "345678912";
	int f[] = {0, 1, 2, 4, 5, 6, 6, 8, 9, 9};
	bool good = false;
	for(int i = 0; i < n; i++) {
		int c = s[i] - '0';
		if(good && c > f[c]) break;
		if(c < f[c]) {
			s[i] = f[c] + '0';
			good = true;
		}
	}
	cout << s << endl;
	return 0;
}
