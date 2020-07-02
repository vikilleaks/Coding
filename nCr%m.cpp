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
using namespace std;

ll n,a,b,m=1e9+7;
ll fact[MAXN];

ll modexp(ll a, ll b)
{
    a %= m;
    ll res = 1;
    while(b>0) 
    {
        if(b%2==1) res = (res * a) % m;
        a = (a * a) % m;
        b/=2;
    }
    return res%m;
}

void solve()
{
	fact[0]=1;
	for(int i=1;i<=MAXN;i++) fact[i]=(fact[i-1]*i)%m;
	cin>>n;
    while(n--)
    {
    	cin>>a>>b;
    	ll res=(( (fact[a] * modexp(fact[b],m-2)) % m) * modexp(fact[a-b],m-2))%m;
    	cout<<res<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
    solve();
}