#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define ll_MAX LONG_LONG_MAX
#define ll_MIN LONG_LONG_MIN
#define pi pair<int,int>
#define endl "\n"
#define MAXN 200005
using namespace std;

int n,m,k,u,v,vis[MAXN];
vector<int> adj[MAXN];
vector<int> e;

void dfs(int s)
{
	vis[s]=1;
	e.pb(s);
	for(auto t:adj[s])
	{
		if(!vis[t])
		{ 
			dfs(t);
			e.pb(s);
		}
	}
}

void solve()
{
	cin>>n>>m>>k;
	while(m--)
	{
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
    solve();
}
