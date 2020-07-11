#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define ll_MAX LONG_LONG_MAX
#define ll_MIN LONG_LONG_MIN
#define pi pair<ll,ll>
#define endl "\n"
#define MAXN 200005
using namespace std;

ll n,q,x,a,b,c;
vector<ll> v;
vector<ll> t(4*MAXN,0);

void build(ll node, ll s, ll e)
{
	if(s==e) t[node]=v[s];
	else
	{
		ll m=s+(e-s)/2;
		build(2*node,s,m);
		build(2*node+1,m+1,e);
		t[node]=min(t[2*node],t[2*node+1]);
	}
}

void update(ll node, ll s, ll e, ll idx, ll val)
{
	if(s==e)
	{
		t[node]=val;
		v[s]=val;
	}
	else
	{
		ll m=s+(e-s)/2;
		if(s<=idx && idx<=m) update(2*node,s,m,idx,val);
		else update(2*node+1,m+1,e,idx,val);
		t[node]=min(t[2*node],t[2*node+1]);
	}
}

ll query(ll node, ll s, ll e, ll l, ll r)
{
	if(s>r || e<l) return ll_MAX;
	if(l<=s && e<=r) return t[node];
	ll m=s+(e-s)/2;
	ll p1=query(2*node,s,m,l,r);
	ll p2=query(2*node+1,m+1,e,l,r);
	return min(p1,p2);
}

void solve()
{
    cin>>n>>q;
    for(ll i=0;i<n;i++)
    {
    	cin>>x;v.pb(x);
    }
    build(1,0,n-1);
    while(q--)
    {
    	cin>>c>>a>>b;
    	if(c==1) update(1,0,n-1,a-1,b);
    	else cout<<query(1,0,n-1,a-1,b-1)<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}