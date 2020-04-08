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
#define MAXN 3005
using namespace std;
using namespace __gnu_pbds;  

ll n,m,k,u,v,w,par[MAXN][MAXN];
vector<ll> adj[MAXN];
map<pair<pi,ll>,ll > mm;
pi res={-1,-1};
vector<ll> v1;

void dijkstra()
{
	queue<pi> q;
	q.push(mp(1,1));
	while(!q.empty())
	{
		pi x=q.front();
		q.pop();
		if(x.ss==n)
		{
			res=x;break;
		}
		for(ll i=0;i<adj[x.ss].size();i++)
		{
			ll p=adj[x.ss][i];
			if(par[x.ss][p] || mm[{x,p}]) continue;
			par[x.ss][p]=x.ff;
			q.push(mp(x.ss,p));
		}
	}
	if(res.ff==-1)
	{
		cout<<-1<<endl;
		return;
	}
	while(res.ss!=1)
	{
		v1.pb(res.ss);
		res={par[res.ff][res.ss],res.ff};
	}
	v1.pb(1);
	cout<<v1.size()-1<<endl;
	for(ll i=v1.size()-1;i>=0;i--) cout<<v1[i]<<" ";
	cout<<endl;
}

void solve()
{
	cin>>n>>m>>k;
	for(ll i=0;i<m;i++)
	{
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for(ll i=0;i<k;i++)
	{
		cin>>u>>v>>w;
		mm[{{u,v},w}]++;
	}
	dijkstra();
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	solve();
}
