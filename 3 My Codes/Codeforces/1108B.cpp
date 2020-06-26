#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i;

    cin >> n;
    vector <int> v(n);

    for(i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());
    cout << v[n-1] << " ";

    int x = v[n-1];
    for(i = 1; i < sqrt(x); i++)
    {
        if(x % i == 0)
        {
            v.erase(find(v.begin(), v.end(), i));
            v.erase(find(v.begin(), v.end(), x/i));
        }
    }

    i = sqrt(x);
    if(i*i == x)
        v.erase(find(v.begin(), v.end(), i));

    cout << v.back();

}
