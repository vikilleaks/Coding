#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define pi pair<int,int>
#define endl "\n"
#define MAXN 100005
using namespace std;

int n,m,u,v,w;
vector<pair<pi,int> > e;
vector<int> d(MAXN,INT_MAX);
vector<int> p(MAXN,-1);

// This algorithm can also be applied to graphs containing negative weight edges . 
// However, if the graph contains a negative cycle, then, clearly, the shortest path to some vertices may not exist. 
// We can find the negative cycle using Bellman Ford.
// n−1  phases of the algorithm are sufficient to correctly calculate the lengths of all shortest paths in the graph.
// Each phase scans through all edges of the graph, and the algorithm tries to produce relaxation along each edge (a,b) having weight c.
// T=O(n*m)
void bf(int u)
{
	d[u]=0;
	while(1)
	{
		// We will stop after the desired number of phases, not necessarily n-1.
		int flag=0;
		for(int i=0;i<m;i++)
		{
			// This verification is needed if negative weight edges present, else incorrect distance of type INT_MAX-1 etc 
			// would appear from vertices to which paths haven't been found. 
			if(d[e[i].ff.ff] < INT_MAX)
			{
				if(d[e[i].ff.ss]>d[e[i].ff.ff]+e[i].ss)
				{
					d[e[i].ff.ss]=d[e[i].ff.ff]+e[i].ss;
					p[e[i].ff.ss]=e[i].ff.ff;
					flag=1;
				}
			}
		}
		if(flag==0) break;
	}
	if(d[n]==INT_MAX) cout<<-1<<endl; //No path exists
	else
	{
		cout<<d[n]<<endl;
		vector<int> v;
		for(int i=n;i!=-1;i=p[i]) v.pb(i);
		reverse(v.begin(),v.end());
		for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
		cout<<endl;
	}
}

void solve()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
    	cin>>u>>v>>w;
    	e.pb(mp(mp(u,v),w));
    }
    bf(1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
    solve();
}
