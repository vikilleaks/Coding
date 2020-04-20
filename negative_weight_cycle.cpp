#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define pi pair<int,int>
#define endl "\n"
#define MAXN 100005
using namespace std;

int n,m,u,v,w;
vector<pair<pi,int> > e;
vector<int> d(MAXN,INT_MAX);
vector<int> p(MAXN,-1);

void bf(int u)
{
	d[u]=0;
	//last vertex for which there was relaxation in nth phase i.e it is either in negative cycle of reachable from it.
	int x;
	// Bellman ford stops in n-1 phases, so if there is relaxation in nth phase, then negative cycle is present.
	for(int j=0;j<n;j++)
	{
		x=-1;
		for(int i=0;i<m;i++)
		{
			// this verification needed if negative weight edges present, else incorrect distance of type INT_MAX-1 etc would appear from vertices to which paths haven't been found. 
			if(d[e[i].ff.ff] < INT_MAX)
			{
				if(d[e[i].ff.ss]>d[e[i].ff.ff]+e[i].ss)
				{
					// to prevent overflow
					d[e[i].ff.ss]=max(INT_MIN,d[e[i].ff.ff]+e[i].ss);
					p[e[i].ff.ss]=e[i].ff.ff;
					x=e[i].ff.ss;
					cout<<e[i].ff.ff<<" "<<x<<" "<<d[x]<<endl;
				}
			}
		}
	}
	if(x==-1) cout<<-1<<endl; //no negative cycle from u
	else
	{
		// To get the vertices that are guaranteed to lie in a negative cycle, starting from the vertex x, pass through to the predecessors n times. Hence we will get the vertex y, namely the vertex in the cycle earliest reachable from source. We have to go from this vertex, through the predecessors, until we get back to the same vertex y (and it will happen, because relaxation in a negative weight cycle occur in a circular manner).
		int y=x;
		for(int i=0;i<n;i++) y=p[y];
		vector<int> v;
		for(int i=y;;i=p[i])
		{
			v.pb(i);
			if(i==y && v.size()>1) break;
		}
		reverse(v.begin(),v.end());
		for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
		cout<<endl;
	}
}

void solve()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
    	cin>>u>>v>>w;
    	e.pb(mp(mp(u,v),w));
    }
    bf(1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
    solve();
}
