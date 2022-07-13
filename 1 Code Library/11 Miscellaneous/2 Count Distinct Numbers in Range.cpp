
// C++ code to find number of distinct numbers
// in a subarray
#include<bits/stdc++.h>
using namespace std;
 
const int MAX = 1000001;
 
// structure to store queries
struct Query
{
    int l, r, idx;
};
 
// cmp function to sort queries according to r
bool cmp(Query x, Query y)
{
    return x.r < y.r;
}
 
// updating the bit array
void update(int idx, int val, int bit[], int n)
{
    for (; idx <= n; idx += idx&-idx)
        bit[idx] += val;
}
 
// querying the bit array
int query(int idx, int bit[], int n)
{
    int sum = 0;
    for (; idx>0; idx-=idx&-idx)
        sum += bit[idx];
    return sum;
}
 
void answeringQueries(int arr[], int n, Query queries[], int q)
{
    // initialising bit array
    int bit[n+1];
    memset(bit, 0, sizeof(bit));
 
    // holds the rightmost index of any number
    // as numbers of a[i] are less than or equal to 10^6
    int last_visit[MAX];
    memset(last_visit, -1, sizeof(last_visit));
 
    // answer for each query
    int ans[q];
    int query_counter = 0;
    for (int i=0; i<n; i++)
    {
        // If last visit is not -1 update -1 at the
        // idx equal to last_visit[arr[i]]
        if (last_visit[arr[i]] !=-1)
            update (last_visit[arr[i]] + 1, -1, bit, n);
 
        // Setting last_visit[arr[i]] as i and updating
        // the bit array accordingly
        last_visit[arr[i]] = i;
        update(i + 1, 1, bit, n);
 
        // If i is equal to r of any query  store answer
        // for that query in ans[]
        while (query_counter < q && queries[query_counter].r == i)
        {
            ans[queries[query_counter].idx] =
                     query(queries[query_counter].r + 1, bit, n)-
                     query(queries[query_counter].l, bit, n);
            query_counter++;
        }
    }
 
    // print answer for each query
    for (int i=0; i<q; i++)
        cout << ans[i] << endl;
}
 
// driver code
int main()
{
    int a[] = {1, 1, 2, 1, 3};
    int n = sizeof(a)/sizeof(a[0]);
    Query queries[3];
    queries[0].l = 0;
    queries[0].r = 4;
    queries[0].idx = 0;
    queries[1].l = 1;
    queries[1].r = 3;
    queries[1].idx = 1;
    queries[2].l = 2;
    queries[2].r = 4;
    queries[2].idx = 2;
    int q = sizeof(queries)/sizeof(queries[0]);
    sort(queries, queries+q, cmp);
    answeringQueries(a, n, queries, q);
    return 0;
}