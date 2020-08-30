#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define ll_MAX LONG_LONG_MAX
#define ll_MIN LONG_LONG_MIN
#define pi pair<int, int>
#define endl "\n"
#define MAXN 100005
using namespace std;

int n, m, a, b, vis[MAXN], pr[MAXN], st, e;
vector<int> adj[MAXN];

bool dfs(int s)
{
    vis[s] = 1;
    for (int i = 0; i < adj[s].size(); i++)
    {
        if (!vis[adj[s][i]])
        {
            pr[adj[s][i]] = s;
            if (dfs(adj[s][i]))
                return true;
        }
        else if (vis[adj[s][i]] && adj[s][i] != pr[s])
        {
            st = adj[s][i];
            e = s;
            return true;
        }
    }
    return false;
}

void solve()
{
    cin >> n >> m;
    while (m--)
    {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    bool temp = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            temp = dfs(i);
            if (temp == 1)
                break;
        }
    }
    if (temp == 0)
        cout << "IMPOSSIBLE" << endl;
    else
    {
        vector<int> v;
        v.pb(st);
        v.pb(e);
        int temp = pr[e];
        while (temp != st)
        {
            v.pb(temp);
            temp = pr[temp];
        }
        v.pb(st);
        reverse(v.begin(), v.end());
        cout << v.size() << endl;
        for (int i = 0; i < v.size(); i++)
            cout << v[i] << " ";
        cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}
