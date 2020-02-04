#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define llu long long unsigned
#define vii vector<int>
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pdd pair<double,double>
#define ff first
#define ss second
#define read freopen("alu.txt","r",stdin);
#define write freopen("vorta.txt","w",stdout);
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);

const int MOD=1e6 + 3, MAX=1e6 + 5;
ll nfact[MAX],inv_n[MAX];

vector<bool>mark(MAX,1);
vector<int>prime;
int seive(){
    int total=0;
    mark[1]=0;
    prime.push_back(2);
    total++;
    for(ll i=4;i<MAX;i+=2) mark[i]=0;
    for(ll i=3;i<MAX;i+=2){
        if(mark[i]){
            prime.push_back(i);
            total++;
            if(i*i<MAX){
                for(ll j=i*i;j<MAX;j+=2*i){
                    mark[j]=0;
                }
            }
        }
    }
    return total;
}

ll gcd(int a, int b){

    if(b==0) return a;
    return gcd(b,a%b);

}

ll lcm(int a, int b){

    return ((long double)a*(long double)b)/(long double)gcd(a,b);

}

ll bigmod(ll a, ll b){

    if(b==0){
        return 1%MOD;
    }
    ll x=bigmod(a,b/2);
    x=(x*x)%MOD;
    if(b%2==1){
        x=(x*a)%MOD;
    }

    return x%MOD;

}

ll invmod(ll a, ll b){

    return bigmod(a,b-2);

}

//precalc fact
fact[0]=inv_fact[0]=inv_fact[1]=1;
for(int i=1;i<MAX;i++) fact[i]=((fact[i-1]%MOD)*((ll)i%MOD))%MOD;
for(int i=2;i<MAX;i++) inv_fact[i]=((inv_fact[i-1]%MOD)*(invmod((ll)i,MOD)))%MOD;

//totient
vector<bool>mark(5000005,1);
long long unsigned phi[5000005];
int totient(){
    mark[1]=0;
    for(int i=1;i<=5000000;i++){
        phi[i]=i;
    }
    for(int i=2;i<=5000000;i++){
        if(mark[i]){
            for(int j=i;j<=5000000;j+=i){
                mark[j]=0;
                phi[j]-=(phi[j]/i);

            }
        }
    }
}

int NOD(int N){
    int i,val,c,sum;
    val=sqrt(N)+1;
    sum=1;
    for(i=0;primes[i]<val;i++){
        if(N%primes[i]==0){
            c=0;
            while(N%primes[i]==0){
                N/=primes[i];
                c++;
            }
            sum*=(c+1);
            val=sqrt(N)+1;
        }
    }
    if(N>1)
    sum=sum*2;
    return sum;
}



int SOD(int N){
    int i,val,c,sum,p,s;
    val=sqrt(N)+1;
    sum=1;
    for(i=0;primes[i]<val;i++){
        if(N%primes[i]==0){
            p=1;
            while(N%primes[i]==0)
                {
                N/=primes[i];
                p=p*primes[i];
            }
            p=p*primes[i];
            s=(p-1)/(primes[i]-1);
            sum=sum*s;
        }
    }

	if(N>1){
        p=N*N;
        s=(p-1)/(N-1);
        sum=sum*s;
    }
    return sum;
}



//Number of divisors upto N
int D[1000010];
void NOD_n(){
    int i,j,val,N,M,c;
    D[1]=1;
    for(i=2;i<=1000000;i++){
        N=M=i;
        val=sqrt(N)+1;
        for(j=0;primes[j]<val;j++){
            if(M%primes[j]==0){
                c=0;
                while(M%primes[j]==0){
                    M/=primes[j];
                    c++;
                }
                D[N]=(c+1)*D[M];
                break;
            }
        }
        if(M==N){
            D[N]=2;
        }
    }
}


//Trailing zero in N! base B
seive();
int factors_in_factorial(int N,int p){
    int sum=0;
    while(N){
        sum+=N/p;
       	N/=p;
    }
    return sum;
}

int Trailingzero_Base_B(int N,int B){
    int i,ans,freq,power;
    ans=1000000000;
    for(i=0;primes[i]<=B;i++){
       	if(B%primes[i]==0){
            freq=0;
            while(B%primes[i]==0){
                freq++;
                B/=primes[i];
            }
            power=factors_in_factorial(N,primes[i]);
            ans=min(ans,power/freq);
        }
    }

    if(b>1){
        power=factor_in_factorial(n,b);
        ans=min(ans,power/1)
    }

    return ans;
}


//Cumulative SOD
ll CSOD(ll n){
    ll j,ans=0;
    for(ll i=2;i*i<=n;i++){
        j=n/i;
        ans+=(i+j)*(j-i+1)/2;
        ans+=i*(j-i);
    }
}

//Sort vector pair on the basis of 2nd element
bool sortbysec(const pair<int,int> &a, const pair<int,int> &b)
{
    return (a.second < b.second);
}


//Last non-zero digit of N!
int dig[MAX] = {1, 1, 2, 6, 4, 2, 2, 4, 2, 8};
int lastNonzeroDigit(ll n){
    if (n < 10)
        return dig[n];

    // Check whether tens (or second last) digit
    // is odd or even
    // If n = 375, So n/10 = 37 and (n/10)%10 = 7
    // Applying formula for even and odd cases.
    if (((n/10)%10)%2 == 0)
        return (6*lastNonzeroDigit(n/5)*dig[n%10]) % 10;
    else
        return (4*lastNonzeroDigit(n/5)*dig[n%10]) % 10;
}

//Recurse graph
void check( int i, int j ) {
    if( i < 0 || j < 0 || i >= totalrow || j >= totalcol ) return;
    if( mp[i][j] == 'B' ) found  = 1;
    else if( mp[i][j] == 'X' ) return;
    else {
        check(i-1,j);
        check(i,j-1);
        check(i,j+1);
        check(i+1,j);
    }
}


void bfs(int s){

    memset(vis,false,sizeof vis);
    dis.clear();
    queue<int>q;
    q.push(s);
    vis[s]=true;
    dis[s]=0;
    while(!q.empty()){
        int n=q.front();
        q.pop();
        for(int i=0;i<graph[n].size();i++){
            if(vis[graph[n][i].ff]==false){
                vis[graph[n][i].ff]=true;
                q.push(graph[n][i].ff);
                dis[graph[n][i].ff]=dis[n]+graph[n][i].ss;
            }
        }
    }

}


const int MAX=30005;

vector<pii>graph[MAX];
bool vis[MAX];
vector<long long>dis(MAX);

void dfs(int n){

    if(!vis[n]) vis[n]=true;
    for(int i: graph[n]) dfs(i);

}

//djikstra
struct comp{

    bool operator()(const pii &a, const pii &b) const{
        return a.ff>b.ff;
    }

};

void djikstra(int s){

    priority_queue<pii,vector<pii>,comp>q;

    for(int i=0;i<MAX;i++) dis[i]=INT_MAX;

    dis[s]=0;
    q.push(pii(dis[s],s));
    while(!q.empty()){
        pii u=q.top();
        q.pop();
        for(int i=0;i<graph[u.ss].size();i++){
            if(dis[u.ss]+graph[u.ss][i].ss<dis[graph[u.ss][i].ff]){
                dis[graph[u.ss][i].ff]=dis[u.ss]+graph[u.ss][i].ss;
                q.push(pii(dis[graph[u.ss][i].ff],graph[u.ss][i].ff));
            }
        }
    }

}

//second shortest path
bool vis[MAX];
int dis_1[MAX], dis_n[MAX];
vector<pii>graph[MAX];

int main(){

    int t,caseno=0;
    scanf("%d",&t);
    while(t--){
        for(int i=0;i<MAX;i++) graph[i].clear();
        int n,r;
        scanf("%d %d",&n,&r);
        while(r--){
            int u,v,cost;
            scanf("%d %d %d",&u,&v,&cost);
            graph[u].push_back(pii(v,cost));
            graph[v].push_back(pii(u,cost));
        }

        djikstra(1,dis_1);
        int shortest=dis_1[n],second_shortest=INT_MAX;
        djikstra(n,dis_n);

        for(int i=1;i<=n;i++){
            for(int j=0;j<graph[i].size();j++){
                int node=graph[i][j].ff;
                int cost=graph[i][j].ss;
                int a=dis_1[i]+dis_n[node]+cost;
                int b=dis_1[i]+dis_n[i]+2*cost;
                if(a>shortest) second_shortest=min(a,second_shortest);
                if(b>shortest) second_shortest=min(b,second_shortest);
            }
        }

        printf("Case %d: %lli\n",++caseno,second_shortest);
    }

}

//floyd warshal
int g[105][105];
int fr[15];
void initialize(int n){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i==j) g[i][j]=0;
            else g[i][j]=INT_MAX;
        }
    }
}

void floyd(int n){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(g[i][k]+g[k][j]>=0) g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
            }
        }
    }
}

