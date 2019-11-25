#include<bits/stdc++.h>
using namespace std;

/* msi1427 */

#define ll           long long
#define llu          long long unsigned
#define LD           long double
#define FOR(i,n)     for(int i=0;i<n;i++)
#define FLR(i,n)     for(ll i=0;i<n;i++)
#define RFOR(i,n)   for(int i=n-1;i>=0;i--)
#define RFLR(i,n)    for(ll i=n-1;i>=0;i--)
#define rep(i,a,b)    for(int i=a;i<=b;i++)
#define repl(i,a,b)  for(ll i=a;i<=b;i++)
#define casep(z)     cout << "Case " << z << ": ";
#define Fast         ios_base::sync_with_stdio(0);cin.tie(0);
#define sz(a)        a.size()
#define all(x)       x.begin(),x.end()
#define SORT(a,n)    sort(a,a+n)
#define RSORT(a,n)   sort(a,a+n,greater<ll>())
#define pii          pair<int,int>
#define pll          pair<ll,ll>
#define VSORT(v)     sort(all(v))
#define VRSORT(v)    sort(all(v),greater<ll>())
#define pb           push_back
#define pf            push_front
#define pob          pop_back()
#define pof          pop_front()
#define ff           first
#define ss           second
#define tt           true
#define fs           false
#define MP           make_pair
 #define ms(x,n)      memset((x),n,sizeof(x))
#define bsrch(a,n,x) binary_search(a,a+n,x)
#define vi           vector<int>
#define vll          vector<ll>
#define PI          acos(-1.0)
#define LB(a,x)      (lower_bound(all(a),x)-a.begin()) //  first element in the range [first,last) which does not compare less than val.
#define UB(a,x)      (upper_bound(all(a),x)-a.begin()) //  first element in the range [first,last) which compares greater than val.
#define PQ           priority_queue
#define heap       PQ< ll , vll , greater < ll > >
#define REV(x)       reverse(all(x))
#define mpii         map<int,int>
#define mpll         map<ll,ll>
#define cig          cin.ignore()
#define INF          1e10
#define EPS          1e-6
#define prec(n)      fixed << setprecision(n)
#define lb           lower_bound
#define ub           upper_bound
#define fin          freopen("in.txt","r",stdin)
#define fout         freopen("out.txt","w",stdout)
#define sc           scanf
#define pt           printf
#define np           next_permutation
#define IT(it,x)     for(it=x.begin();it!=x.end();it++)

ll dx[] = {1,-1,0,0};
ll dy[] = {0,0,1,-1};

#define min3(a,b,c)     min(a,min(b,c))
#define max3(a,b,c)     max(a,max(b,c))
#define min4(a,b,c,d)   min(min(a,b),min(c,d))
#define max4(a,b,c,d)   max(max(a,b),max(c,d))
#define max5(a,b,c,d,e) max(max3(a,b,c),max(d,e))
#define min5(a,b,c,d,e) min(min3(a,b,c),min(d,e))

ll T,n,p;
char s[15][15];
ll d[15][15];
bool vis[15][15];

ll bfs(ll sx, ll sy, ll ex, ll ey)
{
    ms(d,-1);
    queue<pll>q;
    q.push(MP(sx,sy));
    d[sx][sy]=0;
    while(!q.empty())
    {
        ll x = q.front().ff;
        ll y = q.front().ss;
        q.pop();
        FLR(i,4)
        {
            ll xx = x + dx[i];
            ll yy = y + dy[i];
            if(xx>=0 && yy>=0 && xx<n && yy<n && (s[xx][yy]=='.' || vis[xx][yy] || (xx==ex &&yy==ey)) && (d[xx][yy]==-1))
            {
                d[xx][yy]=d[x][y]+1;
                q.push(MP(xx,yy));
            }
        }
    }
    return d[ex][ey];
}

int main()
{
    scanf("%lld",&T);
    while(T--)
    {
        map<char,pll>mp;
        scanf("%lld",&n);
        FLR(i,n) scanf("%s",s[i]);
        FLR(i,n) FLR(j,n) if(isalpha(s[i][j])) mp[s[i][j]]=MP(i,j);
        map<char,pll>::iterator it,it1;
        it1 = mp.end();
        it1--;
        ll cc=0;
        ms(vis,false);
        IT(it,mp)
        {
            ll x = (it->ss).ff;
            ll y = (it->ss).ss;
            if(it!=it1)
            {
                it++;
                ll a = (it->ss).ff;
                ll b = (it->ss).ss;
                ll yy = bfs(x,y,a,b);
                if(yy==-1)
                {
                    cc=-1;
                    break;
                }
                else
                {
                    cc+=yy;
                    vis[x][y]=true;
                    vis[a][b]=true;
                }
                it--;
            }
        }
        if(cc!=-1) printf("Case %lld: %lld\n",++p,cc);
        else printf("Case %lld: Impossible\n",++p);
    }
}
