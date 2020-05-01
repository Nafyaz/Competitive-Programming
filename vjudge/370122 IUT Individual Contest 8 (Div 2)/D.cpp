#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int main()
{
    int n, a[509], b[250009], c[509][509], i, j, k, x;
    map<int, int> freq;

    cin >> n;
    for(i = 0; i < n*n; i++)
    {
        cin >> x;
        freq[x]++;
        b[i] = x;
    }

    sort(b, b+n*n, greater<int>());

    j = n-1;
    for(i = 0; i < n*n; i++)
    {
        if(freq[b[i]] == 0)
            continue;
//        cout << i << " ";
        a[j] = b[i];
        freq[b[i]]--;
        c[j][j] = b[i];
        for(k = j+1; k < n; k++)
        {
//            cout << k << " " << j << endl;
            freq[__gcd(a[k], a[j])] -= 2;

            c[j][k] = c[k][j] = __gcd(a[k], a[j]);
        }
//        if(b[i] == 1)
//        {
//            for(i = 0; i < n; i++)
//            {
//                for(j = 0; j < n; j++)
//                    cout << c[i][j] << " ";
//                cout << endl;
//            }
//            for(auto u : freq)
//                cout << u.ff << " " << u.ss << endl;
//        }

        j--;
    }

    for(i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

//    for(i = 0; i < n; i++)
//    {
//        for(j = 0; j < n; j++)
//            cout << c[i][j] << " ";
//        cout << endl;
//    }
}