int main(){

    fastio;
    int t,caseno=0;
    cin>>t;
    while(t--){
        int n,m,f;
        cin>>n>>m>>f;
        initialize(n);
        while(m--){
            int u,v,w;
            cin>>u>>v>>w;
            if(w<g[u][v]) g[u][v]=g[v][u]=w;
        }

        floyd(n);
    }

}

//bellman ford
int b[MAX],dis[MAX];
int n,m;
vii u,v,cost;

bool bellman(){

    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            if(dis[v[j]]>dis[u[j]]+cost[j]){
                dis[v[j]]=dis[u[j]]+cost[j];
            }
        }
    }

    for(int j=0;j<m;j++){
        if(dis[v[j]]>dis[u[j]]+cost[j]){
            return false;
        }
    }

    return true;

}

void initialize(){

    for(int i=0;i<MAX;i++){
        dis[i]=100000000;
        b[i]=0;
    }
    dis[1]=0;
    u.clear();
    v.clear();
    cost.clear();

}
int main(){

    int t,caseno=0;
    scanf("%d",&t);
    while(t--){
       initialize();
       scanf("%d",&n);
       for(int i=1;i<=n;i++) scanf("%d",&b[i]);
       scanf("%d",&m);
       for(int i=0;i<m;i++){
            int c,d;
            scanf("%d %d",&c,&d);
            int w=(b[d]-b[c]);
            u.push_back(c);
            v.push_back(d);
            cost.push_back(w*w*w);
       }

       int q;
       scanf("%d",&q);
       printf("Case %d:\n",++caseno);
       bellman();
    }
}

//minimum spanning tree
struct node{

    int u,v;
    int cost;
    bool operator<(const node &n) const{
        return cost<n.cost;
    }
    node(int _u, int _v, int _cost){
        u=_u;
        v=_v;
        cost=_cost;
    }

};

typedef struct node node;
map<string,string>par;
set<string>st;

vector<node>e;
int par[MAX];
int findpar(int r){

    if(par[r]==r) return r;
    par[r]=findpar(par[r]);
    return par[r];

}

ll mst(int n){

    for(int i=0;i<n;i++) par[i]=i;
    sort(e.begin(),e.end());
    int c=0;
    ll sum=0;
    for(int i=0;i<e.size();i++){
        int u=findpar(e[i].u);
        int v=findpar(e[i].v);
        if(u!=v){
            par[u]=v;
            sum+=e[i].cost;
            c++;
            if(c==n-1) break;
        }
    }

    if(c!=n-1) return -1;
    return sum;

}

//DSU
int par[MAX];
int sze[MAX];

int findpar(int r){

    if(par[r]==r) return r;
    par[r]=findpar(par[r]);
    return par[r];

}

void make(int a, int b){

    int u=findpar(a);
    int v=findpar(b);
    if(u==v) return;

    if(sze[u]>=sze[v]){
        sze[u]+=sze[v];
        par[v]=u;
    }
    else{
        sze[v]+=sze[u];
        par[u]=v;
    }

}


//bfs in grid...shortest path from (i,j) overcoming obstacles
int fx[]={0,1,0,-1};
int fy[]={-1,0,1,0};
const int MAX=1005;
char grid[25][25];
int dis[25][25];
bool vis[25][25];
int n,m;
void bfs(int i, int j){

    memset(vis,false,sizeof vis);
    for(int x=0;x<n;x++){
        for(int y=0;y<m;y++){
            dis[x][y]=INT_MAX;
        }
    }
    vis[i][j]=true;
    dis[i][j]=0;
    queue<pii>q;
    q.push(pii(i,j));
    while(!q.empty()){
        pii temp=q.front();
        q.pop();
        for(int a=0;a<4;a++){
            i=temp.ff+fx[a];
            j=temp.ss+fy[a];
            if(i>=0 && i<n && j>=0 && j<m && vis[i][j]==false && grid[i][j]!='#' && grid[i][j]!='m'){
                dis[i][j]=min(dis[temp.ff][temp.ss]+1,dis[i][j]);
                vis[i][j]=true;
                q.push(pii(i,j));
            }
        }
    }

}



//topsort lexicographical order
bool flag;
stack<char>st;
map<char,vector<char> >graph;
set<char>track;
map<char,int>vis,indg;

struct comp{

    bool operator()(const char &a, const char &b) const{
        return a>b;
    }

};

priority_queue<char,vector<char>,comp>q;
void cycle(char source){

    if(vis[source]==1){
        flag=true;
        return;
    }
    if(vis[source]==2) return;
    vis[source]=1;
    for(int i=0;i<graph[source].size();i++) cycle(graph[source][i]);
    vis[source]=2;

}

void topsort(char source){

    vis[source]=1;

    for(int i=0;i<graph[source].size();i++){
        if(!vis[graph[source][i]]){
            indg[graph[source][i]]--;
            if(!indg[graph[source][i]]) q.push(graph[source][i]);
        }
    }
    while(!q.empty()){
        char temp=q.top();
        q.pop();
        topsort(temp);
    }
    st.push(source);

}

int main(){

    fastio;
    int t;
    cin>>t;

    while(t--){
        string s;
        cin>>s;
        graph[s[0]].push_back(s[1]);
        graph[s[1]].push_back(s[2]);
        indg[s[1]]++;
        indg[s[2]]++;
        track.insert(s[0]);
        track.insert(s[1]);
        track.insert(s[2]);
    }

    for(set<char>::iterator it=track.begin();it!=track.end();it++){
        flag=false;
        cycle(*it);
        if(flag==true){
            cout<<"SMTH WRONG\n";
            break;
        }
    }

    if(flag==false){
        vis.clear();
        for(set<char>::iterator it=track.begin();it!=track.end();it++){
            if(!vis[*it] && !indg[*it]) q.push(*it);
        }
        while(!q.empty()){
            char temp=q.top();
            q.pop();
            topsort(temp);
        }

        while(!st.empty()){
            char ans;
            ans=st.top();
            st.pop();
            cout<<ans;
        }

        cout<<"\n";
    }

}


//seg_tree(curious robin hood)
typedef long long ll;
typedef pair<int,int> pii;

const int MAX=1000006;
int tree[MAX];

void build(int *tree, int node, int s, int e){

    if(s==e) {scanf("%d",&tree[node]); return;}
    int mid=(s+e)/2.0;
    int left=2*node+1;
    int right=2*node+2;
    build(tree,left,s,mid);
    build(tree,right,mid+1,e);
    tree[node]=tree[left]+tree[right];

}

void update_zero(int *tree, int node, int s, int e, int ind){

    if(s>ind || e<ind) return;
    if(s==e) {printf("%d\n",tree[node]); tree[node]=0; return;}
    int mid=(s+e)/2.0;
    int left=2*node+1;
    int right=2*node+2;
    update_zero(tree,left,s,mid,ind);
    update_zero(tree,right,mid+1,e,ind);
    tree[node]=tree[left]+tree[right];

}

void update_val(int *tree, int node, int s, int e, int ind, int val){

    if(s>ind || e<ind) return;
    if(s==e) {tree[node]+=val; return;}
    int mid=(s+e)/2.0;
    int left=2*node+1;
    int right=2*node+2;
    update_val(tree,left,s,mid,ind,val);
    update_val(tree,right,mid+1,e,ind,val);
    tree[node]=tree[left]+tree[right];


}

int query(int *tree,int node, int s, int e, int i, int j){

    if(i>e || j<s) return 0;
    if(s>=i && e<=j) return tree[node];
    int mid=(s+e)/2.0;
    int left=2*node+1;
    int right=2*node+2;
    return (query(tree,left,s,mid,i,j)+query(tree,right,mid+1,e,i,j));

}
int main(){

//    ios::sync_with_stdio(false);
//    cin.tie(NULL);

//    freopen("alu.txt","r",stdin);
//    freopen("vorta.txt","w",stdout);
    int t,caseno=0;
    scanf("%d",&t);
    while(t--){
        int n,q;
        scanf("%d %d",&n,&q);
        build(tree,0,0,n-1);
        printf("Case %d:\n",++caseno);
        while(q--){
            int c;
            scanf("%d",&c);
            if(c==1){
                int ind;
                scanf("%d",&ind);
                update_zero(tree,0,0,n-1,ind);
            }
            else if(c==2){
                int ind,val;
                scanf("%d %d",&ind,&val);
                update_val(tree,0,0,n-1,ind,val);
            }
            else{
                int i,j;
                scanf("%d %d",&i,&j);
                printf("%d\n",query(tree,0,0,n-1,i,j));
            }
        }
    }


}


//seg_tree(horrible queries)
const int MAX=1000006;
struct info{

    ll sum,lazy;

} tree[MAX];

