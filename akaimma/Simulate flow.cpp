#include<bits/stdc++.h>
using namespace std;

int n, m, val[10];
vector<int> edg;

int main()
{
    int i, j, u, v;
    cin >> n >> m;
//    for(i = 1; i <= n; i++)
//        val[i] = 100;
    for(i = 0; i < m; i++)
    {
        cin >> u >> v;
        edg.push_back(u);
        edg.push_back(v);
    }

    for(i = 0; i < 100; i++)
    {
        for(j = 0; j < edg.size(); j+=2)
        {
            val[edg[j]]--;
            val[edg[j+1]]++;
        }
        cout << "iter: " << i+1 << endl;
        for(j = 1; j <= n; j++)
            cout << setw(4) << j << " ";
        cout << endl;
        for(j = 1; j <= n; j++)
            cout << setw(4) << val[j] << " ";
        cout << endl << endl;
    }
}
/*
8 13
1 2
1 3
3 6
3 5
4 1
4 3
5 4
5 7
6 2
6 5
7 6
7 8
8 5
*/
