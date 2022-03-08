#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

int main()
{
	ll n, i, j, a;

	cin >> n;

	queue<pair<ll, ll>> ones, twos;

	for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(i%2 != j%2)
                ones.push({i, j});
            else
                twos.push({i, j});
        }
    }

    for(i = 1; i <= n*n; i++)
    {
        cin >> a;
        if(a != 1 && !ones.empty())
        {
            cout << "1 " << ones.front().ff << " " << ones.front().ss << "\n";
            ones.pop();
        }
        else if(a != 2 && !twos.empty())
        {
            cout << "2 " << twos.front().ff << " " << twos.front().ss << "\n";
            twos.pop();
        }
        else
        {
            if(!ones.empty())
            {
                cout << "3 " << ones.front().ff << " " << ones.front().ss << "\n";
                ones.pop();
            }
            else
            {
                cout << "3 " << twos.front().ff << " " << twos.front().ss << "\n";
                twos.pop();
            }
        }
    }
}
