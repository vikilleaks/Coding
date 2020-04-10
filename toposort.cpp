#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define pb push_back
#define mp make_pair
#define ff first
#define pi pair<ll,ll>
#define ss second
#define ll long long
#define MAXN 100005
using namespace std;
using namespace __gnu_pbds;  

int n,m,u,v,vis[MAXN],flag;
vector<int> adj[MAXN];
vector<int> res;

void dfs(int s, int p)
{
	vis[s]=1;
	for(int i=0;i<adj[s].size();i++)
	{
		int p=adj[s][i];
		if(!vis[p]) dfs(p,s);
		else if(vis[p]==1)
		{
			// node has not exited so back edge
			flag=1;
			break;
		}
	}
	// node has exited
	vis[s]=2;
	res.pb(s);
}

void solve()
{
	cin>>n>>m;
	while(m--)
	{
		cin>>u>>v;
		adj[u].pb(v);
	}
	for(int i=1;i<=n;i++) sort(adj[i].begin(),adj[i].end(),greater<int>());
	for(int i=n;i>=1;i--)
	{
		if(!vis[i]) dfs(i,-1);
	}
	if(flag==1) cout<<"-1"<<endl;
	else
	{
		for(int i=res.size()-1;i>=0;i--) cout<<res[i]<<" ";
		cout<<endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	solve();
}