void build(int node, int s, int e){

    tree[node].lazy=0;
    if(s==e) {
        tree[node].sum=0;
        return;
    }
    int mid=(s+e)/2.0;
    int left=2*node+1;
    int right=2*node+2;
    build(left,s,mid);
    build(right,mid+1,e);
    tree[node].sum=tree[left].sum+tree[right].sum;
}

void updatelazy(int node, int s, int e, int i, int j, int val){

    if(tree[node].lazy){
        tree[node].sum+=((e-s+1)*tree[node].lazy);
        if(s!=e){
            tree[2*node+1].lazy+=tree[node].lazy;
            tree[2*node+2].lazy+=tree[node].lazy;
        }
        tree[node].lazy=0;
    }

    if(i>e || j<s) return;
    if(s>=i && e<=j){
        tree[node].sum+=((e-s+1)*val);
        if(s!=e){
            tree[2*node+1].lazy+=val;
            tree[2*node+2].lazy+=val;
        }
        return;
    }

    int mid=(s+e)/2.0;
    int left=2*node+1;
    int right=2*node+2;
    updatelazy(left,s,mid,i,j,val);
    updatelazy(right,mid+1,e,i,j,val);
    tree[node].sum=tree[left].sum+tree[right].sum;

}

ll query(int node, int s, int e, int i, int j){

    if(tree[node].lazy){
        tree[node].sum+=((e-s+1)*tree[node].lazy);
        if(s!=e){
            tree[2*node+1].lazy+=tree[node].lazy;
            tree[2*node+2].lazy+=tree[node].lazy;
        }
        tree[node].lazy=0;
    }
    if(i>e || j<s) return 0;
    if(s>=i && e<=j) return tree[node].sum;
    int mid=(s+e)/2.0;
    int left=2*node+1;
    int right=2*node+2;
    return (query(left,s,mid,i,j)+query(right,mid+1,e,i,j));

}
int main(){

    int t,caseno=0;
    scanf("%d",&t);
    while(t--){
        int n,q;
        scanf("%d %d",&n,&q);
        build(0,0,n-1);
        printf("Case %d:\n",++caseno);
        while(q--){
            int c,i,j,val;
            scanf("%d",&c);
            if(c==0){
                scanf("%d %d %d",&i,&j,&val);
                updatelazy(0,0,n-1,i,j,val);
            }
            else{
                scanf("%d %d",&i,&j);
                printf("%lli\n",query(0,0,n-1,i,j));
            }
        }

    }

}

//KMP
int failure[MAX];
void make_failure(string pattern){

    int i=0,j=-1;
    failure[0]=-1;
    int lens=pattern.size();
    while(i<lens){
        while(j>=0 && pattern[i]!=pattern[j]) j=failure[j];
        i++;
        j++;
        failure[i]=j;
    }

}

int kmp(string s, string pattern){

    int i=0,j=0,cnt=0,start=0;
    int lens=s.size();
    int lenp=pattern.size();
    while(i<lens){

        while(j>=0 && s[i]!=pattern[j]) j=failure[j];
        i++;
        j++;
        if(j==lenp){
            cnt++;
            j=failure[j];
        }

    }
    return cnt;

}


int main(){

    fastio;
    int n,k;
    cin>>n>>k;
    while(n--){
        string a,b;
        cin>>a>>b;
        if(k>a.size() || k>b.size()){
            cout<<"No\n";
            continue;
        }
        if(a.size()<b.size()){
            bool flag=false;
            for(int i=0;i+k<=a.size();i++){
                string temp=a.substr(i,k);
                make_failure(temp);
                if(kmp(b,temp)){
                    cout<<"Yes\n";
                    flag=true;
                    break;
                }
            }
            if(!flag) cout<<"No\n";
        }
        else{
            bool flag=false;
            for(int i=0;i+k<=b.size();i++){
                string temp=b.substr(i,k);
                make_failure(temp);
                if(kmp(a,temp)){
                    cout<<"Yes\n";
                    flag=true;
                    break;
                }
            }
            if(!flag) cout<<"No\n";
        }
    }

}

//Delete pashapashi equal elements from list (delete korar por dui pash theke abar pashapashi equal hoile oigulao delete) O(n)
list<int>::iterator porer,ager;
porer=ager=l.begin();
porer++;
while(porer!=l.end()){
    if(*porer==*ager){
        if(l.size()==2) cout<<"sob element equal chhilo"
        if(ager==l.begin()){
            porer++;
            l.erase(ager,porer);
            ager=porer;
            porer++;
        }
        else{
            porer++;
            l.erase(ager,porer);
            if(porer==l.end()) break;
            ager=porer;
            ager--;
        }
    }
    else{
        porer++;
        ager++;
    }
}


//Articulation point
const int MAX=10005;
const int MOD=1000000007;

vii graph[MAX];
vii points;
bool po[MAX];
bool vis[MAX];
int par[MAX];
int d[MAX],low[MAX];

int tim;
void ap(int s){

    vis[s]=true;
    int child=0;
    d[s]=low[s]=++tim;
    for(int i=0;i<graph[s].size();i++){
        int node=graph[s][i];
        if(!vis[node]){
            child++;
            par[node]=s;
            ap(node);
            low[s]=min(low[node],low[s]);
            if(par[s]==-1 && child>1) po[s]=true;
            if(par[s]!=-1 && low[node]>=d[s]) po[s]=true;
        }
        else if(par[node]!=s) low[s]=min(low[s],d[node]);

    }

}
int main(){

    fastio;
    int t,caseno=0;
    cin>>t;
    while(t--){
        tim=0;
        for(int i=0;i<MAX;i++){
            graph[i].clear();
            d[i]=low[i]=0;
            vis[i]=po[i]=false;
            par[i]=-1;
        }
        int n,m;
        cin>>n>>m;
        while(m--){
            int a,b;
            cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        for(int i=1;i<=n;i++){
            if(!vis[i]) ap(i);
        }
        int cnt=0;
        for(int i=1;i<=n;i++) if(po[i]) cnt++;

        cout<<"Case "<<++caseno<<": "<<cnt<<"\n";
    }

}

//query frequency update
int main()
{
    int n,q,x,y;
    cin>>n>>q;
    int a[n+2]={};
    while(q--)
    {
        cin>>x>>y;
        a[x]++;
        a[y+1]--;
    }

    for(int i=1;i<=n;i++)
        a[i]=a[i]+a[i-1];

    for(int i=1;i<=n;i++)
        cout<<a[i];
    return 0;
}


//LCA
#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;i<n;i++)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%I64d",&x)
#define ss(s)	scanf("%s",s)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define clr(x) memset(x, 0, sizeof(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pll;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pll>		vpll;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
const int mod = 1000000007;
const int N = 2e5;
vi g[N];
const int LG = 20;
//LCA begins
//1 based index
int a[N], lvl[N], P[N][LG];
void dfs(int u, int par){
    lvl[u] = 1+lvl[par];
    P[u][0] = par;
	for(int v:g[u]){
		if (v == par) continue;
		dfs(v, u);
	}
}

int lca(int u, int v){
    int i, lg;
    if (lvl[u] < lvl[v]) swap(u, v);

    for(lg = 0; (1<<lg) <= lvl[u]; lg++);
    lg--;

    for(i=lg; i>=0; i--){
        if (lvl[u] - (1<<i) >= lvl[v])
            u = P[u][i];
    }

    if (u == v)
    	return u;

    for(i=lg; i>=0; i--){
        if (P[u][i] != -1 and P[u][i] != P[v][i])
            u = P[u][i], v = P[v][i];
    }

    return P[u][0];
}

//Get the ancestor of node "u"
//which is "dis" distance above.
int getAncestor(int u, int dis){
    dis = lvl[u] - dis;
    int i, lg = 0;
    for(; (1<<lg) <= lvl[u]; lg++); lg--;

    for(i=lg; i>=0; i--){
        if (lvl[u] - (1<<i) >= dis)
            u = P[u][i];
    }

    return u;
}

//returns the distance between
//two nodes "u" and "v".
int dis(int u, int v){
    if (lvl[u] < lvl[v]) swap(u, v);
    int w = lca(u, v);
    return lvl[u] + lvl[v] - 2*lvl[w];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i, n, q, m, j;
	int u, v;
	cin >> n >> m;
	fo(i, n-1){
            cin>>u>>v;
            g[u].pb(v);
            g[v].pb(u);
	}

	fo(i, LG) fo(j, n+1) P[j][i] = -1;
	lvl[0] = -1;

	dfs(1, 0);

	for(i=1; i<LG; i++){
        Fo(j, 1, n+1)
            if (P[j][i-1] != -1)
                P[j][i] = P[P[j][i-1]][i-1];
	}

	return 0;
}

//lcs
int lcs(string a, string b){

    int n=a.size();
    int m=b.size();
    int dp[n+1][m+1];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0) dp[i][j]=0;
            else if(a[i-1]==b[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }

    return dp[n][m];

}

//count number of palindromic subsequence
ll dp[105][105];
ll cnt_palindrome(string s){

    int n=s.size();
    memset(dp,0,sizeof dp);
    for(int len=1;len<=n;len++){
        for(int i=0;i<n;i++){
            int j=i+len-1;
            if(j>=n) break;
            if(i==j) dp[i][j]=1;
            if(s[i]==s[j]) dp[i][j]=1+dp[i][j-1]+dp[i+1][j];
            else dp[i][j]=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1];
        }
    }

    return dp[0][n-1];

}

