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

ll m=1e9+7, fact[MAXN];
ll n;

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
// t[i] = ((-1)^i)/i!
// !n = n!* summation(t[i];0<=i<=n)

void solve()
{
	fact[0]=1;
	for(ll i=1;i<=MAXN;i++) fact[i]=(fact[i-1]*i)%m;
	cin>>n;
    ll res=fact[n];
    ll temp=0;
    for(ll i=0;i<=n;i++)
    {
        if(i%2==0) temp=(temp+modexp(fact[i],m-2))%m;
        else temp=(temp-modexp(fact[i],m-2)+m)%m;
    }
    res=(res*temp)%m;
	cout<<res<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
    solve();
}
