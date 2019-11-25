#include<bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t, n, m, i, j, u, v;
	scanf("%d", &t);
	while(t--)
	{
	    scanf("%d %d", &n, &m);
	    vector <int> adj[n];

	    for(i = 0; i < m; i++)
	    {
	        scanf("%d %d", &u, &v);
	        adj[u].push_back(v);
	        adj[v].push_back(u);
	    }

	    for(i = 0; i < n; i++)
	    {
	        printf("%d", i);
	        for(j = 0; j < adj[i].size(); j++)
	            printf("-> %d", adj[i][j]);
	       printf("\n");
	    }
	}
	return 0;
}