//longest palindromic subsequence
int dp[1005][1005];
int longest_palindrome(string s){

    int n=s.size();
    memset(dp,0,sizeof dp);

    for(int len=1;len<=n;len++){
        for(int i=0;i<n;i++){
            int j=i+len-1;
            if(j>=n) break;

            if(i==j) dp[i][j]=1;
            else if(s[i]==s[j]) dp[i][j]=2+dp[i+1][j-1];
            else dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
        }
    }

    return dp[0][n-1];

}

//LIS
int LongestIncreasingSubsequenceLength(std::vector<int>& v)
{
    if (v.size() == 0)
        return 0;

    std::vector<int> tail(v.size(), 0);
    int length = 1; // always points empty slot in tail

    tail[0] = v[0];
    for (size_t i = 1; i < v.size(); i++) {
        if (v[i] > tail[length - 1])
            tail[length++] = v[i];
        else {
            // TO check whether the element is not present before hand
            auto it = find(tail.begin(), tail.begin() + length, v[i]);
            if (it != tail.begin() + length) {
                continue;
            }
            // If not present change the tail element to v[i]
            it = upper_bound(tail.begin(), tail.begin() + length, v[i]);
            *it = v[i];
        }
    }

    return length;
}

//z algo
int z[MAX];
void calcz(string s){
    int n=s.size();
    int l,r;
    l=r=0;
    for(int i=1;i<n;i++){
        if(i>r){
            l=r=i;
            while(r<n && s[r]==s[r-l]) r++;
            z[i]=r-l;
            r--;
        }
        else{
            int k=i-l;
            if(z[k]<r-i+1) z[i]=z[k];
            else{
                l=i;
                while(r<n && s[r]==s[r-l]) r++;
                z[i]=r-l;
                r--;
            }
        }
    }
}

//compress array
void compress(int n){
    vii v;
    for(int i=0;i<n;i++) v.pb(arr[i]);
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i=0;i<n;i++){
        int zipped=lower_bound(v.begin(),v.end(),arr[i])-v.begin()+1;
        arr[i]=zipped;
        mx=max(mx,zipped);
    }
}

//bitmask
ll Set(ll n, int pos){return n|((ll)1<<pos);}
ll reset(ll n, int pos){return n&~((ll)1<<pos);}
bool check(ll n, int pos){return (bool)(n&((ll)1<<pos));}

//measure execution time
clock_t strt, ed;
/* Recording the starting clock tick.*/
strt = clock();
//code goes here
// Recording the end clock tick.
ed = clock();
// Calculating total time taken by the program.
double time_taken = double(ed - strt) / double(CLOCKS_PER_SEC);
cout << "Time taken by program is : " << fixed << time_taken << setprecision(5) << " sec\n";

//BIT
void update(int val, int pos){
    while(pos<=n){
        bit[pos]+=val;
        pos+=(pos & (-pos));
    }
}

int get(int pos){
    int ret=0;
    while(pos>0){
        ret+=bit[pos];
        pos-=(pos & (-pos));
    }
    return ret;
}

//tree distance query(with node value update)
int bit[60005];

void update(int pos, int val, int n){
    while(pos<=n){
        bit[pos]+=val;
        pos+=(pos & -pos);
    }
}

int get(int pos, int n){
    int ret=0;
    while(pos>0){
        ret+=bit[pos];
        pos-=(pos & -pos);
    }
    return ret;
}

vii g[30005];
int arr[30005];
pii pos[30005];
int lv[30005];
int p[30005][25];
bool vis[30005];
int ind;
int n;

void dfs(int node, int par, int lvl){
    vis[node]=true;
    pos[node].ff=ind++;
    lv[node]=lvl;
    p[node][0]=par;
    for(int i=0;i<g[node].size();i++){
        if(!vis[g[node][i]]) dfs(g[node][i],node,lvl+1);
    }
    pos[node].ss=ind++;
}

int lca(int u, int v){
    if(lv[v]<lv[u]) swap(u,v);
    int lg=0;
    for(;(1<<lg)<=lv[v];lg++);
    lg--;

    for(int i=lg;i>=0;i--){
        if(lv[v]-(1<<i) >= lv[u]) v=p[v][i];
    }

    if(u==v) return v;
    for(int i=lg;i>=0;i--){
        if(p[u][i]!=-1 && p[u][i]!=p[v][i]) u=p[u][i], v=p[v][i];
    }

    return p[u][0];
}

int main(){

//    fastio;
    int t,caseno=0;
    scanf("%d",&t);
    while(t--){
        printf("Case %d:\n",++caseno);
        scanf("%d",&n);
        for(int i=0;i<n;i++) g[i].clear(), vis[i]=false;
        for(int i=0;i<n;i++) scanf("%d",&arr[i]);
        for(int i=0;i<n-1;i++){
            int a,b;
            scanf("%d %d",&a,&b);
            g[a].pb(b);
            g[b].pb(a);
        }

        memset(p,-1,sizeof p);
        memset(bit,0,sizeof bit);
        ind=1;
        dfs(0,-1,0);
        ind--;
        for(int j=1;j<25;j++){
            for(int i=0;i<n;i++){
                if(p[i][j-1]!=-1) p[i][j]=p[p[i][j-1]][j-1];
            }
        }

        for(int i=0;i<n;i++){
            update(pos[i].ff,arr[i],ind);
            update(pos[i].ss,-arr[i],ind);
        }

        int q;
        scanf("%d",&q);
        while(q--){
            int i,a,b;
            scanf("%d %d %d",&i,&a,&b);
            if(!i){
                int par=lca(a,b);
                int ans=-1;
                if(par!=a && par!=b) ans=get(pos[a].ff,ind)+get(pos[b].ff,ind)-2*get(pos[par].ff,ind)+arr[par];
                else{
                    if(lv[a]>lv[b]) ans=get(pos[a].ff,ind)-get(pos[b].ff-1,ind);
                    else ans=get(pos[b].ff,ind)-get(pos[a].ff-1,ind);
                }

                printf("%d\n",ans);
            }
            else{
                update(pos[a].ff,-arr[a],ind);
                update(pos[a].ss,+arr[a],ind);
                update(pos[a].ff,b,ind);
                update(pos[a].ss,-b,ind);
                arr[a]=b;
            }
        }
    }
}

//sparse table(gcd)
for(int i=2;i<MAX;i++) lg[i]=lg[i/2]+1;
for(int i=0;i<n;i++){
    cin>>arr[i];
    dp[i][0]=arr[i];
}

for(int j=1;j<25;j++){
    for(int i=0;i+(1<<j)<=n;i++){
        dp[i][j]=__gcd(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
    }
}

//sparse table range sum query
long long sum = 0;
for (int j = K; j >= 0; j--) {
    if ((1 << j) <= R - L + 1) {
        sum += st[L][j];
        L += 1 << j;
    }
}

//group same color together in minimum adjacent swaps(m is number of colors in array...all colors have to be present from 1 to m)
int prv[21];
ll cost[21][21] ;
int m,n;

ll dp[1<<21];
bool ok[1<<21];

ll solve(ll mask){
    if(mask==(1<<m)-1) return 0ll;
    ll &ret=dp[mask];
    if(ok[mask]) return ret;
    ok[mask]=true;
    ret=inf;

    for(int i=0;i<m;i++){
        if(!(mask&(1<<i) )){
            ll c=0;
            for(int j=0;j<m;j++){
                if((mask&(1<<j) ) )
                    c+=cost[i][j];
            }
            ret=min(ret,c+solve((mask|(1<<i) ) ) ) ;
        }
    }
    return ret;
}

int main(){

    for(int i=0;i<n;i++){
        int val=arr[i];
        val--;
        prv[val]++;
        for(int j=0;j<m;j++){
            if(val==j) continue;
            cost[val][j] +=prv[j];
        }
    }
    ll ans=solve(0);

}

ll mulmod(ll a, ll b){
    ll ret=0;
    a=a%m;
    while(b>0){
        if(b%2==1) ret=(ret + a)%m;
        a=(a * 2)%m;
        b/=2;
    }
    return(ret%m);
}

long long bigmod ( long long a, long long p, long long m){
    long long res = 1%m;
    long long x = a%m;
    while(p){
        if(p&1){
            res = (res * x)%m;
        }
        x = (x * x)%m;
        p = p>>1;
    }
    return res;
}

//mo's algorithm
void remove(idx);  // TODO: remove value at idx from data structure
void add(idx);     // TODO: add value at idx from data structure
int get_answer();  // TODO: extract the current answer of the data structure

int block_size;

struct Query {
    int l, r, idx;
    bool operator<(Query other) const {
        return make_pair(l / block_size, r) <
               make_pair(other.l / block_size, other.r);
    }
};

vector<int> mo_s_algorithm(vector<Query> queries) {
    vector<int> answers(queries.size());
    sort(queries.begin(), queries.end());

    // TODO: initialize data structure

    int cur_l = 0;
    int cur_r = -1;
    // invariant: data structure will always reflect the range [cur_l, cur_r]
    for (Query q : queries) {
        while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(cur_r);
            cur_r--;
        }
        answers[q.idx] = get_answer();
    }
    return answers;
}

