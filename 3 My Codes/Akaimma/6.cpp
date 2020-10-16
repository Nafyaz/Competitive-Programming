#include<bits/stdc++.h>
using namespace std;

int a[1000], dp[1000][2], n;

int call(int i, int choice)
{
    if(i == n)
        return 0;
    if(dp[i][choice] != -1)
        return dp[i][choice];

    dp[i][choice] = call(i+1, 1);
    if(choice)
        dp[i][choice] = max(dp[i][choice], a[i] + call(i+1, 0));

    return dp[i][choice];
}

int main()
{
    int i;
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> a[i];

    memset(dp, -1, sizeof dp);
    cout << call(0, 1);
}
/*
11
5
1 2 3 4 5
5
5 4 3 2 1
7
1 3 2 5 4 8 20
11
1 1 1 5 1 1 10 1 1 15 1
4
1 2 3 4
4
4 3 2 1
5
1 2 1 2 1
7
2 4 2 2 5 3 1
5
1 1 1 1 1
4
1 1 1 1
5
0 0 1 0 0
*/
/*
Output:
9
9
28
31
6
6
4
10
3
2
1
*/
