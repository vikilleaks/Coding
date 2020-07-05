#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
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
#define MAXN 1000005
#define mod ((ll)(1e9 + 7))
using namespace std;

ll check(ll maxx, vector<ll> &cnt)
{
	ll flag=0,res;
	for(ll i=maxx;i>=1;i--)
    {
    	ll c=0;
    	for(ll j=i;j<=maxx;j+=i)
    	{
    		if(cnt[j]>=2)
    		{
    			flag=1;
    			res=j;
    			break;
    		}
    		if(cnt[j]==1) c++;
    		if(c==2)
    		{
    			flag=1;
    			res=i;
    			break;
    		}
    	}
    	if(flag==1) break;
    }
    return res;
}

void solve()
{
	ll n,x,maxx=ll_MIN;
    cin>>n;
    vector<ll> cnt(MAXN,0);
    for(ll i=0;i<n;i++)
    {
    	cin>>x;
    	cnt[x]++;
    	maxx=max(maxx,x);
    }
    ll res=check(maxx, cnt);
    cout<<res<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}