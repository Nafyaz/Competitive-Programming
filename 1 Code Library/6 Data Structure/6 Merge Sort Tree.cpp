vector<ll>Tree[4*maxN];
ll arr[maxN];

vector<ll> merge(vector<ll> v1, vector<ll> v2)
{
    ll i = 0, j = 0;
    vector<ll> ret;

    while(i < v1.size() || j < v2.size())
    {
        if(i == v1.size())
        {
            ret.push_back(v2[j]);
            j++;
        }
        else if(j == v2.size())
        {
            ret.push_back(v1[i]);
            i++;
        }
        else
        {
            if(v1[i] < v2[j])
            {
                ret.push_back(v1[i]);
                i++;
            }
            else
            {
                ret.push_back(v2[j]);
                j++;
            }
        }
    }

    return ret;
}

void Build(ll node, ll bg, ll ed)
{
    if(bg == ed)
    {
        Tree[node].push_back(arr[bg]);
        return;
    }

    ll leftNode = 2*node, rightNode = 2*node + 1;
    ll mid = (bg+ed)/2;

    Build(leftNode, bg, mid); 
    Build(rightNode, mid+1, ed);

    Tree[node] = merge(Tree[leftNode], Tree[rightNode]);
}
 
ll query(ll node, ll bg, ll ed, ll l, ll r, ll k)
{
    if(ed < l || bg > r)    
        return 0;
    
    if(l <= bg && ed <= r)    
        return upper_bound(Tree[node].begin(), Tree[node].end(), k) - Tree[node].begin();    

    ll leftNode = 2*node, rightNode = 2*node + 1;
    ll mid = (bg + ed)/2;

    return query(leftNode, bg, mid, l, r, k) + query(rightNode, mid+1, ed, l, r, k);
}
