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

ll n,x,pr[MAXN],pr2[MAXN];
vector<int> v;

void sieve(int n)
{
	// pr[i] checks if i is prime
	pr[1]=1;
	// pr2[i] checks if i is square of prime
	for(int i=1;i<=n;i++) pr2[i]=1;
	for(int i=2;i*i<=n;i++)
	{
		if(pr[i]==0)
		{
			v.pb(i);
			pr2[i*i]=0;
			for(int j=i*i;j<=n;j+=i) pr[j]=1;
		}
	}
}

void solve()
{
	sieve(MAXN);
	cin>>n;
	while(n--)
	{
		cin>>x;
		int ans=1;
		for(int i=0;i<v.size();i++)
		{
			// count number of divisors for prime factors <= x^(1/3)
			if(v[i]*v[i]*v[i]>x) break;
			int cnt=1;
			while(x%v[i]==0)
			{
				x/=v[i];
				cnt++;
			}
			ans*=cnt;
		}
		// Now x can either be 1 or have atmost 2 prime factors. This is because the primes we find here will be > x^(1/3) so if they are >= 3, they will amount to >= x which is a contradiction. 
		// prime
		if(pr[x]==0) ans*=2;
		// square of a prime
		else if(pr2[x]==0) ans*=3;
		// product of 2 distinct primes
		else if(x!=1) ans*=4;
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