//improve mo's runtime
bool cmp(pair<int, int> p, pair<int, int> q) {
    if (p.first / BLOCK_SIZE != q.first / BLOCK_SIZE)
        return p < q;
    return (p.first / BLOCK_SIZE & 1) ? (p.second < q.second) : (p.second > q.second);
}

//fft
struct complx{
    long double real, img;

    inline complx(){
        real = img = 0.0;
    }

    inline complx(long double x){
        real = x, img = 0.0;
    }

    inline complx(long double x, long double y){
        real = x, img = y;
    }

    inline void operator += (complx &other){
        real += other.real, img += other.img;
    }

    inline void operator -= (complx &other){
        real -= other.real, img -= other.img;
    }

    inline complx operator + (complx &other){
        return complx(real + other.real, img + other.img);
    }

    inline complx operator - (complx &other){
        return complx(real - other.real, img - other.img);
    }

    inline complx operator * (complx& other){
        return complx((real * other.real) - (img * other.img), (real * other.img) + (img * other.real));
    }
};


void FFT(vector <complx> &ar, int n, int inv){
    int i, j, l, len, len2;
    const long double p = 4.0 * inv * acos(0.0);

    for (i = 1, j = 0; i < n; i++){
        for (l = n >> 1; j >= l; l >>= 1) j -= l;
        j += l;
        if (i < j) swap(ar[i], ar[j]);
    }

    for(len = 2; len <= n; len <<= 1) {
        long double ang = 2 * PI / len * inv;
        complx wlen(cos(ang), sin(ang));
        for(i = 0; i < n; i += len) {
            complx w(1);
            for(j = 0; j < len / 2; j++) {
                complx u = ar[i + j];
                complx v = ar[i + j + len / 2] * w;
                ar[i + j] = u + v;
                ar[i + j + len / 2] = u - v;
                w = w * wlen;
            }
        }
    }

    if (inv == -1){
        long double tmp = 1.0 / n;
        for (i = 0; i < n; i++) ar[i].real *= tmp;
    }
}


vector <complx> Mul(const vector <complx> &x, const vector <complx> &y) {
    int n = 1;
    while(n <= x.size() + y.size()) n = n * 2;
    vector <complx> A(n), B(n);
    REP(i, x.size()) A[i] = x[i];
    REP(i, y.size()) B[i] = y[i];
    FFT(A, n, 1);
    FFT(B, n, 1);
    REP(i, n) A[i] = A[i] * B[i];
    FFT(A, n, -1);
    return A;
}

void multiply(string a, string b){
    vector<complx>v1,v2;

    int sign = 0;
    if(a[0] == '-'){
        sign = 1 - sign;
        a.erase(a.begin());
    }
    if(b[0] == '-'){
        sign = 1 - sign;
        b.erase(b.begin());
    }
    for(int i = 0;i < a.size();i++){
        int d = a[i] - '0';
        v1.push_back(complx(d));
    }
    for(int i = 0;i < b.size();i++){
        int d = b[i] - '0';
        v2.push_back(complx(d));
    }

    REV(v1); REV(v2);
    vector<complx>v = Mul(v1,v2);

    int carry = 0;
    vector<int>answer;
    for(int i = 0;i < v.size();i++){
        int temp = round(v[i].real);
        temp += carry;
        answer.push_back(temp % 10);
        carry = temp/10;
    }
    while(answer.size() > 1 and answer.back() == 0)answer.pop_back();
    REV(answer);
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        string a,b;
        cin >> a >> b;
        vector<complx>v1,v2;

        int sign = 0;
        if(a[0] == '-'){
            sign = 1 - sign;
            a.erase(a.begin());
        }
        if(b[0] == '-'){
            sign = 1 - sign;
            b.erase(b.begin());
        }
        for(int i = 0;i < a.size();i++){
            int d = a[i] - '0';
            v1.push_back(complx(d));
        }
        for(int i = 0;i < b.size();i++){
            int d = b[i] - '0';
            v2.push_back(complx(d));
        }

        REV(v1); REV(v2);
        vector<complx>v = Mul(v1,v2);

        int carry = 0;
        vector<int>answer;
        for(int i = 0;i < v.size();i++){
            int temp = round(v[i].real);
            temp += carry;
            answer.push_back(temp % 10);
            carry = temp/10;
        }
        while(answer.size() > 1 and answer.back() == 0)answer.pop_back();
        REV(answer);

        for(int i : answer)cout << i;
        cout << "\n";

    }
}

//submask == all i such that mask&i == i || mask&i == mask (all i such that all 0 in mask are fixed and the 1's change)
//sos dp memory optimized
for(int i = 0; i<(1<<N); ++i)
	F[i] = A[i];
for(int i = 0;i < N; ++i) for(int mask = 0; mask < (1<<N); ++mask){
	if(mask & (1<<i))
		F[mask] += F[mask^(1<<i)];
}

//sos iterative
for(int mask = 0; mask < (1<<N); ++mask){
	dp[mask][-1] = A[mask];	//handle base case separately (leaf states)
	for(int i = 0;i < N; ++i){
		if(mask & (1<<i))
			dp[mask][i] = dp[mask][i-1] + dp[mask^(1<<i)][i-1];
		else
			dp[mask][i] = dp[mask][i-1];
	}
	F[mask] = dp[mask][N-1];
}

// iterate over all the masks
for (int mask = 0; mask < (1<<n); mask++){
	F[mask] = A[0];
    // iterate over all the subsets of the mask
    for(int i = mask; i > 0; i = (i-1) & mask){
    	F[mask] += A[i];
    }
}

//trie(find number of a[i] in trie such that present a[i] xor p < l)
int trie[30*100000 + 5][2];
int mark[30*100000 + 5];

int node=1;
void add(int n){
    int now=1;
    for(int i=27;i>=0;i--){
        int d=(bool)(n & (1<<i));
        if(!trie[now][d]) trie[now][d] = ++node;
        now=trie[now][d];
        mark[now]++;
    }
}

void del(int n){
    int now=1;
    deque<int>v;
    for(int i=27;i>=0;i--){
        int d=(bool)(n & (1<<i));
        if(trie[now][d]){
            v.push_front(now);
            now=trie[now][d];
            mark[now]--;
        }
    }
    v.push_front(now);
    for(int i=1;i<v.size();i++){
        if(!mark[v[i-1]]){
            if(trie[v[i]][0]==v[i-1]) trie[v[i]][0]=0;
            if(trie[v[i]][1]==v[i-1]) trie[v[i]][1]=0;
        }
    }
}

int solve(int now, int pos, int p, int l){
    if(pos<0) return 0;
    int p_b=(bool)(p & (1<<pos));
    int l_b=(bool)(l & (1<<pos));
    int ret=0;
    if(!p_b && l_b){
        ret+=mark[trie[now][0]];
        if(trie[now][1]) ret+=solve(trie[now][1],pos-1,p,l);
    }
    if(p_b && l_b){
        ret+=mark[trie[now][1]];
        if(trie[now][0]) ret+=solve(trie[now][0],pos-1,p,l);
    }
    if(!p_b && !l_b) if(trie[now][0]) ret+=solve(trie[now][0],pos-1,p,l);
    if(p_b && !l_b) if(trie[now][1]) ret+=solve(trie[now][1],pos-1,p,l);
    return ret;
}

//range hash and inverse hash
struct simplehash{
    int len;
    long long base, mod;
    vector <int> P, H, R;

    simplehash(){}
    simplehash(string str, long long b, long long m){
        base = b, mod = m, len = str.size();
        P.resize(len + 1, 1), H.resize(len + 1, 0), R.resize(len + 2, 0);

        for (int i = 1; i <= len; i++) P[i] = (P[i - 1] * base) % mod;
        for (int i = 1; i <= len; i++) H[i] = (H[i - 1] * base + str[i - 1] + 1007) % mod;
        for (int i = len; i >= 1; i--) R[i] = (R[i + 1] * base + str[i - 1] + 1007) % mod;
    }


    inline int range_hash(int l, int r){
        int hashval = H[r + 1] - ((long long)P[r - l + 1] * H[l] % mod);
        return (hashval < 0 ? hashval + mod : hashval);
    }

