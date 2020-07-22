#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, i;
    string a, b;
    cin >> t;
    while(t--)
    {
        cin >> n >> a >> b;
        a = a + '0';
        b = b + '0';
        vector<int> va, vb;
        for(i = 0; i < n; i++)
        {
            if(a[i] != a[i+1])
                va.push_back(i+1);
            if(b[i] != b[i+1])
                vb.push_back(i+1);
        }

        cout << va.size() + vb.size() << " ";
        for(i = 0; i < va.size(); i++)
            cout << va[i] << " ";
        for(i = vb.size() - 1; i >= 0; i--)
            cout << vb[i] << " ";
        cout << "\n";
    }
}
