#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define MAXN 200005
using namespace std;
using namespace __gnu_pbds;  

ll n,m,k,x,y,p[100005],vis[1005][1005],ans;
char s[1005][1005];
ll r[]={1,-1,0,0};
ll c[]={0,0,1,-1};

bool check(ll x, ll y)
{
	if(x==0 || y==0 || x==n+1 || y==m+1) return 0;
	else return 1;
}

void dfs(ll x, ll y, ll idx)
{
	if(s[x][y]=='*')
	{
		ans++;return;
	}
	vis[x][y]=idx;
	for(ll i=0;i<4;i++)
	{
		if(check(x+r[i],y+c[i]) && !vis[x+r[i]][y+c[i]]) dfs(x+r[i],y+c[i],idx);
	}
}

void solve()
{
	cin>>n>>m>>k;
	for(ll i=1;i<=n;i++) 
	{
		for(ll j=1;j<=m;j++) cin>>s[i][j];
	}
	for(ll i=1;i<=k;i++)
	{
		cin>>x>>y;
		ans=0;
		if(!vis[x][y]) dfs(x,y,i);
		else ans=p[vis[x][y]];
		p[i]=ans;
		cout<<ans<<endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	solve();
}
