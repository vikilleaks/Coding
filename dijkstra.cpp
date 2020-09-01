#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define ll_MAX LONG_LONG_MAX
#define ll_MIN LONG_LONG_MIN
#define pi pair<ll, ll>
#define endl "\n"
#define MAXN 100005
using namespace std;

ll n, m, a, b, c, vis[MAXN], d[MAXN];
vector<pi> adj[MAXN];

// T=O(ElogV)
// algo invariant if graph contains multiple edges or loops
// Doesn't work for negative weight edges. Use Bellman-Ford in that case.
void dijkstra(ll s)
{
    // pairs in a set are sorted by the first value of the pair.The Dijkstra's algorithm runs for n iterations. 
    // At each iteration a vertex v is chosen as unmarked vertex which has the least value d[v]:
    multiset<pi> mm;
    mm.insert(mp(0, s));
    while (!mm.empty())
    {
        pi p = *mm.begin();
        mm.erase(mm.begin());
        ll u = p.ss;
	// After any vertex v becomes marked, the current distance to it d[v] is the shortest, and will no longer change.
        if (vis[u] == 1)
            continue;
        vis[u] = 1;
        for (pi t : adj[u])
        {
            ll v = t.ff, w = t.ss;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                mm.insert(mp(d[v], v));
            }
        }
    }
}

void solve()
{
    cin >> n >> m;
    while (m--)
    {
        cin >> a >> b >> c;
        adj[a].pb(mp(b, c));
    }
    for (ll i = 1; i <= n; i++)
        d[i] = ll_MAX;
    d[1] = 0;
    dijkstra(1);
    for (ll i = 1; i <= n; i++)
        cout << d[i] << " ";
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}
