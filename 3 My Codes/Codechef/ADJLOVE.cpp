#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, n, a, i;

    cin >> t;

    while(t--)
    {
        cin >> n;

        vector<ll> odd, even;

        for(i = 0; i < n; i++)
        {
            cin >> a;
            if(a&1)
                odd.push_back(a);
            else
                even.push_back(a);
        }

//        for(auto u : odd)
//            cout << u << " ";
//        for(auto u : even)
//            cout << u << " ";
//        cout << "\n";

        if(!odd.empty() && odd.size()%2 == 0)
        {
            for(auto u : even)
                cout << u << " ";
            for(auto u : odd)
                cout << u << " ";
            cout << "\n";
        }
        else if(!even.empty() && odd.size() >= 3 && odd.size()%2 == 1)
        {
            cout << odd[0] << " ";
            for(auto u : even)
                cout << u << " ";
            for(i = 1; i < odd.size(); i++)
                cout << odd[i] << " ";
            cout << "\n";
        }
        else
            cout << "-1\n";
    }
}
