#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, i, n, k;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        vector<int> div;
        for(i = 1; i*i < n; i++)
        {
            if(n%i == 0)
            {
                div.push_back(i);
                div.push_back(n/i);
            }
        }
        if(i*i == n)
            div.push_back(i);

        sort(div.begin(), div.end());

//        for(auto u : div)
//            cout << u << " ";

        int pos = lower_bound(div.begin(), div.end(), k+1) - div.begin() -1;
//        cout << pos << endl;
        cout << n/div[pos] << endl;
    }
}
