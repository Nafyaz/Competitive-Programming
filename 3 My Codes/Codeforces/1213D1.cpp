#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	vector<int> poss;
	for (int i = 0; i < n; ++i)
    {
		int x = a[i];
		while (x > 0)
        {
			poss.push_back(x);
			x /= 2;
		}
	}

	int ans = 1e9;
	for (auto res : poss)
    {
		vector<int> cnt;
		for (int i = 0; i < n; ++i)
		{
			int x = a[i];
			int cur = 0;
			while (x > res)
			{
				x /= 2;
				++cur;
			}
			if (x == res)
				cnt.push_back(cur);
		}
		if (int(cnt.size()) < k) continue;
		sort(cnt.begin(), cnt.end());
		ans = min(ans, accumulate(cnt.begin(), cnt.begin() + k, 0));
	}

	cout << ans << endl;

	return 0;
}
