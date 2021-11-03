#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define vii vector<int>
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pdd pair<double,double>
#define pldld pair<long long double, long long double>
#define ff first
#define ss second
#define pb push_back
#define read freopen("alu.txt","r",stdin);
#define write freopen("vorta.txt","w",stdout);
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);
#define PI 2*acos(0.0)
#define eps 1e-11
#define DEBUG(x) cerr << #x << " = " << x << endl
//#pragma comment(linker, "/stack:200000000")
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

const int MAX = 1e5 + 5, MOD = 1e9 + 7  , MAXLG = log2(MAX)+1;
const ll inf = 1e18 + 5;

struct state{
    int link, next_lif, idx;
    int next[26];
    bool lif;
    state(){
        lif = false;
        link = 0;
        next_lif = 0;
        idx = -1;
        memset(next, 0, sizeof next);
    }
};
vector<state>aho;
int cnt[505], mp[505];
int sz;

void add_str(const string &s, int idx){
    int now = 0;
    for(int i=0; i<s.size(); i++){
        int c = s[i] - 'a';
        if(!aho[now].next[c]){
            aho[now].next[c] = (int)aho.size();
            aho.emplace_back();
        }
        now = aho[now].next[c];
    }

    if(aho[now].lif){
        mp[idx] = aho[now].idx;
        return;
    }
    mp[idx] = idx;
    aho[now].lif = true;
    aho[now].idx = idx;
}

void push_link(){
    queue<int>q;
    q.push(0);
    while(!q.empty()){
        int cur = q.front();
        int link = aho[cur].link;
        q.pop();

        aho[cur].next_lif = aho[link].lif ? link : aho[link].next_lif;
        for(int c=0; c<26; c++){
            if(aho[cur].next[c]){
                aho[ aho[cur].next[c] ].link = cur ? aho[link].next[c] : 0;
                q.push( aho[cur].next[c] );
            }
            else aho[cur].next[c] = aho[link].next[c];
        }
    }
}

// int arr[MAX];
int main(){

    // fastio;
    int t, cs = 0;
    cin >> t;
    while(t--){
        sz = 0;
        int n;
        cin >> n;
        string s;
        cin >> s;
        aho.clear();
        aho.emplace_back();
        memset(cnt, 0, sizeof cnt);
        memset(mp, -1, sizeof mp);
        for(int i=0; i<n; i++){
            string p;
            cin >> p;
            add_str(p,i);
        }
        push_link();
        int now = 0;
        for(int i=0; i<s.size(); i++){
            int c = s[i] - 'a';
            now = aho[now].next[c];
            int cur = now;
            while(cur){
                if(aho[cur].idx != -1) cnt[aho[cur].idx]++;
                cur = aho[cur].next_lif;
            }
        }

        cout << "Case " << ++cs << ":\n";
        for(int i=0; i<n; i++){
            cout << cnt[mp[i]] << "\n";
        }
    }
}
