#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define MAXN 705
using namespace std;
using namespace __gnu_pbds;  

int n,m,u,v,vis[MAXN],low[MAXN],disc[MAXN],tim;
vector<int> adj[MAXN];
vector<pair<int,int> > res;

void bridges(int s, int p)
{
	vis[s]=1;
	low[s]=disc[s]=tim++;
	for(int i=0;i<adj[s].size();i++)
	{
		int u=adj[s][i];
		if(!vis[u])
		{
			bridges(u,s);
			low[s]=min(low[s],low[u]);
			if(low[u]>disc[s])
			{
				int a=min(u,s), b=max(u,s);
				res.pb(mp(a,b));
			}
		}
		else if(u!=p) low[s]=min(low[s],disc[u]);
	}
}

void solve()
{
		cin>>n>>m;
		for(int i=0;i<m;i++)
		{
			cin>>u>>v;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		bridges(1,0);
		cout<<res.size()<<endl;
		sort(res.begin(), res.end());
		for(int i=0;i<res.size();i++) cout<<res[i].ff<<" "<<res[i].ss<<endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	solve();
}
