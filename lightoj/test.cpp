#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
#define ff first
#define ss second

int main()
{
   priority_queue<pi, vector<pi>, greater<pi>> pq;
   pq.push({1, 2});
   pq.push({5, 2});
   pq.push({3, 8});
   pq.push({2, 1});

   while(!pq.empty())
   {
       cout << pq.top().ff << " " << pq.top().ss << endl;
       pq.pop();
   }
}
