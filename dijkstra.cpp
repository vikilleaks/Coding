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

ll n,m,u,v,w,vis[MAXN],d[MAXN],p[MAXN];
vector<pair<ll,ll> > adj[MAXN];
multiset<pair<ll,ll> > s;

// algo invariant if graph contains multiple edges or loops
void dijkstra()
{
	// pairs in a set are sorted by the first value of the pair.
	s.insert(mp(0,1));
	while(!s.empty())
	{
		pair<ll,ll> t=*s.begin();
		s.erase(s.begin());
		ll v=t.ss, w=t.ff;
		if(vis[v]) continue;
		vis[v]=1;
		for(ll i=0;i<adj[v].size();i++)
		{
			ll x=adj[v][i].ff, y=adj[v][i].ss;
			if(d[v]+y < d[x])
			{
				d[x]=d[v]+y;
				p[x]=v;
				s.insert(mp(d[x],x));
			}
		}
	}
}

void solve()
{
	cin>>n>>m;
	for(ll i=0;i<m;i++)
	{
		cin>>u>>v>>w;
		adj[u].pb(mp(v,w));
		adj[v].pb(mp(u,w)); //comment if directed graph
	}
	// vertex 1 is source so d[1]=0
	d[1]=0;
	for(ll i=2;i<=n;i++) d[i]=LONG_LONG_MAX;
	dijkstra();
	if(d[n]==LONG_LONG_MAX) cout<<-1<<endl;
	else
	{
		stack<ll> res;
		res.push(n);
		ll q=n;
		while(q!=1)
		{
			res.push(p[q]);
			q=p[q];
		}
		while(!res.empty())
		{
			q=res.top();
			res.pop();
			cout<<q<<" ";
		}
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
