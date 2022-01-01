#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, i, j, n, m, ans;
    pair<int, int> robot, dirty, dir;

    cin >> t;

    while(t--)
    {
        cin >> n >> m >> robot.ff >> robot.ss >> dirty.ff >> dirty.ss;
        dir.ff = 1;
        dir.ss = 1;

        for(ans = 0; robot.ff != dirty.ff && robot.ss != dirty.ss; ans++)
        {
            if(robot.ff + dir.ff > n || robot.ff + dir.ff <= 0)
                dir.ff *= -1;
            if(robot.ss + dir.ss > m || robot.ss + dir.ss <= 0)
                dir.ss *= -1;

            robot.ff = robot.ff + dir.ff;
            robot.ss = robot.ss + dir.ss;
        }

        cout << ans << "\n";
    }
}
