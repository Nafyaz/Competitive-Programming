#include<bits/stdc++.h>
#define lli long long int
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;

lli a[100005], segment_tree[4*100005];

void init(lli node, lli Begin, lli End)
{
    if(Begin==End)
    {
        segment_tree[node]=a[Begin];
        return;
    }
    lli left=node*2;
    lli right=(node*2)+1;
    lli mid=(Begin+End)/2;
    init(left,Begin,mid);
    init(right,mid+1,End);
    segment_tree[node]=segment_tree[left]*segment_tree[right];
}

lli Query(lli node, lli Begin, lli End, lli i, lli j)
{
    if(Begin>j || End<i)
        return 1;
    if(Begin>=i && End<=j)
        return segment_tree[node];
    lli left=node*2;
    lli right=(node*2)+1;
    lli mid=(Begin+End)/2;
    lli q1=Query(left, Begin, mid, i, j);
    lli q2=Query(right, mid+1, End, i, j);
    return q1*q2;
}

void Update(lli node, lli Begin, lli End, lli i, lli val)
{
    if(Begin>i || End<i)
        return;
    if(Begin==i && End==i)
    {
        segment_tree[node]=val;
        return;
    }
    lli left=node*2;
    lli right=(node*2)+1;
    lli mid=(Begin+End)/2;
    Update(left, Begin, mid, i, val);
    Update(right, mid+1, End, i, val);
    segment_tree[node]=segment_tree[left]*segment_tree[right];
}

int main()
{
    freopen("out.txt", "w", stdout);
    fastio;
    lli n, k;
    while(cin>>n>>k)
    {
        lli c=1;
        string res1="";
        for(lli i=1; i<=n; i++)
            cin>>a[i];
        init(1,1,n);
        while(k--)
        {
            char ch;
            lli i, v;
            cin>>ch>>i>>v;
            if(ch=='C')
            {
                Update(1,1,n,i,v);
            }
            else if(ch=='P')
            {
                lli result=Query(1,1,n,i,v);
                if(result>0)
                    res1+='+';
                else if(result<0)
                    res1+='-';
                else if(result==0)
                    res1+='0';
            }
        }

        cout<<res1<<endl;
    }
}