    inline int reverse_hash(int l, int r){;
        int hashval = R[l + 1] - ((long long)P[r - l + 1] * R[r + 2] % mod);
        return (hashval < 0 ? hashval + mod : hashval);
    }
};

struct stringhash{
    simplehash sh1, sh2;
    stringhash(){}
    stringhash(string str){
        sh1 = simplehash(str, 1949313259, 2091573227);
        sh2 = simplehash(str, 1997293877, 2117566807);
    }

    inline long long range_hash(int l, int r){ /// 0 index
        return ((long long)sh1.range_hash(l, r) << 32) ^ sh2.range_hash(l, r);
    }

    inline long long reverse_hash(int l, int r){
        return ((long long)sh1.reverse_hash(l, r) << 32) ^ sh2.reverse_hash(l, r);
    }
};

//not printed

//maximum weight edge between two nodes of a tree
int p[MAX][MAXLG+5];
ll weight[MAX][MAXLG+5];
int lvl[MAX];
void dfs(int u, int pr, ll w, int l){
    lvl[u]=l;
    p[u][0]=pr;
    weight[u][0]=w;
    for(int i=0;i<tree[u].size();i++){
        if(tree[u][i].ff!=pr) dfs(tree[u][i].ff,u,tree[u][i].ss,l+1);
    }
}

void preprocess(){
    dfs(1,-1,0,0);
    for(int j=1;j<=log2(n)+1;j++){
        for(int i=1;i<=n;i++){
            if(p[i][j-1]!=-1){
                p[i][j]=p[p[i][j-1]][j-1];
                weight[i][j]=max(weight[i][j-1],weight[p[i][j-1]][j-1]);
            }
        }
    }
}

ll lca(int u, int v){
    if(lvl[v]<lvl[u]) swap(u,v);
    int lg=0;
    for(;(1<<lg)<=lvl[v];lg++);
    lg--;

    ll ret=0;
    for(int i=lg;i>=0;i--){
        if(lvl[v]-(1<<i) >= lvl[u]){
            ret=max(ret, weight[v][i]);
            v=p[v][i];
        }
    }

    if(u==v) return ret;
    for(int i=lg;i>=0;i--){
        if(p[u][i]!=-1 && p[u][i]!=p[v][i]){
            ret=max(ret, weight[v][i]);
            ret=max(ret, weight[u][i]);
            u=p[u][i];
            v=p[v][i];
        }
    }

    ret=max(ret, weight[u][0]);
    ret=max(ret, weight[v][0]);
    return ret;
}

//ordered set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>ordered_set;

//suffix array
struct suffix_array{
    string s;
    int n,alphabet;
    vector<int> p, c, cnt, lcp;

    suffix_array(){}
    suffix_array(string str){
        s = str + '$';
        n = s.size();
        alphabet = 256;
        sort_cycle_shift();
        create_lcp();
    }

    inline void sort_cycle_shift(){
        p.resize(n);
        c.resize(n);
        cnt.assign(alphabet,0);
        for (int i = 0; i < n; i++) cnt[s[i]]++;
        for (int i = 1; i < alphabet; i++) cnt[i] += cnt[i-1];
        for (int i = 0; i < n; i++) p[--cnt[s[i]]] = i;

        c[p[0]] = 0;
        int classes = 1;
        for (int i = 1; i < n; i++) {
            if (s[p[i]] != s[p[i-1]]) classes++;
            c[p[i]] = classes - 1;
        }

        vector<int> pn(n), cn(n);
        for (int h = 0; (1 << h) < n; ++h) {
            for (int i = 0; i < n; i++) {
                pn[i] = p[i] - (1 << h);
                if (pn[i] < 0) pn[i] += n;
            }
            fill(cnt.begin(), cnt.begin() + classes, 0);
            for (int i = 0; i < n; i++) cnt[c[pn[i]]]++;
            for (int i = 1; i < classes; i++) cnt[i] += cnt[i-1];
            for (int i = n-1; i >= 0; i--) p[--cnt[c[pn[i]]]] = pn[i];

            cn[p[0]] = 0;
            classes = 1;
            for (int i = 1; i < n; i++) {
                pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
                pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
                if (cur != prev) ++classes;
                cn[p[i]] = classes - 1;
            }
            c.swap(cn);
        }
        p.erase(p.begin());
    }

    inline void create_lcp(){
        s.pop_back();
        n--;
        vector<int> rank(n, 0);
        for (int i = 0; i < n; i++) rank[p[i]] = i;
        int k = 0;
        lcp.assign(n, 0);
        for (int i = 0; i < n; i++) {
            if (rank[i] == n - 1) {
                k = 0;
                continue;
            }
            int j = p[rank[i] + 1];
            while (i + k < n && j + k < n && s[i+k] == s[j+k]) k++;
            lcp[rank[i]] = k;
            if (k) k--;
        }
    }
};


//suffix array with 2D c
vector<vector<int> >c;
vector<int>sort_cyclic_shifts(string const& s){
    int n = s.size();
    const int alphabet = 256;
    vector<int> p(n), cnt(alphabet, 0);

    c.clear();
    c.emplace_back();
    c[0].resize(n);

    for (int i = 0; i < n; i++)         cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)  cnt[i] += cnt[i-1];
    for (int i = 0; i < n; i++)         p[--cnt[s[i]]] = i;

    c[0][p[0]] = 0;
    int classes = 1;

    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i-1]])   classes++;
        c[0][p[i]] = classes - 1;
    }

    vector<int> pn(n), cn(n);
    cnt.resize(n);

    for (int h = 0; (1<<h) < n; h++) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1<<h);
            if (pn[i] < 0)  pn[i] += n;
        }
        fill(cnt.begin(), cnt.end(), 0);

        /// radix sort
        for (int i = 0; i < n; i++)         cnt[c[h][pn[i]]]++;
        for (int i = 1; i < classes; i++)   cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--)      p[--cnt[c[h][pn[i]]]] = pn[i];

        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pii cur = {c[h][p[i]], c[h][(p[i] + (1<<h))%n]};
            pii prev = {c[h][p[i-1]], c[h][(p[i-1] + (1<<h))%n]};
            if (cur != prev)    ++classes;
            cn[p[i]] = classes - 1;
        }
        c.push_back(cn);
    }
    return p;
}

vector<int> suffix_array_construction(string s){
    s += "!";
    vector<int> sorted_shifts = sort_cyclic_shifts(s);
    sorted_shifts.erase(sorted_shifts.begin());
    return sorted_shifts;
}

/// compare two suffixes starting at i and j with length 2^k
int compare(int i, int j, int n, int k){
    pii a = {c[k][i], c[k][(i+1-(1<<k))%n]};
    pii b = {c[k][j], c[k][(j+1-(1<<k))%n]};
    return a == b ? 0 : a < b ? -1 : 1;
}

int lcp(int i, int j){
    int log_n = c.size()-1;
    int ans = 0;

    for (int k = log_n; k >= 0; k--) {
        if (c[k][i] == c[k][j]) {
            ans += 1 << k;
            i += 1 << k;
            j += 1 << k;
        }
    }
    return ans;
}

vector<int> lcp_construction(string const& s, vector<int> const& p){
    int n = s.size();
    vector<int> rank(n, 0);

    for (int i = 0; i < n; i++)
        rank[p[i]] = i;

    int k = 0;
    vector<int> lcp(n, 0);

    for (int i = 0; i < n; i++) {
        if (rank[i] == n - 1) {
            k = 0;
            continue;
        }

        int j = p[rank[i] + 1];
        while (i + k < n && j + k < n && s[i+k] == s[j+k])  k++;
        lcp[rank[i]] = k;
        if (k)  k--;
    }
    return lcp;
}

//kth lexicographically smallest substring (considering duplicates)
int arr[MAX], lg[MAX], mn[MAX][25];
vector<int>p, lcp;
string s;
int k;
void build(){
    for(int i=2;i<MAX;i++) lg[i]=lg[i/2]+1;
    for(int i=0;i<s.size();i++) mn[i][0]=lcp[i];
    for(int j=1;j<25;j++){
        for(int i=0;i+(1<<j)<=s.size();i++){
            mn[i][j] = min(mn[i][j-1], mn[i+(1<<(j-1))][j-1]);
        }
    }
}

int get(int l, int r){
    int len=r-l+1;
    int j=lg[len];
    return min(mn[l][j], mn[r - (1<<j) + 1][j]);
}

///find the rightmost position where get(l,r) > val
int khoj(int l, int r, int val){
    int lo=l+1, hi=r, ret=-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(get(l,mid-1) > val){
            ret=mid;
            lo=mid+1;
        }
        else hi=mid-1;
    }
    return ret;
}

