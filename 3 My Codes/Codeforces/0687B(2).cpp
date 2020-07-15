#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, k, a, i, lcm = 1;
	scanf("%d %d", &n, &k);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &a);
		a = __gcd(a, k);
		lcm = lcm/__gcd(lcm, a) * a;
	}

    printf(lcm == k? "Yes" : "No");
}
