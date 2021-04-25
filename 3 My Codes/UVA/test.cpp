#include <bits/stdc++.h>
using namespace std;

void solve(int tc) {

    int n; cin >> n;

    map <int, int> mp, cnt;

    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        mp[x] = i;
        cnt[x]++;
    }

    for(auto [x, y]: mp) if(cnt[x] == 1) {
        cout << y << endl;
        return;
    }

}

int32_t main() {
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t, tc = 0; cin >> t;
    while(t--)
        solve(++tc);
}