int done[MAX];
int main(){

    fastio;
    cin>>s>>k;
    p = suffix_array_construction(s);
    lcp = lcp_construction(s,p);
    build();

    int n=s.size();
    int milaisi=0;
    for(int i=0;i<n;i++){
        milaisi+=done[i];
        int len = n-p[i];
        int cur = milaisi;
        /// cur = i ? lcp[i-1] : 0; this can replace all the milaisi and done parts
        while(cur < len){
            int r = khoj(i,n-1,cur);
            int koyta, milabo;
            if(r == -1){
                milabo = len - cur;
                koyta = 1;
            }
            else{
                milabo = get(i,r-1) - cur;
                koyta = r-i+1;
            }
            if(koyta * milabo < k) k-=(koyta * milabo);
            else{
                int d = k/koyta;
                int m = k%koyta;
                if(!m){
                    cout<<s.substr(p[i], cur + d)<<"\n";
                    return 0;
                }
                else{
                    cout<<s.substr(p[i], cur + d + 1)<<"\n";
                    return 0;
                }
            }

            if(r == -1) break;
            done[r+1]-=milabo;
            cur=get(i,r-1);
            milaisi+=milabo;
        }
    }

    cout<<"No such line.\n";

}

//suffix automata
struct state {
    int len, link;
    map<char, int> next;
};
state st[2*MAX];
int sz, last;

void sa_init() {
    st[0].len = 0;
    st[0].link = -1;
    sz++;
    last = 0;
}

void sa_extend(char c) {
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    int p = last;
    while (p != -1 && !st[p].next.count(c)) {
        st[p].next[c] = cur;
        p = st[p].link;
    }
    if (p == -1) {
        st[cur].link = 0;
    } else {
        int q = st[p].next[c];
        if (st[p].len + 1 == st[q].len) {
            st[cur].link = q;
        } else {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            st[clone].next = st[q].next;
            st[clone].link = st[q].link;
            while (p != -1 && st[p].next[c] == q) {
                st[p].next[c] = clone;
                p = st[p].link;
            }
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}

string lcs (string S, string T) {
    sa_init();
    for (int i = 0; i < S.size(); i++)
        sa_extend(S[i]);

    int v = 0, l = 0, best = 0, bestpos = 0;
    for (int i = 0; i < T.size(); i++) {
        while (v && !st[v].next.count(T[i])) {
            v = st[v].link ;
            l = st[v].len ;
        }
        if (st[v].next.count(T[i])) {
            v = st [v].next[T[i]];
            l++;
        }
        if (l > best) {
            best = l;
            bestpos = i;
        }
    }
    return t.substr(bestpos - best + 1, best);
}

//lcs of n strings
struct state {
    int len, link;
    int next[26];
};
state st[2*MAX];
int mx[2*MAX], mn[2*MAX];
int sz, last;

void sa_init() {
    st[0].len = 0;
    st[0].link = -1;
    sz++;
    last = 0;
}

void sa_extend(char c) {
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    mn[cur] = st[cur].len;
    int p = last;
    while (p != -1 && !st[p].next[c - 'a']) {
        st[p].next[c - 'a'] = cur;
        p = st[p].link;
    }
    if (p == -1) {
        st[cur].link = 0;
    } else {
        int q = st[p].next[c - 'a'];
        if (st[p].len + 1 == st[q].len) {
            st[cur].link = q;
        } else {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            mn[clone] = st[clone].len;
//            st[clone].next = st[q].next;
            for(int i=0; i<26; i++) st[clone].next[i] = st[q].next[i];
            st[clone].link = st[q].link;
            while (p != -1 && st[p].next[c - 'a'] == q) {
                st[p].next[c - 'a'] = clone;
                p = st[p].link;
            }
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}

void add_str(string s) {
    for(int i=0; i<sz; i++) mx[i] = 0;
    int v = 0, l = 0;
    for (int i = 0; i < s.size(); i++) {
        while (v && !st[v].next[s[i] - 'a']) {
            v = st[v].link ;
            l = st[v].len ;
        }
        if (st[v].next[s[i] - 'a']) {
            v = st [v].next[s[i] - 'a'];
            l++;
        }
        mx[v] = max(mx[v], l);
    }
    for(int i=sz-1; i>0; i--) mx[st[i].link] = max(mx[st[i].link], mx[i]);
    for(int i=0; i<sz; i++) mn[i] = min(mn[i], mx[i]);
}

int lcs(){
    int ret = 0;
    for(int i=0; i<sz; i++) ret = max(ret, mn[i]);
    return ret;
}


string s[15];
int main(){

    fastio;
    int n=0;
    while(cin>>s[n]) n++;
    sa_init();
    for(int i=0;i<s[0].size();i++) sa_extend(s[0][i]);
    for(int i=1;i<n;i++) add_str(s[i]);
    cout<<lcs()<<"\n";
}

//centroid decomposition (res[i] contains the sum of numbers of distinct colors in all paths from i)
set<int>g[MAX];
int col[MAX];
int child[MAX];
int used[18][MAX];
ll ans[MAX], res[MAX];
int sz = 0;
int n;
bool vis[MAX];
int uniq = 0;

void dfs(int u, int p){
    sz++;
    child[u] = 1;
    for(auto v: g[u]){
        if(v != p){
            dfs(v,u);
            child[u] += child[v];
        }
    }
}

int get_centroid(int u, int p){
    for(auto v: g[u]){
        if(v != p && child[v] > sz/2) return get_centroid(v, u);
    }
    return u;
}

void add(int u, int p, int depth, int centroid){
    bool check = false;
    child[u] = 1;
    if(!vis[col[u]]){
        uniq++;
        check = true;
        vis[col[u]] = true;
    }
    ans[centroid] += uniq;
    for(auto v: g[u]){
        if(v != p){
            add(v, u, depth, centroid);
            child[u] += child[v];
        }
    }
    if(check){
        uniq--;
        used[depth][col[u]] += child[u];
        vis[col[u]] = false;
    }
}

void del(int u, int p, int depth, int centroid){
    bool check = false;
    if(!vis[col[u]]){
        uniq++;
        used[depth][col[u]] -= child[u];
        vis[col[u]] = true;
        check = true;
    }
    ans[centroid] -= uniq;
    for(auto v: g[u]){
        if(v != p){
            del(v, u, depth, centroid);
        }
    }
    child[u] = 0;
    if(check){
        uniq--;
        vis[col[u]] = false;
    }
}

void solve(int u, int p, int depth, int centroid){
    ans[u] += (ans[p] + child[centroid] - used[depth][col[u]]);
    res[u] += ans[u];
    int temp = used[depth][col[u]];
    used[depth][col[u]] = child[centroid];
    for(auto v: g[u]){
        if(v != p) solve(v, u, depth, centroid);
    }
    ans[u] = 0;
    used[depth][col[u]] = temp;
}

void reset_col(int u, int p, int depth){
    used[depth][col[u]] = 0;
    for(auto v: g[u]){
        if(v != p) reset_col(v, u, depth);
    }
}

void decompose(int u, int depth){
    sz = 0;
    uniq = 0;
    dfs(u,-1);
    int centroid = get_centroid(u,-1);
    reset_col(centroid,-1,depth);
    add(centroid, -1, depth, centroid); ///get ans for centroid and get the number of paths where each color is used
    res[centroid] += ans[centroid];
    uniq++;
    vis[col[centroid]] = true;
    for(auto v: g[centroid]){
        child[centroid] -= child[v];

        ///remove all contribution of the subtree of v
        del(v, centroid, depth, centroid);
        used[depth][col[centroid]] = child[centroid];

        solve(v, centroid, depth, centroid);

        ///add back the contribution of the subtree of v
        add(v, centroid, depth, centroid);
        child[centroid] += child[v];
    }
    uniq--;
    vis[col[centroid]] = false;
    for(auto it = g[centroid].begin(); it != g[centroid].end(); it++){
        g[*it].erase(centroid);
        decompose(*it, depth + 1);
    }
}

int main(){

    fastio;
    cin>>n;
    for(int i=1; i<=n; i++) cin>>col[i];
    for(int i=0; i<n-1; i++){
        int u,v;
        cin>>u>>v;
        g[u].insert(v);
        g[v].insert(u);
    }
    decompose(1,0);
    for(int i=1; i<=n; i++) cout<<res[i]<<"\n";

}

//check colinear
struct point{
    int x,y;
    point(){}
    point(int x, int y) : x(x), y(y){}
};

inline bool colinear(const point &a, const point &b, const point &c){
    return ((c.y - b.y)*(b.x - a.x) == (c.x - b.x)*(b.y - a.y));
}

//rooted tree hash to check isomorphism
mp["01"] = 1;
ind = 1;
int dfs(int u, int p){
    int cnt = 0;
    vector<int>vs;
    for(auto v: g1[u]){
        if(v != p){
            int got = dfs(v,u);
            vs.pb(got);
            cnt++;
        }
    }
    if(!cnt) return 1;

    sort(vs.begin(), vs.end());
    string s = "0";
    for(auto i: vs) s += to_string(i);
    vs.clear();
    s.pb('1');
    if(mp.find(s) == mp.end()) mp[s] = ++ind;
    int ret = mp[s];
    return ret;
}

//palindromic tree (number of palindromic substrings with len > 2 whose prefix of len ceil(len/2) is also a palindrome
struct state {
    int len, link;
    map<char, int> next;
};
state st[MAX];
int id, last;
string s;
ll ans[MAX];
void init(){
    for(int i=0; i<=id; i++){
        st[i].len = 0;
        st[i].link = 0;
        st[i].next.clear();
        ans[i] = 0;
    }
    st[1].len = -1;
    st[1].link = 1;
    st[2].len = 0;
    st[2].link = 1;
    id = 2;
    last = 2;
}

void extend(int pos){
    while(s[pos - st[last].len - 1] != s[pos]) last = st[last].link;
    int newlink = st[last].link;
    char c = s[pos];
    while(s[pos - st[newlink].len - 1] != s[pos]) newlink = st[newlink].link;
    if(!st[last].next.count(c)){
        st[last].next[c] = ++id;
        st[id].len = st[last].len + 2;
        st[id].link = (st[id].len == 1 ? 2 : st[newlink].next[c]);
        ans[id] += ans[st[id].link];
        if(st[id].len > 2){
            int l = st[id].len/2 + (st[id].len % 2 ? 1 : 0);
            if(h.range_hash(pos - st[id].len + 1, pos - st[id].len + l) == h.reverse_hash(pos - st[id].len + 1, pos - st[id].len + l)) ans[id]++;
        }
    }
    last = st[last].next[c];
}

int main(){

    fastio;
    int t,cs = 0;
    cin>>t;
    while(t--){
        int n;
        cin>>n>>s;
        s = "#" + s;
        h = stringhash(s);
        init();
        ll sum = 0;

        for(int i=1; i<=n; i++){
            extend(i);
            sum += ans[last];
        }
        cout<<"Case "<<++cs<<": "<<sum<<"\n";
    }
}

//largest area of rectangle in a histogram
int arr[30005];
int main(){

    fastio;
    int t,caseno=0;
    cin>>t;
    while(t--){
        int n,ans=-1;
        cin>>n;
        for(int i=0;i<n;i++) cin>>arr[i];
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                int top=arr[st.top()];
                st.pop();
                if(st.empty()) ans=max(ans,top*i);
                else ans=max(ans,top*(i-1-st.top()));
            }
            st.push(i);
        }
        while(!st.empty()){
            int top=arr[st.top()];
            st.pop();
            if(st.empty()) ans=max(ans,top*n);
            else ans=max(ans,top*(n-1-st.top()));
        }
        cout<<"Case "<<++caseno<<": "<<ans<<"\n";
    }
}

//manacher
vector<int> d1(n); ///odd palindromes
for (int i = 0, l = 0, r = -1; i < n; i++) {
    int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
    while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
        k++;
    }
    d1[i] = k--;
    if (i + k > r) {
        l = i - k;
        r = i + k;
    }
}

vector<int> d2(n); ///even palindromes
for (int i = 0, l = 0, r = -1; i < n; i++) {
    int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
    while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
        k++;
    }
    d2[i] = k--;
    if (i + k > r) {
        l = i - k - 1;
        r = i + k ;
    }
}

