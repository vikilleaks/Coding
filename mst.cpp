#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define MAXN 100005
using namespace std;
using namespace __gnu_pbds;  

ll n,m,u,v,w,cost;
vector<pair<pair<ll,ll>,ll> > adj;
ll p[MAXN],r[MAXN],sz[MAXN];
vector<pair<ll,ll> > res;

bool trick(const pair<pair<ll,ll>,ll> &a, const pair<pair<ll,ll>,ll> &b)
{
	return a.ss<b.ss;
}

void make_set(ll v)
{
	p[v]=v;
	r[v]=0;
	sz[v]=0;
}

ll find_set(ll v)
{
	if(p[v]==v) return v;
	return p[v]=find_set(p[v]);
}

void union_sets(ll v1, ll v2)
{
	ll a=find_set(v1), b=find_set(v2);
	if(a!=b)
	{
		if(r[a]<r[b]) swap(a,b);
		p[b]=a;
		sz[a]+=sz[b];
		if(r[a]==r[b]) r[a]++;
	}
}

void solve()
{
	cin>>n>>m;
	for(ll i=0;i<m;i++)
	{
		cin>>u>>v>>w;
		adj.pb(mp(mp(u,v),w));
	}
	sort(adj.begin(),adj.end(),trick);
	for(ll i=1;i<=n;i++) make_set(i);
	for(ll i=0;i<m;i++)
	{
		if(find_set(adj[i].ff.ff) != find_set(adj[i].ff.ss))
		{
			cost+=adj[i].ss;
			res.pb(mp(adj[i].ff.ff,adj[i].ff.ss));
			union_sets(adj[i].ff.ff,adj[i].ff.ss);
		}
	}
	cout<<cost<<endl;
	// for(ll i=0;i<res.size();i++) cout<<res[i].ff<<" "<<res[i].ss<<endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}