//hld
vector<int> parent, depth, heavy, head, pos;
int cur_pos;

int dfs(int v, vector<vector<int>> const& adj) {
    int size = 1;
    int max_c_size = 0;
    for (int c : adj[v]) {
        if (c != parent[v]) {
            parent[c] = v, depth[c] = depth[v] + 1;
            int c_size = dfs(c, adj);
            size += c_size;
            if (c_size > max_c_size)
                max_c_size = c_size, heavy[v] = c;
        }
    }
    return size;
}

int decompose(int v, int h, vector<vector<int>> const& adj) {
    head[v] = h, pos[v] = cur_pos++;
    if (heavy[v] != -1)
        decompose(heavy[v], h, adj);
    for (int c : adj[v]) {
        if (c != parent[v] && c != heavy[v])
            decompose(c, c, adj);
    }
}

void init(vector<vector<int>> const& adj) {
    int n = adj.size();
    parent = vector<int>(n);
    depth = vector<int>(n);
    heavy = vector<int>(n, -1);
    head = vector<int>(n);
    pos = vector<int>(n);
    cur_pos = 0;

    dfs(0, adj);
    decompose(0, 0, adj);
}

int query(int a, int b) {
    int res = 0;
    for (; head[a] != head[b]; b = parent[head[b]]) {
        if (depth[head[a]] > depth[head[b]])
            swap(a, b);
        int cur_heavy_path_max = segment_tree_query(pos[head[b]], pos[b]);
        res = max(res, cur_heavy_path_max);
    }
    if (depth[a] > depth[b])
        swap(a, b);
    int last_heavy_path_max = segment_tree_query(pos[a], pos[b]);
    res = max(res, last_heavy_path_max);
    return res;
}

//dominator tree
struct dominator{
    int n, d_t;
    vector<vector<int>> g, rg, tree, bucket;
    vector<int> sdom, dom, par, dsu, label, val, rev;
    dominator(){}
    dominator(int n) : n(n), d_t(0), g(n+1), rg(n+1),
                       tree(n+1), bucket(n+1), sdom(n+1),
                       dom(n+1), par(n+1), dsu(n+1),
                       label(n+1), val(n+1),rev(n+1)
    { for(int i=1; i<=n; i++) sdom[i] = dom[i] = dsu[i] = label[i] = i; }

    void add_edge(int u, int v) { g[u].pb(v); }

    int dfs(int u){
        d_t++;
        val[u] = d_t, rev[d_t] = u;
        label[d_t] = sdom[d_t] = dom[d_t] = d_t;
        for(int v: g[u]){
            if(!val[v]){
                dfs(v);
                par[val[v]] = val[u];
            }
            rg[val[v]].pb(val[u]);
        }
    }

    int findpar(int u, int x = 0){
        if(dsu[u] == u) return x ? -1 : u;
        int v = findpar(dsu[u], x+1);
        if(v < 0) return u;

        if(sdom[label[dsu[u]]] < sdom[label[u]]) label[u] = label[dsu[u]];
        dsu[u] = v;
        return x ? v : label[u];
    }

    void join(int u, int v) { dsu[v] = u; }

    vector<vector<int>> build(int s){
        dfs(s);
        for(int i=n; i>=1; i--){
            for(int j=0; j<rg[i].size(); j++){
                sdom[i] = min(sdom[i], sdom[ findpar(rg[i][j]) ]);
            }

            if(i > 1) bucket[sdom[i]].pb(i);
            for(int w: bucket[i]){
                int v = findpar(w);
                if(sdom[v] == sdom[w]) dom[w] = sdom[w];
                else dom[w] = v;
            }
            if(i > 1) join(par[i], i);
        }

        for(int i=2; i<=n; i++){
            if(dom[i] != sdom[i]) dom[i] = dom[dom[i]];
            tree[rev[i]].pb(rev[dom[i]]);
            tree[rev[dom[i]]].pb(rev[i]);
        }
        return tree;
    }
};

//flow (dinic)
int src, sink;
int dis[MAX], q[MAX], work[MAX];
int n,m,nodes;

struct edge{
    int v, rev, cap, flow;
    edge(){}
    edge(int v, int rev, int cap) : v(v), rev(rev), cap(cap), flow(0){}
};
vector<edge>g[MAX];

void add_edge(int u, int v, int cap){
    edge _u = edge(v, g[v].size(), cap);
    edge _v = edge(u, g[u].size(), 0);
    g[u].pb(_u);
    g[v].pb(_v);
}

bool dinic_bfs(int s){
    fill(dis, dis + nodes, -1);
    dis[s] = 0;
    int id = 0;
    q[id++] = s;

    for(int i=0; i<id; i++){
        int u = q[i];
        for(int j=0; j<g[u].size(); j++){
            edge &e = g[u][j];
            if(dis[e.v] == -1 && e.flow < e.cap){
                dis[e.v] = dis[u] + 1;
                q[id++] = e.v;
            }
        }
    }
    return dis[sink] >= 0;
}

int dinic_dfs(int u, int f){
    if(u == sink) return f;
    for(int &i = work[u]; i<g[u].size(); i++){
        edge &e = g[u][i];
        if(e.cap <= e.flow) continue;
        if(dis[e.v] == dis[u] + 1){
            int flow = dinic_dfs(e.v, min(f, e.cap - e.flow));
            if(flow){
                e.flow += flow;
                g[e.v][e.rev].flow -= flow;
                return flow;
            }
        }
    }
    return 0;
}

int max_flow(int _src, int _sink){
    src = _src;
    sink = _sink;
    int ret = 0;
    while(dinic_bfs(src)){
        fill(work, work + nodes, 0);
        while(int flow = dinic_dfs(src, INT_MAX)){
            ret += flow;
        }
    }
    return ret;
}
